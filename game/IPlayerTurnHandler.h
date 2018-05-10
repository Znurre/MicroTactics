#ifndef IPLAYERTURNHANDLER_H
#define IPLAYERTURNHANDLER_H

#include "IDrawable.h"

class IPlayer;

class IPlayerTurnHandler
{
	public:
		virtual IPlayer &current() = 0;

		virtual void next() = 0;
};

#endif // IPLAYERTURNHANDLER_H
