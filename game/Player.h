#ifndef PLAYER_H
#define PLAYER_H

#include <cmath>

#include <QtMath>

#include "IPlayer.h"
#include "Character.h"

class ICollisionHandler;
class IPlayerTurnHandler;
class IPlayerProvider;
class IMapHandler;

class Player : public IPlayer
{
	public:
		Player(int id, ICollisionHandler &collisionHandler, IMapHandler &mapHandler, IPlayerProvider &playerHandler);
		~Player();

		int health() const;
		int rotation() const override;
		int x() const override;
		int y() const override;
		int id() const override;

		void rotate(int direction) override;
		void damage();

		void advance() override;
		void retreat() override;
		void shoot() override;
		void melee() override;

		void iterate(ISceneNodeCallback &callback) override;

	private:
		void ensurePosition();

		ICollisionHandler &m_collisionHandler;
		IMapHandler &m_mapHandler;
		IPlayerProvider &m_playerProvider;

		Character m_character;

		int m_id;
		int m_health;
		int m_rotation;

		int *m_x;
		int *m_y;
};

#endif // PLAYER_H
