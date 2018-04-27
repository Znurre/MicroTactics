#include "Application.h"

Application::Application(const Platform::Sdl2Application::Arguments &arguments)
	: Platform::Application(arguments, Configuration().setTitle("foo"))
	, m_playerTurnHandler(m_playerHandler)
	, m_keyInputHandler(m_playerTurnHandler)
{
	static const Vector3 data[]
	{
		{ -0.5f, -0.5f, -0.5f },
		{  0.5f, -0.5f, -0.5f },
		{  0.5f, 0.5f, -0.5f }
	};

	m_buffer
		.setData(data, BufferUsage::StaticDraw);

	m_mesh
		.setPrimitive(MeshPrimitive::Triangles)
		.setCount(3)
		.addVertexBuffer(m_buffer, 0, MyShader::Position());
}

void Application::drawEvent()
{
	defaultFramebuffer.clear(FramebufferClear::Color);

	m_board.draw();

	m_shader.setColor(0xff0000_rgbf);
	m_mesh.draw(m_shader);

	swapBuffers();
}

void Application::keyReleaseEvent(Platform::Sdl2Application::KeyEvent &event)
{
//	m_keyInputHandler.onKeyPress(event.key());
}
