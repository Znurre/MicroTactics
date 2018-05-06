#ifndef IDRAWABLE_H
#define IDRAWABLE_H

#include <QPainter>

class IDrawable
{
	public:
		virtual ~IDrawable() = default;

		virtual void draw(QPainter &painter) = 0;
};

#endif // IDRAWABLE_H
