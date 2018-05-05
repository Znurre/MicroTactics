#ifndef KEYINPUTHANDLER_H
#define KEYINPUTHANDLER_H

class IPlayerTurnHandler;

class KeyInputHandler
{
	public:
		KeyInputHandler(IPlayerTurnHandler &playerTurnHandler);

		void onKeyPress(int key);

	private:
		IPlayerTurnHandler &m_playerTurnHandler;
};

#endif // KEYINPUTHANDLER_H
