#include "GroundTile.h"

GroundTile::GroundTile(int x, int y)
	: m_x(x)
	, m_y(y)
{
}

int GroundTile::x() const
{
	return m_x;
}

int GroundTile::y() const
{
	return m_y;
}

void GroundTile::draw(QPainter &painter)
{
	static const QImage image("resources/ground.png");

	const int width = image.width();
	const int height = image.height();
	const int x = m_x * (width / 2) - m_y * (width / 2);
	const int y = m_x * (height / 4) + m_y * (height / 4);

	painter.drawImage(x, -y, image);
}

void GroundTile::iterate(ISceneNodeCallback &callback)
{
	callback.node(this);
}

int GroundTile::order() const
{
	return -(m_x + m_y);
}

bool GroundTile::isCollidable() const
{
	return false;
}
