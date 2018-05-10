#ifndef MAP_H
#define MAP_H

#include "IMap.h"

class Map : public IMap
{
	public:
		Map(const QList<IMapTile *> &tiles, QList<IMapTile *> &playerSpawns, int width, int height);

		int width() const;
		int height() const;

		IMapTile *tileAt(int x, int y) const override;
		IMapTile *spawnForPlayer(int id) const override;

		QList<IMapTile *> tiles() const override;

	private:
		QList<IMapTile *> m_tiles;
		QList<IMapTile *> m_playerSpawns;

		int m_width;
		int m_height;
};

#endif // MAP_H
