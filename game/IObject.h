#ifndef IOBJECT_H
#define IOBJECT_H

#include "IDrawable.h"

class IDeferredDrawable : public IDrawable
{
	public:
		virtual int order() = 0;
};

#endif // IOBJECT_H
