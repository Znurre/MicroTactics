#include <QKeyEvent>

#include "KeyInputHandler.h"
#include "IPlayerTurnHandler.h"
#include "Player.h"

KeyInputHandler::KeyInputHandler(IPlayerTurnHandler &playerTurnHandler)
	: m_playerTurnHandler(playerTurnHandler)
{
}

void KeyInputHandler::onKeyPress(int key)
{
	IPlayer &player = m_playerTurnHandler.current();

	switch (key)
	{
		case Qt::Key_Q:
		{
			player.shoot();

			return m_playerTurnHandler.next();
		}

		case Qt::Key_E:
		{
			player.melee();

			return m_playerTurnHandler.next();
		}

		case Qt::Key_A:
		{
			player.rotate(-1);

			return m_playerTurnHandler.next();
		}

		case Qt::Key_D:
		{
			player.rotate(1);

			return m_playerTurnHandler.next();
		}

		case Qt::Key_W:
		{
			player.advance();

			return m_playerTurnHandler.next();
		}

		case Qt::Key_S:
		{
			player.retreat();

			return m_playerTurnHandler.next();
		}

		default:
		{
			break;
		}
	}
}
