#include "Map.h"

Map::Map(const QList<IMapTile *> &tiles, QList<IMapTile *> &playerSpawns, int width, int height)
	: m_tiles(tiles)
	, m_playerSpawns(playerSpawns)
	, m_width(width)
	, m_height(height)
{
}

int Map::width() const
{
	return m_width;
}

int Map::height() const
{
	return m_height;
}

IMapTile *Map::tileAt(int x, int y) const
{
	if (x < 0 || x >= m_width)
	{
		return nullptr;
	}

	if (y < 0 || y >= m_height)
	{
		return nullptr;
	}

	return m_tiles[x +(m_width * y)];
}

IMapTile *Map::spawnForPlayer(int id) const
{
	return m_playerSpawns[id];
}

QList<IMapTile *> Map::tiles() const
{
	return m_tiles;
}
