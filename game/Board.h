#ifndef BOARD_H
#define BOARD_H

#include "ISceneNode.h"
#include "IMap.h"
#include "Map.h"

class MapHandler;

class Board : public ISceneNode
{
	public:
		Board(MapHandler &mapHandler);

		void iterate(ISceneNodeCallback &callback) override;

	private:
		MapHandler &m_mapHandler;
};

#endif // BOARD_H
