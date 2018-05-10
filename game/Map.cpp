#include "Map.h"

class GroundTile : public IMapTile
{
	public:
		GroundTile(int x, int y)
			: m_x(x)
			, m_y(y)
		{
		}

		void draw(QPainter &painter) override
		{
			static const QImage image("resources/ground.png");

			const int width = image.width();
			const int height = image.height();
			const int x = m_x * (width / 2) - m_y * (width / 2);
			const int y = m_x * (height / 4) + m_y * (height / 4);

			painter.drawImage(x, -y, image);
		}

		void iterate(ISceneNodeCallback &callback) override
		{
			callback.node(this);
		}

		int order() const override
		{
			return -(m_x + m_y);
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

		void draw(QPainter &painter) override
		{
			static const QImage image("resources/cover.png");

			const int width = image.width();
			const int height = image.height();
			const int x = m_x * (width / 2) - m_y * (width / 2);
			const int y = m_x * (height / 4) + m_y * (height / 4);

			painter.drawImage(x, -y, image);
		}

		void iterate(ISceneNodeCallback &callback) override
		{
			callback.node(this);
		}

		int order() const override
		{
			return -(m_x + m_y);
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
	: m_width(3)
	, m_height(3)
{
	m_tiles =
	{
		new GroundTile(0, 0),
		new GroundTile(1, 0),
		new GroundTile(2, 0),
		new GroundTile(0, 1),
		new CoverTile(1, 1),
		new GroundTile(2, 1),
		new GroundTile(0, 2),
		new GroundTile(1, 2),
		new GroundTile(2, 2),
	};
}

int Map::width() const
{
	return m_width;
}

int Map::height() const
{
	return m_height;
}

IMapTile *Map::tileAt(int x, int y) const
{
	if (x < 0 || x >= m_width)
	{
		return nullptr;
	}

	if (y < 0 || y >= m_height)
	{
		return nullptr;
	}

	return m_tiles[x +(m_width * y)];
}

QList<IMapTile *> Map::tiles() const
{
	return m_tiles;
}
