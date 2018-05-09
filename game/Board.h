#ifndef BOARD_H
#define BOARD_H

#include "ISceneNode.h"
#include "IMap.h"
#include "Map.h"

class Board : public ISceneNode
{
	public:
		Board();

		void iterate(ISceneNodeCallback &callback) override;

	private:
		Map m_dummyMap;

		IMap &m_map;
};

#endif // BOARD_H
