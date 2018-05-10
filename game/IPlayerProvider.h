#ifndef IPLAYERPROVIDER_H
#define IPLAYERPROVIDER_H

#include <QList>

class IPlayer;

class IPlayerProvider
{
	public:
		virtual QList<IPlayer *> playersSurrounding(IPlayer *self) = 0;

		virtual IPlayer *playerInDirection(IPlayer *self) = 0;
		virtual IPlayer *playerAt(int x, int y) = 0;
};

#endif // IPLAYERPROVIDER_H
