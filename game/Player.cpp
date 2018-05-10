#include <QDebug>

#include "Player.h"
#include "CollisionHandler.h"
#include "IPlayerProvider.h"
#include "IMapHandler.h"
#include "IMap.h"

Player::Player(int id
	, ICollisionHandler &collisionHandler
	, IMapHandler &mapHandler
	, IPlayerProvider &playerHandler
	)
	: m_collisionHandler(collisionHandler)
	, m_mapHandler(mapHandler)
	, m_playerProvider(playerHandler)
	, m_character(*this)
	, m_id(id)
	, m_health(1)
	, m_rotation(0)
	, m_x(nullptr)
	, m_y(nullptr)
{
}

Player::~Player()
{
	delete m_x;
	delete m_y;
}

int Player::health() const
{
	return m_health;
}

int Player::rotation() const
{
	return m_rotation;
}

int Player::x() const
{
	if (!m_x)
	{
		IMap &map = m_mapHandler.map();
		IMapTile *spawn = map.spawnForPlayer(m_id);

		if (!spawn)
		{
			return 0;
		}

		return spawn->x();
	}

	return *m_x;
}

int Player::y() const
{
	if (!m_y)
	{
		IMap &map = m_mapHandler.map();
		IMapTile *spawn = map.spawnForPlayer(m_id);

		if (!spawn)
		{
			return 0;
		}

		return spawn->y();
	}

	return *m_y;
}

int Player::id() const
{
	return m_id;
}

void Player::rotate(int direction)
{
	ensurePosition();

	m_rotation = ((m_rotation - direction) % 4 + 4) % 4;
}

void Player::damage()
{
	m_health = 0;
}

void Player::advance()
{
	ensurePosition();

	const int x = *m_x + (int)sin(m_rotation * M_PI / 2);
	const int y = *m_y - (int)cos(m_rotation * M_PI / 2);

	if (m_collisionHandler.isCollidable(x, y))
	{
		return damage();
	}

	if (m_playerProvider.playerAt(x, y))
	{
		return damage();
	}

	*m_x = x;
	*m_y = y;
}

void Player::retreat()
{
	ensurePosition();

	const int x = *m_x - (int)sin(m_rotation * M_PI / 2);
	const int y = *m_y + (int)cos(m_rotation * M_PI / 2);

	if (m_collisionHandler.isCollidable(x, y))
	{
		return damage();
	}

	if (m_playerProvider.playerAt(x, y))
	{
		return damage();
	}

	*m_x = x;
	*m_y = y;
}

void Player::shoot()
{
	IPlayer *player = m_playerProvider.playerInDirection(this);

	if (player)
	{
		if (player->id() != m_id)
		{
			player->damage();
		}
	}
}

void Player::melee()
{
	QList<IPlayer *> players = m_playerProvider.playersSurrounding(this);

	for (IPlayer *player : players)
	{
		if (player->id() != m_id)
		{
			player->damage();
		}
	}
}

void Player::iterate(ISceneNodeCallback &callback)
{
	callback.node(this);

	m_character.iterate(callback);
}

void Player::ensurePosition()
{
	if (!m_x)
	{
		m_x = new int(x());
	}

	if (!m_y)
	{
		m_y = new int(y());
	}
}
