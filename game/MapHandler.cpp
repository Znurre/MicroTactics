#include "MapHandler.h"
#include "MapLoader.h"

MapHandler::MapHandler()
{
	MapLoader mapLoader;

	m_maps << mapLoader.load("resources/maps/first.tmx");
}

IMap &MapHandler::map()
{
	return *m_maps[0];
}
