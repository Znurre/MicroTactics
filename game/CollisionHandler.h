#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include "ICollisionHandler.h"

class MapHandler;

class CollisionHandler : public ICollisionHandler
{
	public:
		CollisionHandler(MapHandler &mapHandler);

		bool isCollidable(int x, int y) const override;

	private:
		MapHandler &m_mapHandler;
};

#endif // COLLISIONHANDLER_H
