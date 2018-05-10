#include "PlayerHandler.h"
#include "ICollisionHandler.h"

PlayerHandler::PlayerHandler(ICollisionHandler &collisionHandler)
	: m_collisionHandler(collisionHandler)
//	: m_players(4)
	, m_playerCount(2)
{
	m_players =
	{
		new Player(collisionHandler, *this),
		new Player(collisionHandler, *this),
		new Player(collisionHandler, *this),
		new Player(collisionHandler, *this)
	};
}

void PlayerHandler::addPlayer()
{
	if (m_playerCount < 4)
	{
		m_playerCount++;
	}
}

void PlayerHandler::removePlayer()
{
	if (m_playerCount > 2)
	{
		m_playerCount--;
	}
}

int PlayerHandler::playerCount() const
{
	return m_playerCount;
}

IPlayer *PlayerHandler::playerInDirection(int x, int y, int direction)
{
	const int dx = (int)sin(direction * M_PI / 2);
	const int dy = -(int)cos(direction * M_PI / 2);

	for (int i = 1; ; i++)
	{
		const int rx = x + dx * i;
		const int ry = y + dy * i;

		if (m_collisionHandler.isCollidable(rx, ry))
		{
			return nullptr;
		}

		for (int j = 0; j < m_playerCount; j++)
		{
			Player *player = m_players[j];

			if (player->x() == rx &&
				player->y() == ry)
			{
				return player;
			}
		}
	}

	return nullptr;
}

IPlayer *PlayerHandler::playerAt(int x, int y)
{
	Q_UNUSED(x);
	Q_UNUSED(y);

	return m_players[0];
}

IPlayer &PlayerHandler::player(int index)
{
	return *m_players[index];
}
