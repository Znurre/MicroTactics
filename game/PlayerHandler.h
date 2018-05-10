#ifndef PLAYERHANDLER_H
#define PLAYERHANDLER_H

#include "IPlayerHandler.h"
#include "Player.h"

class PlayerHandler : public IPlayerHandler
{
	public:
		PlayerHandler(ICollisionHandler &collisionHandler);

		void addPlayer() override;
		void removePlayer() override;

		int playerCount() const override;

		IPlayer *playerInDirection(int x, int y, int direction) override;
		IPlayer *playerAt(int x, int y) override;

		IPlayer &player(int index) override;

	private:
		ICollisionHandler &m_collisionHandler;

		QList<Player *> m_players;

		int m_playerCount;
};

#endif // PLAYERHANDLER_H
