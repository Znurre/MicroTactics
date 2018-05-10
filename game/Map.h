#ifndef MAP_H
#define MAP_H

#include "IMap.h"

class Map : public IMap
{
	public:
		Map();

		int width() const;
		int height() const;

		IMapTile *tileAt(int x, int y) const override;

		QList<IMapTile *> tiles() const override;

	private:
		QList<IMapTile *> m_tiles;

		int m_width;
		int m_height;
};

#endif // MAP_H
