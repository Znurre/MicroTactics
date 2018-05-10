#ifndef IPLAYER_H
#define IPLAYER_H

#include "ICharacterProperties.h"

class IPlayer : public ICharacterProperties
{
	public:
		virtual void rotate(int direction) = 0;
		virtual void damage() = 0;
		virtual void advance() = 0;
		virtual void retreat() = 0;
		virtual void shoot() = 0;
		virtual void melee() = 0;
};

#endif // IPLAYER_H
