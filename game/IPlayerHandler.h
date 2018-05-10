#ifndef IPLAYERHANDLER_H
#define IPLAYERHANDLER_H

#include <QList>

class IPlayer;

class IPlayerHandler
{
	public:
		virtual void addPlayer() = 0;
		virtual void removePlayer() = 0;

		virtual int playerCount() const = 0;

		virtual IPlayer *playerInDirection(int x, int y, int direction) = 0;
		virtual IPlayer *playerAt(int x, int y) = 0;

		virtual IPlayer &player(int index) = 0;
};

#endif // IPLAYERHANDLER_H
