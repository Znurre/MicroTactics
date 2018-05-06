#ifndef ICHARACTERPROPERTIES_H
#define ICHARACTERPROPERTIES_H

class ICharacterProperties
{
	public:
		virtual int rotation() const = 0;
		virtual int x() const = 0;
		virtual int y() const = 0;
};

#endif // ICHARACTERPROPERTIES_H
