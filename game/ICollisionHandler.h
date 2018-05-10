#ifndef ICOLLISIONHANDLER_H
#define ICOLLISIONHANDLER_H

class ICollisionHandler
{
	public:
		virtual bool isCollidable(int x, int y) const = 0;
};

#endif // ICOLLISIONHANDLER_H
