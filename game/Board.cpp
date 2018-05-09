#include "Board.h"

Board::Board()
	: m_map(m_dummyMap)
{
}

void Board::iterate(ISceneNodeCallback &callback)
{
	callback.node(this);

	for (IMapTile *tile : m_map.tiles())
	{
		tile->iterate(callback);
	}
}
