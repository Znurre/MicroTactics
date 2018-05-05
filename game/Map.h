#ifndef MAP_H
#define MAP_H

#include "IMap.h"

class Map : public IMap
{
	public:
		Map();

		QList<IMapTile *> tiles() override;
};

#endif // MAP_H
