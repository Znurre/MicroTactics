#ifndef IMAP_H
#define IMAP_H

#include <QList>

#include "IDrawable.h"

class IMapTile : public IDrawable
{
	public:
		virtual bool isCollidable() const = 0;
};

class IMap
{
	public:
		virtual QList<IMapTile *> tiles() const = 0;
};

#endif // IMAP_H
