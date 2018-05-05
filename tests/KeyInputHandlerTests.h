#ifndef KEYINPUTHANDLERTESTS_H
#define KEYINPUTHANDLERTESTS_H

#include <QObject>
#include <QTest>
#include <QDebug>

#include "IPlayerTurnHandler.h"
#include "KeyInputHandler.h"
#include "Player.h"

#include "fakeit.hpp"

using namespace fakeit;

class KeyInputHandlerTests : public QObject
{
	Q_OBJECT

	private slots:
		void init()
		{
			When(Method(m_playerTurnHandlerMock, current)).Return(m_playerMock.get());
			Fake(Method(m_playerTurnHandlerMock, next));

			Fake(Method(m_playerMock, advance));
			Fake(Method(m_playerMock, retreat));
			Fake(Method(m_playerMock, rotate));
			Fake(Method(m_playerMock, shoot));
			Fake(Method(m_playerMock, melee));
		}

		void shouldBeAbleToAdvance()
		{
			KeyInputHandler keyInputHandler(m_playerTurnHandlerMock.get());

			keyInputHandler.onKeyPress(Qt::Key_W);

			Verify(Method(m_playerMock, advance) + Method(m_playerTurnHandlerMock, next));
		}

		void shouldBeAbleToRetreat()
		{
			KeyInputHandler keyInputHandler(m_playerTurnHandlerMock.get());

			keyInputHandler.onKeyPress(Qt::Key_S);

			Verify(Method(m_playerMock, retreat) + Method(m_playerTurnHandlerMock, next));
		}

		void shouldBeAbleToRotateRight()
		{
			KeyInputHandler keyInputHandler(m_playerTurnHandlerMock.get());

			keyInputHandler.onKeyPress(Qt::Key_D);

			Verify(Method(m_playerMock, rotate).Using(1) + Method(m_playerTurnHandlerMock, next));
		}

		void shouldBeAbleToRotateLeft()
		{
			KeyInputHandler keyInputHandler(m_playerTurnHandlerMock.get());

			keyInputHandler.onKeyPress(Qt::Key_A);

			Verify(Method(m_playerMock, rotate).Using(-1) + Method(m_playerTurnHandlerMock, next));
		}

		void shouldBeAbleToShoot()
		{
			KeyInputHandler keyInputHandler(m_playerTurnHandlerMock.get());

			keyInputHandler.onKeyPress(Qt::Key_Q);

			Verify(Method(m_playerMock, shoot) + Method(m_playerTurnHandlerMock, next));
		}

		void shouldBeAbleToUseMelee()
		{
			KeyInputHandler keyInputHandler(m_playerTurnHandlerMock.get());

			keyInputHandler.onKeyPress(Qt::Key_E);

			Verify(Method(m_playerMock, melee) + Method(m_playerTurnHandlerMock, next));
		}

	private:
		Mock<IPlayerTurnHandler> m_playerTurnHandlerMock;
		Mock<IPlayer> m_playerMock;
};

#endif // KEYINPUTHANDLERTESTS_H
