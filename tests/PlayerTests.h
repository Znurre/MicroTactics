#include <QString>
#include <QtTest>

#include "fakeit.hpp"

#include "Player.h"
#include "IPlayerHandler.h"
#include "ICollisionHandler.h"

using namespace fakeit;

class PlayerTests : public QObject
{
	Q_OBJECT

	private:
		Player createSut()
		{
			return Player(m_collisionHandlerMock.get(), m_playerHandlerMock.get());
		}

	private slots:
		void shouldBeAbleToRotate()
		{
			Player sut = createSut();

			QCOMPARE(sut.rotation(), 0);

			sut.rotate(1);

			QCOMPARE(sut.rotation(), 3);

			sut.rotate(1);

			QCOMPARE(sut.rotation(), 2);

			sut.rotate(1);

			QCOMPARE(sut.rotation(), 1);

			sut.rotate(1);

			QCOMPARE(sut.rotation(), 0);

			sut.rotate(1);

			QCOMPARE(sut.rotation(), 3);

			sut.rotate(-1);

			QCOMPARE(sut.rotation(), 0);

			sut.rotate(-1);

			QCOMPARE(sut.rotation(), 1);
		}

		void shouldBeAbleToAdvance()
		{
			Player sut = createSut();

			Fake(Method(m_collisionHandlerMock, isCollidable));

			QCOMPARE(sut.x(), 0);
			QCOMPARE(sut.y(), 0);

			sut.advance();

			QCOMPARE(sut.x(), 0);
			QCOMPARE(sut.y(), -1);

			sut.advance();

			QCOMPARE(sut.x(), 0);
			QCOMPARE(sut.y(), -2);

			sut.rotate(-1);
			sut.advance();

			QCOMPARE(sut.x(), 1);
			QCOMPARE(sut.y(), -2);

			sut.advance();

			QCOMPARE(sut.x(), 2);
			QCOMPARE(sut.y(), -2);

			sut.rotate(-1);
			sut.advance();

			QCOMPARE(sut.x(), 2);
			QCOMPARE(sut.y(), -1);

			sut.advance();

			QCOMPARE(sut.x(), 2);
			QCOMPARE(sut.y(), 0);

			sut.rotate(-1);
			sut.advance();

			QCOMPARE(sut.x(), 1);
			QCOMPARE(sut.y(), 0);

			sut.advance();

			QCOMPARE(sut.x(), 0);
			QCOMPARE(sut.y(), 0);
		}

		void shouldBeAbleToRetreat()
		{
			Player sut = createSut();

			Fake(Method(m_collisionHandlerMock, isCollidable));

			QCOMPARE(sut.x(), 0);
			QCOMPARE(sut.y(), 0);

			sut.retreat();

			QCOMPARE(sut.x(), 0);
			QCOMPARE(sut.y(), 1);

			sut.retreat();

			QCOMPARE(sut.x(), 0);
			QCOMPARE(sut.y(), 2);

			sut.rotate(-1);
			sut.retreat();

			QCOMPARE(sut.x(), -1);
			QCOMPARE(sut.y(), 2);

			sut.retreat();

			QCOMPARE(sut.x(), -2);
			QCOMPARE(sut.y(), 2);

			sut.rotate(-1);

			QCOMPARE(sut.rotation(), 2);

			sut.retreat();

			QCOMPARE(sut.x(), -2);
			QCOMPARE(sut.y(), 1);

			sut.retreat();

			QCOMPARE(sut.x(), -2);
			QCOMPARE(sut.y(), 0);

			sut.rotate(-1);
			sut.retreat();

			QCOMPARE(sut.x(), -1);
			QCOMPARE(sut.y(), 0);

			sut.retreat();

			QCOMPARE(sut.x(), 0);
			QCOMPARE(sut.y(), 0);
		}

		void shouldBeAbleToShoot()
		{
			Player sut = createSut();

			sut.advance();
			sut.rotate(1);
			sut.advance();
			sut.rotate(-1);

			Mock<IPlayer> playerSouth;
			Mock<IPlayer> playerEast;
			Mock<IPlayer> playerNorth;
			Mock<IPlayer> playerWest;

			Fake(Method(playerSouth, damage));
			Fake(Method(playerEast, damage));
			Fake(Method(playerNorth, damage));
			Fake(Method(playerWest, damage));

			When(Method(m_playerHandlerMock, playerInDirection)(-1, -1, 0)).AlwaysReturn(&playerSouth.get());
			When(Method(m_playerHandlerMock, playerInDirection)(-1, -1, 1)).AlwaysReturn(&playerEast.get());
			When(Method(m_playerHandlerMock, playerInDirection)(-1, -1, 2)).AlwaysReturn(&playerNorth.get());
			When(Method(m_playerHandlerMock, playerInDirection)(-1, -1, 3)).AlwaysReturn(&playerWest.get());

			sut.shoot();

			Verify(Method(playerSouth, damage)).Exactly(Once);
			Verify(Method(playerEast, damage)).Never();
			Verify(Method(playerNorth, damage)).Never();
			Verify(Method(playerWest, damage)).Never();

			sut.rotate(1);
			sut.shoot();

			Verify(Method(playerSouth, damage)).Exactly(Once);
			Verify(Method(playerEast, damage)).Exactly(Once);
			Verify(Method(playerNorth, damage)).Never();
			Verify(Method(playerWest, damage)).Never();

			sut.rotate(1);
			sut.shoot();

			Verify(Method(playerSouth, damage)).Exactly(Once);
			Verify(Method(playerEast, damage)).Exactly(Once);
			Verify(Method(playerNorth, damage)).Exactly(Once);
			Verify(Method(playerWest, damage)).Never();

			sut.rotate(1);
			sut.shoot();

			Verify(Method(playerSouth, damage)).Exactly(Once);
			Verify(Method(playerEast, damage)).Exactly(Once);
			Verify(Method(playerNorth, damage)).Exactly(Once);
			Verify(Method(playerWest, damage)).Exactly(Once);
		}

		void shouldShouldDoNothingIfNullPlayer()
		{
			Player sut = createSut();

			When(Method(m_playerHandlerMock, playerInDirection)).Return(nullptr);

			sut.shoot();
		}

	private:
		Mock<IPlayerHandler> m_playerHandlerMock;
		Mock<ICollisionHandler> m_collisionHandlerMock;
};
