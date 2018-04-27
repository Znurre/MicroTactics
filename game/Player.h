#ifndef PLAYER_H
#define PLAYER_H

#include <cmath>

#include "IPlayer.h"

class Player : public IPlayer
{
	public:
		Player()
			: m_rotation(0)
			, m_x(0)
			, m_y(0)
		{
		}

		int rotation() const override
		{
			return m_rotation;
		}

		int x() const override
		{
			return m_x;
		}

		int y() const override
		{
			return m_y;
		}

		void rotate(int direction) override
		{
			m_rotation = ((m_rotation + direction) % 4 + 4) % 4;
		}

		void advance() override
		{
			m_x += sin(m_rotation * M_PI / 2);
			m_y -= cos(m_rotation * M_PI / 2);
		}

		void retreat() override
		{
			m_x -= sin(m_rotation * M_PI / 2);
			m_y += cos(m_rotation * M_PI / 2);
		}

		void shoot() override
		{

		}

		void melee() override
		{

		}

	private:
		int m_rotation;
		int m_x;
		int m_y;
};

#endif // PLAYER_H
