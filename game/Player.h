#ifndef PLAYER_H
#define PLAYER_H

#include <cmath>

#include <QtMath>

#include "IPlayer.h"
#include "ICharacterProperties.h"
#include "Character.h"

class Player
	: public IPlayer
	, public ICharacterProperties
{
	public:
		Player();

		int rotation() const override;
		int x() const override;
		int y() const override;

		void rotate(int direction) override;

		void advance() override;
		void retreat() override;
		void shoot() override;
		void melee() override;

		void draw(QPainter &painter) override;

	private:
		Character m_character;

		int m_rotation;
		int m_x;
		int m_y;
};

#endif // PLAYER_H
