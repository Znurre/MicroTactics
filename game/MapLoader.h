#ifndef MAPLOADER_H
#define MAPLOADER_H

#include "Map.h"

class MapLoader
{
	public:
		MapLoader();

		Map *load(const QString &fileName) const;
};

#endif // MAPLOADER_H
