#ifndef PLAYERPROVIDER_H
#define PLAYERPROVIDER_H

#include "IPlayerHandler.h"
#include "IPlayerProvider.h"

class IPlayerHandler;
class ICollisionHandler;

class PlayerProvider : public IPlayerProvider
{
	public:
		PlayerProvider(IPlayerHandler &playerProvider, ICollisionHandler &collisionHandler);

		QList<IPlayer *> playersSurrounding(IPlayer *self) override;

		IPlayer *playerInDirection(IPlayer *self) override;
		IPlayer *playerAt(int x, int y) override;

	private:
		IPlayerHandler &m_playerHandler;
		ICollisionHandler &m_collisionHandler;
};

#endif // PLAYERPROVIDER_H
