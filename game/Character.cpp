#include "Character.h"
#include "ICharacterProperties.h"

Character::Character(ICharacterProperties &properties)
	: m_properties(properties)
{
}

void Character::iterate(ISceneNodeCallback &callback)
{
	callback.node(this);
}

void Character::draw(QPainter &painter)
{
	const QImage &image = selectImage();

	const int width = image.width();
	const int height = image.height();
	const int x = m_properties.x() * (width / 2) - m_properties.y() * (width / 2);
	const int y = m_properties.x() * (height / 4) + m_properties.y() * (height / 4);
	const int health = m_properties.health();

	painter.setOpacity(health / 3.0);
	painter.drawImage(x, -y, image);
	painter.setOpacity(1);
}

int Character::order() const
{
	return -(m_properties.x() + m_properties.y()) + 1;
}

QImage Character::selectImage() const
{
	static const QList<QImage> images =
	{
		QImage("resources/south.png"),
		QImage("resources/east.png"),
		QImage("resources/north.png"),
		QImage("resources/west.png")
	};

	const int rotation = m_properties.rotation();

	return images[rotation];
}
