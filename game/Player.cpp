#include "Player.h"

Player::Player()
	: m_character(*this)
	, m_rotation(0)
	, m_x(0)
	, m_y(0)
{
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

void Player::advance()
{
	m_x += (int)sin(m_rotation * M_PI / 2);
	m_y -= (int)cos(m_rotation * M_PI / 2);
}

void Player::retreat()
{
	m_x -= (int)sin(m_rotation * M_PI / 2);
	m_y += (int)cos(m_rotation * M_PI / 2);
}

void Player::shoot()
{

}

void Player::melee()
{

}

void Player::draw(QPainter &painter)
{
	m_character.draw(painter);
}
