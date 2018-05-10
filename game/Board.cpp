#include "Board.h"
#include "MapHandler.h"

Board::Board(MapHandler &mapHandler)
	: m_mapHandler(mapHandler)
{
}

void Board::iterate(ISceneNodeCallback &callback)
{
	callback.node(this);

	const IMap &map = m_mapHandler.map();

	for (IMapTile *tile : map.tiles())
	{
		tile->iterate(callback);
	}
}
