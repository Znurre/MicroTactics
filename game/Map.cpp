#include "Map.h"

class GroundTile : public IMapTile
{
	public:
		GroundTile(MyShader &shader, int x, int y)
			: m_shader(shader)
			, m_x(x)
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
		MyShader &m_shader;

		int m_x;
		int m_y;
};

Map::Map()
{
}

QList<IMapTile *> Map::tiles() const
{
	return
	{
		new GroundTile(m_shader, 0, 0),
		new GroundTile(m_shader, 1, 0),
		new GroundTile(m_shader, 0, 1),
		new GroundTile(m_shader, 1, 1)
	};
}
