#ifndef PLAYERTURNHANDLERTESTS_H
#define PLAYERTURNHANDLERTESTS_H

#include "PlayerTurnHandler.h"
#include "IPlayerHandler.h"
#include "IPlayer.h"

#include "fakeit.hpp"

using namespace fakeit;

class PlayerTurnHandlerTests : public QObject
{
	Q_OBJECT

	private slots:
		void shouldBeAbleToSkipTurn()
		{
			Mock<IPlayer> player1;
			Mock<IPlayer> player2;
			Mock<IPlayer> player3;
			Mock<IPlayerHandler> playerHandlerMock;

			When(Method(playerHandlerMock, playerCount)).AlwaysReturn(3);
			When(Method(playerHandlerMock, player).Using(0)).AlwaysReturn(player1.get());
			When(Method(playerHandlerMock, player).Using(1)).AlwaysReturn(player2.get());
			When(Method(playerHandlerMock, player).Using(2)).AlwaysReturn(player3.get());

			PlayerTurnHandler playerTurnHandler(playerHandlerMock.get());

			QCOMPARE(&playerTurnHandler.current(), &player1.get());
			QCOMPARE(&playerTurnHandler.current(), &player1.get());

			playerTurnHandler.next();

			QCOMPARE(&playerTurnHandler.current(), &player2.get());
			QCOMPARE(&playerTurnHandler.current(), &player2.get());

			playerTurnHandler.next();

			QCOMPARE(&playerTurnHandler.current(), &player3.get());
			QCOMPARE(&playerTurnHandler.current(), &player3.get());

			playerTurnHandler.next();

			QCOMPARE(&playerTurnHandler.current(), &player1.get());
			QCOMPARE(&playerTurnHandler.current(), &player1.get());
		}
};

#endif // PLAYERTURNHANDLERTESTS_H
