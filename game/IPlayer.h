#ifndef IPLAYER_H
#define IPLAYER_H

class IPlayer
{
	public:
		virtual int rotation() const = 0;
		virtual int x() const = 0;
		virtual int y() const = 0;

		virtual void rotate(int direction) = 0;
		virtual void advance() = 0;
		virtual void retreat() = 0;
		virtual void shoot() = 0;
		virtual void melee() = 0;
};

#endif // IPLAYER_H
