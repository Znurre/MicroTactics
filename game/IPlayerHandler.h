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

		virtual QList<IPlayer *> activePlayers() const = 0;

		virtual IPlayer &player(int index) = 0;
};

#endif // IPLAYERHANDLER_H
