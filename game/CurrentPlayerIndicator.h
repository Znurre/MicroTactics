#ifndef CURRENTPLAYERINDICATOR_H
#define CURRENTPLAYERINDICATOR_H

#include "IDrawable.h"

class IPlayerTurnHandler;

class CurrentPlayerIndicator : public IDrawable
{
	public:
		CurrentPlayerIndicator(IPlayerTurnHandler &playerTurnHandler);

		void draw(QPainter &painter) override;

		int order() const override;

	private:
		IPlayerTurnHandler &m_playerTurnHandler;
};

#endif // CURRENTPLAYERINDICATOR_H
