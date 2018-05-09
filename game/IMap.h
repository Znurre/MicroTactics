#ifndef IMAP_H
#define IMAP_H

#include <QList>

#include "IDrawable.h"
#include "ISceneNode.h"

class IMapTile : public ISceneNode, public IDrawable
{
	public:
		virtual bool isCollidable() const = 0;
};

class IMap
{
	public:
		virtual QList<IMapTile *> tiles() = 0;
};

#endif // IMAP_H
