#ifndef PLAYERHANDLERTESTS_H
#define PLAYERHANDLERTESTS_H

#include <QObject>

#include "fakeit.hpp"

#include "PlayerHandler.h"
#include "ICollisionHandler.h"
#include "IMapHandler.h"

using namespace fakeit;

class PlayerHandlerTests : public QObject
{
	Q_OBJECT

	public:
		PlayerHandlerTests()
			: m_playerHandler(m_collisionHandlerMock.get(), m_mapHandlerMock.get())
		{
		}

	public slots:
		void shouldBeAbleToGetPlayerInDirection_1()
		{
		}

	private:
		Mock<ICollisionHandler> m_collisionHandlerMock;
		Mock<IMapHandler> m_mapHandlerMock;

		PlayerHandler m_playerHandler;
};

#endif // PLAYERHANDLERTESTS_H
