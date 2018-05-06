#include "PlayerHandler.h"

PlayerHandler::PlayerHandler()
	: m_players(4)
	, m_playerCount(1)
{
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

IPlayer &PlayerHandler::player(int index)
{
	return m_players[index];
}
