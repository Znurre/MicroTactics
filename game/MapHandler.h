#ifndef MAPHANDLER_H
#define MAPHANDLER_H

#include <QList>

#include "IMapHandler.h"

class IMap;

class MapHandler : public IMapHandler
{
	public:
		MapHandler();

		IMap &map() override;

	private:
		QList<IMap *> m_maps;
};

#endif // MAPHANDLER_H
