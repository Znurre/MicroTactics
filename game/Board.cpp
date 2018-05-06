#include "Board.h"

Board::Board()
	: m_map(m_dummyMap)
{
}

void Board::draw(QPainter &painter)
{
	for (IMapTile *tile : m_map.tiles())
	{
		tile->draw(painter);
	}
}
