#ifndef PLAYERHANDLER_H
#define PLAYERHANDLER_H

#include "IPlayerHandler.h"
#include "PlayerProvider.h"
#include "Player.h"

class ICollisionHandler;
class IMapHandler;

class PlayerHandler : public IPlayerHandler
{
	public:
		PlayerHandler(ICollisionHandler &collisionHandler, IMapHandler &mapHandler);

		void addPlayer() override;
		void removePlayer() override;

		int playerCount() const override;

		QList<IPlayer *> activePlayers() const override;

		IPlayer &player(int index) override;

	private:
		ICollisionHandler &m_collisionHandler;

		PlayerProvider m_playerProvider;

		QList<IPlayer *> m_players;

		int m_playerCount;
};

#endif // PLAYERHANDLER_H
