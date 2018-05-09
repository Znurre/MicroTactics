#ifndef CHARACTER_H
#define CHARACTER_H

#include "IDrawable.h"
#include "Palette1.h"
#include "CuteFaceTemplate.h"
#include "ISceneNode.h"
#include "ICharacterProperties.h"

class Character : public ISceneNode, public IDrawable
{
	public:
		Character(ICharacterProperties &properties);

		void iterate(ISceneNodeCallback &callback) override;
		void draw(QPainter &painter) override;

		int order() const override;

	private:
		QImage selectImage() const;

		ICharacterProperties &m_properties;
		Palette1 m_palette;
		CuteFaceTemplate m_faceTemplate;
};

#endif // CHARACTER_H
