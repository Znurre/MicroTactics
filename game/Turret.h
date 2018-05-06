#ifndef TURRET_H
#define TURRET_H

#include "IDrawable.h"

class IPalette;
class ICharacterProperties;

class Turret : public IDrawable
{
	public:
		Turret(ICharacterProperties &properties, IPalette &palette);

		void draw(QPainter &painter) override;

	private:
		QPointF createPoint(const QPointF &point, double radius, double angle) const;
		QPainterPath createPath(const QRectF &source, double length) const;

		ICharacterProperties &m_properties;
		IPalette &m_palette;
};
#endif // TURRET_H
