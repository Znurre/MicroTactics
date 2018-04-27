#ifndef KEYINPUTHANDLER_H
#define KEYINPUTHANDLER_H

#include <Magnum/Platform/Sdl2Application.h>

using namespace Magnum;

class IPlayerTurnHandler;

class KeyInputHandler
{
	public:
		KeyInputHandler(IPlayerTurnHandler &playerTurnHandler);

		void onKeyPress(Platform::Sdl2Application::KeyEvent::Key key);

	private:
		IPlayerTurnHandler &m_playerTurnHandler;
};

#endif // KEYINPUTHANDLER_H
