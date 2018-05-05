#ifndef IDRAWABLE_H
#define IDRAWABLE_H

class IDrawable
{
	public:
		virtual ~IDrawable() = default;

		virtual void draw() = 0;
};

#endif // IDRAWABLE_H
