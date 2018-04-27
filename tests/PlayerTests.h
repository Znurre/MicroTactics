#include <QString>
#include <QtTest>

#include "Player.h"

class PlayerTests : public QObject
{
	Q_OBJECT

	private slots:
		void shouldBeAbleToRotate()
		{
			Player player;

			QCOMPARE(player.rotation(), 0);

			player.rotate(1);

			QCOMPARE(player.rotation(), 1);

			player.rotate(1);

			QCOMPARE(player.rotation(), 2);

			player.rotate(1);

			QCOMPARE(player.rotation(), 3);

			player.rotate(1);

			QCOMPARE(player.rotation(), 0);

			player.rotate(1);

			QCOMPARE(player.rotation(), 1);

			player.rotate(-1);

			QCOMPARE(player.rotation(), 0);

			player.rotate(-1);

			QCOMPARE(player.rotation(), 3);
		}

		void shouldBeAbleToAdvance()
		{
			Player player;

			QCOMPARE(player.x(), 0);
			QCOMPARE(player.y(), 0);

			player.advance();

			QCOMPARE(player.x(), 0);
			QCOMPARE(player.y(), -1);

			player.advance();

			QCOMPARE(player.x(), 0);
			QCOMPARE(player.y(), -2);

			player.rotate(1);
			player.advance();

			QCOMPARE(player.x(), 1);
			QCOMPARE(player.y(), -2);

			player.advance();

			QCOMPARE(player.x(), 2);
			QCOMPARE(player.y(), -2);

			player.rotate(1);
			player.advance();

			QCOMPARE(player.x(), 2);
			QCOMPARE(player.y(), -1);

			player.advance();

			QCOMPARE(player.x(), 2);
			QCOMPARE(player.y(), 0);

			player.rotate(1);
			player.advance();

			QCOMPARE(player.x(), 1);
			QCOMPARE(player.y(), 0);

			player.advance();

			QCOMPARE(player.x(), 0);
			QCOMPARE(player.y(), 0);
		}

		void shouldBeAbleToRetreat()
		{
			Player player;

			QCOMPARE(player.x(), 0);
			QCOMPARE(player.y(), 0);

			player.retreat();

			QCOMPARE(player.x(), 0);
			QCOMPARE(player.y(), 1);

			player.retreat();

			QCOMPARE(player.x(), 0);
			QCOMPARE(player.y(), 2);

			player.rotate(1);
			player.retreat();

			QCOMPARE(player.x(), -1);
			QCOMPARE(player.y(), 2);

			player.retreat();

			QCOMPARE(player.x(), -2);
			QCOMPARE(player.y(), 2);

			player.rotate(1);
			player.retreat();

			QCOMPARE(player.x(), -2);
			QCOMPARE(player.y(), 1);

			player.retreat();

			QCOMPARE(player.x(), -2);
			QCOMPARE(player.y(), 0);

			player.rotate(1);
			player.retreat();

			QCOMPARE(player.x(), -1);
			QCOMPARE(player.y(), 0);

			player.retreat();

			QCOMPARE(player.x(), 0);
			QCOMPARE(player.y(), 0);
		}
};
