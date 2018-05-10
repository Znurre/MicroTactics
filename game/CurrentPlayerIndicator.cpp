#include "CurrentPlayerIndicator.h"
#include "IPlayerTurnHandler.h"
#include "IPlayer.h"

CurrentPlayerIndicator::CurrentPlayerIndicator(IPlayerTurnHandler &playerTurnHandler)
	: m_playerTurnHandler(playerTurnHandler)
{
}

void CurrentPlayerIndicator::draw(QPainter &painter)
{
	IPlayer &player = m_playerTurnHandler.current();

	const int width = 139;
	const int height = 160;

	const int x = player.x() * (width / 2) - player.y() * (width / 2);
	const int y = player.x() * (height / 4) + player.y() * (height / 4);

	painter.setBrush(QColor("red"));
	painter.drawEllipse(x + (width / 2) - 5, -y + (height / 2) - 5, 10, 10);
}

int CurrentPlayerIndicator::order() const
{
	return 1000;
}
