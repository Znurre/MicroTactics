#ifndef CHARACTER_H
#define CHARACTER_H

#include "IDrawable.h"
#include "Turret.h"
#include "Palette1.h"
#include "CuteFaceTemplate.h"

class Character : public IDrawable
{
	public:
		Character(ICharacterProperties &properties);

		void draw(QPainter &painter) override;

	private:
		QImage selectImage() const;

		ICharacterProperties &m_properties;
		Palette1 m_palette;
		CuteFaceTemplate m_faceTemplate;
		Turret m_turret;
};

#endif // CHARACTER_H
