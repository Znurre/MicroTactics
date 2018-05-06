#include "Palette1.h"

const QColor *Palette1::brows() const
{
	static const QColor brows("#374845");

	return &brows;
}

const QColor *Palette1::eye() const
{
	static const QColor eye("white");

	return &eye;
}

const QColor *Palette1::iris() const
{
	static const QColor iris("#87cdde");

	return &iris;
}

const QColor *Palette1::blush() const
{
	static const QColor blush("#ffaaee");

	return &blush;
}

const QColor *Palette1::lips() const
{
	static const QColor lips("#ff5555");

	return &lips;
}
