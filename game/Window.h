#ifndef WINDOW_H
#define WINDOW_H

#include "Board.h"
#include "KeyInputHandler.h"
#include "PlayerHandler.h"
#include "PlayerTurnHandler.h"

#include <QRasterWindow>
#include <QElapsedTimer>
#include <QOpenGLWindow>

class Window : public QOpenGLWindow
{
	public:
		Window();

	private:
		void keyPressEvent(QKeyEvent *event) override;
		void paintEvent(QPaintEvent *event) override;

		QElapsedTimer m_timer;

		PlayerHandler m_playerHandler;
		PlayerTurnHandler m_playerTurnHandler;
		KeyInputHandler m_keyInputHandler;
		Board m_board;

		long m_elapsed;
		long m_fps;
};

#endif // WINDOW_H
