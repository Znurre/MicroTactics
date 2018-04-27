#ifndef BOARD_H
#define BOARD_H

#include "IDrawable.h"
#include "IMap.h"
#include "Map.h"

class Board : public IDrawable
{
	public:
		Board();

		void draw() override;

	private:
		Map m_dummyMap;

		IMap &m_map;
};

#endif // BOARD_H
