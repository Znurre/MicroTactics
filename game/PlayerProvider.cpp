#include <QtMath>

#include "PlayerProvider.h"
#include "IPlayerHandler.h"
#include "ICollisionHandler.h"
#include "IPlayer.h"

PlayerProvider::PlayerProvider(IPlayerHandler &playerHandler, ICollisionHandler &collisionHandler)
	: m_playerHandler(playerHandler)
	, m_collisionHandler(collisionHandler)
{
}

IPlayer *PlayerProvider::playerInDirection(IPlayer *self)
{
	const int dx = (int)qSin(self->rotation() * M_PI / 2);
	const int dy = -(int)qCos(self->rotation() * M_PI / 2);

	for (int i = 1; ; i++)
	{
		const int rx = self->x() + dx * i;
		const int ry = self->y() + dy * i;

		if (m_collisionHandler.isCollidable(rx, ry))
		{
			return nullptr;
		}

		for (IPlayer *player : m_playerHandler.activePlayers())
		{
			if (player->x() == rx &&
				player->y() == ry)
			{
				return player;
			}
		}
	}

	return nullptr;
}

IPlayer *PlayerProvider::playerAt(int x, int y)
{
	for (IPlayer *player : m_playerHandler.activePlayers())
	{
		if (player->x() == x &&
			player->y() == y)
		{
			return player;
		}
	}

	return nullptr;
}

QList<IPlayer *> PlayerProvider::playersSurrounding(IPlayer *self)
{
	QList<IPlayer *> players;

	for (IPlayer *player : m_playerHandler.activePlayers())
	{
		const int dx = qAbs(self->x() - player->x());
		const int dy = qAbs(self->y() - player->y());

		if (dx <= 1 && dy <= 1)
		{
			players << player;
		}
	}

	return players;
}
