#include "PlayerTurnHandler.h"
#include "IPlayerHandler.h"

PlayerTurnHandler::PlayerTurnHandler(IPlayerHandler &playerHandler)
	: m_playerHandler(playerHandler)
	, m_current(0)
{
}

IPlayer &PlayerTurnHandler::current()
{
	const int playerCount = m_playerHandler.playerCount();
	const int playerIndex = m_current % playerCount;

	return m_playerHandler.player(playerIndex);
}

void PlayerTurnHandler::next()
{
	m_current++;
}
