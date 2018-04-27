#include "KeyInputHandler.h"
#include "IPlayerTurnHandler.h"
#include "Player.h"

KeyInputHandler::KeyInputHandler(IPlayerTurnHandler &playerTurnHandler)
	: m_playerTurnHandler(playerTurnHandler)
{
}

void KeyInputHandler::onKeyPress(Platform::Sdl2Application::KeyEvent::Key key)
{
	IPlayer &player = m_playerTurnHandler.current();

	switch (key)
	{
		case Platform::Sdl2Application::KeyEvent::Key::Q:
		{
			player.shoot();

			return m_playerTurnHandler.next();
		}

		case Platform::Sdl2Application::KeyEvent::Key::E:
		{
			player.melee();

			return m_playerTurnHandler.next();
		}

		case Platform::Sdl2Application::KeyEvent::Key::A:
		{
			player.rotate(-1);

			return m_playerTurnHandler.next();
		}

		case Platform::Sdl2Application::KeyEvent::Key::D:
		{
			player.rotate(1);

			return m_playerTurnHandler.next();
		}

		case Platform::Sdl2Application::KeyEvent::Key::W:
		{
			player.advance();

			return m_playerTurnHandler.next();
		}

		case Platform::Sdl2Application::KeyEvent::Key::S:
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
