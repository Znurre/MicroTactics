#ifndef PALETTE1_H
#define PALETTE1_H

#include "IPalette.h"

class Palette1 : public IPalette
{
	public:
		const QColor *brows() const override;
		const QColor *eye() const override;
		const QColor *iris() const override;
		const QColor *blush() const override;
		const QColor *lips() const override;
};

#endif // PALETTE1_H
