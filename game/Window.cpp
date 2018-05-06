#include <QPainter>
#include <QtMath>
#include <QDebug>

#include "Turret.h"
#include "Window.h"
#include "CuteFaceTemplate.h"
#include "Palette1.h"

Window::Window()
	: m_playerTurnHandler(m_playerHandler)
	, m_keyInputHandler(m_playerTurnHandler)
	, m_elapsed(0)
	, m_fps(0)
{
	m_timer.start();
}

void Window::keyPressEvent(QKeyEvent *event)
{
	if (event->isAutoRepeat())
	{
		return;
	}

	m_keyInputHandler.onKeyPress(event->key());
}

void Window::paintEvent(QPaintEvent *event)
{
	Q_UNUSED(event);

	m_fps++;

	if (m_timer.elapsed())
	{
		const long delta = m_timer.restart();

		if ((m_elapsed += delta) >= 1000)
		{
			qDebug() << "FPS" << m_fps;

			m_fps = 0;
			m_elapsed = 0;
		}
	}

	glClear(GL_COLOR_BUFFER_BIT);

	QPainter painter(this);
	painter.translate(500, 500);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.setPen(Qt::NoPen);

	m_board.draw(painter);

	for (int i = 0; i < m_playerHandler.playerCount(); i++)
	{
		IPlayer &player = m_playerHandler.player(i);

		player.draw(painter);
	}

	update();
}
