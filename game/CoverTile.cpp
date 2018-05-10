#include "CoverTile.h"

CoverTile::CoverTile(int x, int y)
	: m_x(x)
	, m_y(y)
{
}

int CoverTile::x() const
{
	return m_x;
}

int CoverTile::y() const
{
	return m_y;
}

void CoverTile::draw(QPainter &painter)
{
	static const QImage image("resources/cover.png");

	const int width = image.width();
	const int height = image.height();
	const int x = m_x * (width / 2) - m_y * (width / 2);
	const int y = m_x * (height / 4) + m_y * (height / 4);

	painter.drawImage(x, -y, image);
}

void CoverTile::iterate(ISceneNodeCallback &callback)
{
	callback.node(this);
}

int CoverTile::order() const
{
	return -(m_x + m_y);
}

bool CoverTile::isCollidable() const
{
	return true;
}
