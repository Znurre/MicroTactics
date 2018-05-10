#ifndef IMAP_H
#define IMAP_H

#include <QList>

#include "IDrawable.h"
#include "ISceneNode.h"

class IMapTile : public ISceneNode, public IDrawable
{
	public:
		virtual int x() const = 0;
		virtual int y() const = 0;

		virtual bool isCollidable() const = 0;
};

class IMap
{
	public:
		virtual IMapTile *tileAt(int x, int y) const = 0;
		virtual IMapTile *spawnForPlayer(int id) const = 0;

		virtual QList<IMapTile *> tiles() const = 0;
};

#endif // IMAP_H
