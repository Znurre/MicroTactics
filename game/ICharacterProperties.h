#ifndef ICHARACTERPROPERTIES_H
#define ICHARACTERPROPERTIES_H

#include "ISceneNode.h"

class ICharacterProperties : public ISceneNode
{
	public:
		virtual int health() const = 0;
		virtual int rotation() const = 0;
		virtual int x() const = 0;
		virtual int y() const = 0;
		virtual int id() const = 0;
};

#endif // ICHARACTERPROPERTIES_H
