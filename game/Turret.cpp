#include <QtMath>

#include "Turret.h"
#include "ICharacterProperties.h"

Turret::Turret(ICharacterProperties &properties, IPalette &palette)
	: m_properties(properties)
	, m_palette(palette)
{
}

void Turret::draw(QPainter &painter)
{
	const QRectF barrelBase(40, 46.5, 5, 5);
	const QPainterPath &barrel = createPath(barrelBase, 20);
	const QRectF &barrelBoundingRect = barrel.boundingRect();

	const QRectF muzzleBase(barrelBoundingRect.right() - 6, barrelBoundingRect.bottom() - 6, 7, 7);
	const QPainterPath &muzzle = createPath(muzzleBase, 30);
	const QRectF &muzzleBoundingRect = muzzle.boundingRect();

	const QRectF muzzleEnd(muzzleBoundingRect.right() - 7, muzzleBoundingRect.bottom() - 7, 7, 7);
	const QRectF &groove = muzzleEnd.adjusted(1, 1, -1, -1);

	painter.setBrush(QBrush("#b7c8c4"));
	painter.drawPath(barrel);
	painter.setBrush(QBrush("#dbe3e2"));
	painter.drawPath(muzzle);
	painter.setBrush(QBrush("#b7c8c4"));
	painter.drawEllipse(muzzleEnd);
	painter.setBrush(QBrush("#374845"));
	painter.drawEllipse(groove);
}

QPointF Turret::createPoint(const QPointF &point, double radius, double angle) const
{
	const double x = radius * qCos(angle) + point.x();
	const double y = radius * qSin(angle) + point.y();

	return QPointF(x, y);
}

QPainterPath Turret::createPath(const QRectF &source, double length) const
{
	static const double SouthWest = qDegreesToRadians(-225.0);
	static const double NorthWest = qDegreesToRadians(-135.0);
	static const double NorthEast = qDegreesToRadians(-45.0);
	static const double SouthEast = qDegreesToRadians(45.0);

	const double thickness = source.width() / 2.0;
	const double innerLength = length - source.width();

	const QPointF &start = source.center();
	const QPointF &end = createPoint(start, innerLength, SouthEast);

	const QPointF &start1 = createPoint(start, thickness, SouthWest);
	const QPointF &end1 = createPoint(start, thickness, NorthWest);
	const QPointF &cp11 = createPoint(start1, thickness / 2.0, NorthWest);
	const QPointF &cp12 = createPoint(end1, thickness / 2.0, SouthWest);

	const QPointF &end2 = createPoint(start, thickness, NorthEast);
	const QPointF &cp21 = createPoint(end1, thickness / 2.0, NorthEast);
	const QPointF &cp22 = createPoint(end2, thickness / 2.0, NorthWest);

	const QPointF &start3 = createPoint(end, thickness, NorthEast);
	const QPointF &end3 = createPoint(end, thickness, SouthEast);
	const QPointF &cp31 = createPoint(start3, thickness / 2.0, SouthEast);
	const QPointF &cp32 = createPoint(end3, thickness / 2.0, NorthEast);

	const QPointF &end4 = createPoint(end, thickness, SouthWest);
	const QPointF &cp41 = createPoint(end3, thickness / 2.0, SouthWest);
	const QPointF &cp42 = createPoint(end4, thickness / 2.0, SouthEast);

	QPainterPath path(start1);
	path.cubicTo(cp11, cp12, end1);
	path.cubicTo(cp21, cp22, end2);
	path.lineTo(start3);
	path.cubicTo(cp31, cp32, end3);
	path.cubicTo(cp41, cp42, end4);

	return path;
}
