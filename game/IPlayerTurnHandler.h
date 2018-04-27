#ifndef IPLAYERTURNHANDLER_H
#define IPLAYERTURNHANDLER_H

class IPlayer;

class IPlayerTurnHandler
{
	public:
		virtual IPlayer &current() = 0;

		virtual void next() = 0;
};

#endif // IPLAYERTURNHANDLER_H
