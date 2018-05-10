#ifndef COVERTILE_H
#define COVERTILE_H

#include "IMap.h"

class CoverTile : public IMapTile
{
	public:
		CoverTile(int x, int y);

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

#endif // COVERTILE_H
