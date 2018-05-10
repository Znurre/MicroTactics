#ifndef GROUNDTILE_H
#define GROUNDTILE_H

#include "IMap.h"

class GroundTile : public IMapTile
{
	public:
		GroundTile(int x, int y);

		int x() const override;
		int y() const override;

		void draw(QPainter &painter) override;
		void iterate(ISceneNodeCallback &callback) override;

		int order() const override;

		bool isCollidable() const override;

	private:
		int m_x;
		int m_y;
};

#endif // GROUNDTILE_H
