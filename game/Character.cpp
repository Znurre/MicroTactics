#include "Character.h"
#include "ICharacterProperties.h"
#include "IPlayerTurnHandler.h"
#include "IPlayer.h"

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
	if (!m_properties.health())
	{
		return;
	}

	QImage image = selectImage();

	QColor color((Qt::GlobalColor)(Qt::red + m_properties.id()));
	color.setAlpha(100);

	QPainter painter1(&image);
	painter1.setCompositionMode(QPainter::CompositionMode_SourceAtop);
	painter1.fillRect(image.rect(), color);

	const int width = image.width();
	const int height = image.height();
	const int x = m_properties.x() * (width / 2) - m_properties.y() * (width / 2);
	const int y = m_properties.x() * (height / 4) + m_properties.y() * (height / 4);

	painter.drawImage(x, -y, image);
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
