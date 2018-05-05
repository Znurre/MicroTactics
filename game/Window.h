#ifndef WINDOW_H
#define WINDOW_H

#include "Board.h"
#include "KeyInputHandler.h"
#include "PlayerHandler.h"
#include "PlayerTurnHandler.h"

#include <QOpenGLWindow>
#include <QOpenGLExtraFunctions>
#include <QRasterWindow>

class Window : public QRasterWindow
{
	public:
		Window();

	private:
		void keyReleaseEvent(QKeyEvent *event) override;
		void paintEvent(QPaintEvent *event) override;

		PlayerHandler m_playerHandler;
		PlayerTurnHandler m_playerTurnHandler;
		KeyInputHandler m_keyInputHandler;
		Board m_board;
};

#endif // WINDOW_H
