#ifndef PLAYER_H
#define PLAYER_H

#include <cmath>

#include <QtMath>

#include "IPlayer.h"
#include "Character.h"

class ICollisionHandler;
class IPlayerHandler;

class Player : public IPlayer
{
	public:
		Player(ICollisionHandler &collisionHandler, IPlayerHandler &playerHandler);

		int health() const;
		int rotation() const override;
		int x() const override;
		int y() const override;

		void rotate(int direction) override;
		void damage();

		void advance() override;
		void retreat() override;
		void shoot() override;
		void melee() override;

		void iterate(ISceneNodeCallback &callback) override;

	private:
		ICollisionHandler &m_collisionHandler;
		IPlayerHandler &m_playerHandler;

		Character m_character;

		int m_health;
		int m_rotation;
		int m_x;
		int m_y;
};

#endif // PLAYER_H
