#include <QDebug>

#include "Player.h"
#include "CollisionHandler.h"
#include "IPlayerHandler.h"

Player::Player(ICollisionHandler &collisionHandler, IPlayerHandler &playerHandler)
	: m_collisionHandler(collisionHandler)
	, m_playerHandler(playerHandler)
	, m_character(*this)
	, m_health(3)
	, m_rotation(0)
	, m_x(0)
	, m_y(0)
{
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
	return m_x;
}

int Player::y() const
{
	return m_y;
}

void Player::rotate(int direction)
{
	m_rotation = ((m_rotation - direction) % 4 + 4) % 4;
}

void Player::damage()
{
	if ((m_health--) <= 0)
	{
		qDebug() << "Player died";
	}
}

void Player::advance()
{
	const int x = m_x + (int)sin(m_rotation * M_PI / 2);
	const int y = m_y - (int)cos(m_rotation * M_PI / 2);

	if (m_collisionHandler.isCollidable(x, y))
	{
		return;
	}

	m_x = x;
	m_y = y;
}

void Player::retreat()
{
	const int x = m_x - (int)sin(m_rotation * M_PI / 2);
	const int y = m_y + (int)cos(m_rotation * M_PI / 2);

	if (m_collisionHandler.isCollidable(x, y))
	{
		return;
	}

	m_x = x;
	m_y = y;
}

void Player::shoot()
{
	IPlayer *player = m_playerHandler.playerInDirection(m_x, m_y, m_rotation);

	if (player)
	{
		player->damage();
	}
}

void Player::melee()
{

}

void Player::iterate(ISceneNodeCallback &callback)
{
	callback.node(this);

	m_character.iterate(callback);
}
