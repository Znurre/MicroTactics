#include "Board.h"

Board::Board()
	: m_map(m_dummyMap)
{
}

void Board::draw()
{
	for (IMapTile *tile : m_map.tiles())
	{
		tile->draw();
	}
}
