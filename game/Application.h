#ifndef APPLICATION_H
#define APPLICATION_H

#include "Board.h"
#include "KeyInputHandler.h"
#include "PlayerHandler.h"
#include "PlayerTurnHandler.h"

#include <Magnum/DefaultFramebuffer.h>
#include <Magnum/Platform/Sdl2Application.h>

#include <Magnum/Context.h>
#include <Magnum/Renderer.h>
#include <Magnum/Version.h>
#include <Magnum/Math/Color.h>
#include <Magnum/Buffer.h>
#include <Magnum/Mesh.h>
#include <Magnum/Shader.h>

#include <Magnum/Shaders/VertexColor.h>

using namespace Magnum::Math::Literals;
using namespace Magnum;

class Application : public Platform::Application
{
	public:
		Application(const Arguments &arguments);

	private:
		void drawEvent() override;
		void keyReleaseEvent(KeyEvent &event) override;

		Buffer m_buffer;
		Mesh m_mesh;
		MyShader m_shader;
		PlayerHandler m_playerHandler;
		PlayerTurnHandler m_playerTurnHandler;
		KeyInputHandler m_keyInputHandler;
		Board m_board;
};

#endif // APPLICATION_H
