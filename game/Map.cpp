#include "Map.h"

class GroundTile : public IMapTile
{
	public:
		GroundTile(int x, int y)
			: m_x(x)
			, m_y(y)
		{
		}

		void draw() override
		{
		}

		bool isCollidable() const override
		{
			return false;
		}

	private:
		int m_x;
		int m_y;
};

class CoverTile : public IMapTile
{
	public:
		CoverTile(int x, int y)
			: m_x(x)
			, m_y(y)
		{
		}

		void draw() override
		{
		}

		bool isCollidable() const override
		{
			return true;
		}

	private:
		int m_x;
		int m_y;
};

Map::Map()
{

}

QList<IMapTile *> Map::tiles()
{
	return
	{
		new GroundTile(0, 0),
		new GroundTile(1, 0),
		new GroundTile(0, 1),
		new CoverTile(1, 1),
		new GroundTile(2, 0),
		new GroundTile(2, 1),
		new GroundTile(0, 2),
		new GroundTile(1, 2),
		new GroundTile(2, 2),
	};
}
