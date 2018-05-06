#ifndef IPALETTE_H
#define IPALETTE_H

#include <QColor>

class IPalette
{
	public:
		virtual const QColor *brows() const = 0;
		virtual const QColor *eye() const = 0;
		virtual const QColor *iris() const = 0;
		virtual const QColor *blush() const = 0;
		virtual const QColor *lips() const = 0;

		QColor *none()
		{
			return nullptr;
		}
};

#endif // IPALETTE_H
