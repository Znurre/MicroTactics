#ifndef MAPHANDLER_H
#define MAPHANDLER_H

#include "Map.h"

class MapHandler
{
	public:
		MapHandler();

		IMap &map();

	private:
		Map m_map;
};

#endif // MAPHANDLER_H
