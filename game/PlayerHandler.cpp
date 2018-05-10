#include "PlayerHandler.h"
#include "ICollisionHandler.h"

PlayerHandler::PlayerHandler(ICollisionHandler &collisionHandler
	, IMapHandler &mapHandler
	)
	: m_collisionHandler(collisionHandler)
	, m_playerProvider(*this, collisionHandler)
	, m_playerCount(8)
{
	m_players =
	{
		new Player(0, collisionHandler, mapHandler, m_playerProvider),
		new Player(1, collisionHandler, mapHandler, m_playerProvider),
		new Player(2, collisionHandler, mapHandler, m_playerProvider),
		new Player(3, collisionHandler, mapHandler, m_playerProvider),
		new Player(0, collisionHandler, mapHandler, m_playerProvider),
		new Player(1, collisionHandler, mapHandler, m_playerProvider),
		new Player(2, collisionHandler, mapHandler, m_playerProvider),
		new Player(3, collisionHandler, mapHandler, m_playerProvider),
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

QList<IPlayer *> PlayerHandler::activePlayers() const
{
	QList<IPlayer *> players;

	for (int i = 0; i < m_playerCount; i++)
	{
		IPlayer *player = m_players[i];

		if (player->health())
		{
			players << player;
		}
	}

	return players;
}

IPlayer &PlayerHandler::player(int index)
{
	return *m_players[index];
}
