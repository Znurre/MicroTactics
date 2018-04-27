#ifndef PLAYERTURNHANDLER_H
#define PLAYERTURNHANDLER_H

#include "IPlayerTurnHandler.h"

class IPlayerHandler;

class PlayerTurnHandler : public IPlayerTurnHandler
{
	public:
		PlayerTurnHandler(IPlayerHandler &playerHandler);

		IPlayer &current() override;

		void next() override;

	private:
		IPlayerHandler &m_playerHandler;

		int m_current;
};

#endif // PLAYERTURNHANDLER_H
