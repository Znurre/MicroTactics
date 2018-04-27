#ifndef KEYINPUTHANDLERTESTS_H
#define KEYINPUTHANDLERTESTS_H

#include <QObject>
#include <QTest>
#include <QDebug>

#include <Magnum/Platform/Sdl2Application.h>

#include "IPlayerTurnHandler.h"
#include "KeyInputHandler.h"
#include "Player.h"

#include "fakeit.hpp"

using namespace Magnum;
using namespace fakeit;

class KeyInputHandlerTests : public QObject
{
	Q_OBJECT

	private slots:
		void init()
		{
			When(Method(m_playerTurnHandlerMock, current)).Return(m_playerMock.get());
			Fake(Method(m_playerTurnHandlerMock, next));

			Fake(Method(m_playerMock, advance));
			Fake(Method(m_playerMock, retreat));
			Fake(Method(m_playerMock, rotate));
			Fake(Method(m_playerMock, shoot));
			Fake(Method(m_playerMock, melee));
		}

		void shouldBeAbleToAdvance()
		{
			KeyInputHandler keyInputHandler(m_playerTurnHandlerMock.get());

			keyInputHandler.onKeyPress(Platform::Sdl2Application::KeyEvent::Key::W);

			Verify(Method(m_playerMock, advance) + Method(m_playerTurnHandlerMock, next));
		}

		void shouldBeAbleToRetreat()
		{
			KeyInputHandler keyInputHandler(m_playerTurnHandlerMock.get());

			keyInputHandler.onKeyPress(Platform::Sdl2Application::KeyEvent::Key::S);

			Verify(Method(m_playerMock, retreat) + Method(m_playerTurnHandlerMock, next));
		}

		void shouldBeAbleToRotateRight()
		{
			KeyInputHandler keyInputHandler(m_playerTurnHandlerMock.get());

			keyInputHandler.onKeyPress(Platform::Sdl2Application::KeyEvent::Key::D);

			Verify(Method(m_playerMock, rotate).Using(1) + Method(m_playerTurnHandlerMock, next));
		}

		void shouldBeAbleToRotateLeft()
		{
			KeyInputHandler keyInputHandler(m_playerTurnHandlerMock.get());

			keyInputHandler.onKeyPress(Platform::Sdl2Application::KeyEvent::Key::A);

			Verify(Method(m_playerMock, rotate).Using(-1) + Method(m_playerTurnHandlerMock, next));
		}

		void shouldBeAbleToShoot()
		{
			KeyInputHandler keyInputHandler(m_playerTurnHandlerMock.get());

			keyInputHandler.onKeyPress(Platform::Sdl2Application::KeyEvent::Key::Q);

			Verify(Method(m_playerMock, shoot) + Method(m_playerTurnHandlerMock, next));
		}

		void shouldBeAbleToUseMelee()
		{
			KeyInputHandler keyInputHandler(m_playerTurnHandlerMock.get());

			keyInputHandler.onKeyPress(Platform::Sdl2Application::KeyEvent::Key::E);

			Verify(Method(m_playerMock, melee) + Method(m_playerTurnHandlerMock, next));
		}

	private:
		Mock<IPlayerTurnHandler> m_playerTurnHandlerMock;
		Mock<IPlayer> m_playerMock;
};

#endif // KEYINPUTHANDLERTESTS_H
