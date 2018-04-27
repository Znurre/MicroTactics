#ifndef PLAYERHANDLER_H
#define PLAYERHANDLER_H

#include "IPlayerHandler.h"
#include "Player.h"

class PlayerHandler : public IPlayerHandler
{
	public:
		PlayerHandler();

		void addPlayer() override;
		void removePlayer() override;

		int playerCount() const override;

		IPlayer &player(int index) override;

	private:
		QVector<Player> m_players;

		int m_playerCount;
};

#endif // PLAYERHANDLER_H
