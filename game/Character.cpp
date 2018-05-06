#include "Character.h"
#include "ICharacterProperties.h"

Character::Character(ICharacterProperties &properties)
	: m_properties(properties)
	, m_turret(properties, m_palette)
{
}

void Character::draw(QPainter &painter)
{
	const QImage &image = selectImage();

	const int width = image.width();
	const int height = image.height();
	const int x = m_properties.x() * (width / 2) - m_properties.y() * (width / 2);
	const int y = m_properties.x() * (height / 4) + m_properties.y() * (height / 4);

	painter.drawImage(x, -y, image);

//	QPolygon leftFace;
//	leftFace << QPoint(0, 0);
//	leftFace << QPoint(0, 30);
//	leftFace << QPoint(30, 60);
//	leftFace << QPoint(30, 30);

//	QPolygon topFace;
//	topFace << QPoint(0, 0);
//	topFace << QPoint(30, 30);
//	topFace << QPoint(55, 30);
//	topFace << QPoint(25, 0);

//	QPolygon frontFace;
//	frontFace << QPoint(30, 30);
//	frontFace << QPoint(30, 60);
//	frontFace << QPoint(55, 60);
//	frontFace << QPoint(55, 30);

//	painter.setBrush(QBrush("#6f918a"));
//	painter.drawPolygon(leftFace);

//	painter.setBrush(QBrush("#dbe3e2"));
//	painter.drawPolygon(topFace);

//	painter.setBrush(QBrush("#93aca7"));
//	painter.drawPolygon(frontFace);

//	FaceDefinition face;

//	memset(&face, 0, 8 * 8 * sizeof(void *));

//	m_faceTemplate.apply(face, m_palette);

//	const QRectF &faceRect = frontFace.boundingRect();

//	const double frx = faceRect.width() / 8.0;
//	const double fry = faceRect.height() / 8.0;

//	for (int x = 0; x < 8; x++)
//	{
//		for (int y = 0; y < 8; y++)
//		{
//			const QRectF rect(faceRect.x() + frx * x, faceRect.y() + fry * y, frx, fry);
//			const QColor *color = face[y][x];

//			if (color)
//			{
//				painter.fillRect(rect, *color);
//			}
//		}
//	}

	//	m_turret.draw(painter);
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
