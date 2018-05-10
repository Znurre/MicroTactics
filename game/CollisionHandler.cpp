#include "CollisionHandler.h"
#include "MapHandler.h"
#include "IMap.h"

CollisionHandler::CollisionHandler(MapHandler &mapHandler)
	: m_mapHandler(mapHandler)
{
}

bool CollisionHandler::isCollidable(int x, int y) const
{
	const IMap &map = m_mapHandler.map();
	const IMapTile *tile = map.tileAt(x, y);

	if (!tile)
	{
		return true;
	}

	if (!tile->isCollidable())
	{
		return false;
	}

	return true;
}
