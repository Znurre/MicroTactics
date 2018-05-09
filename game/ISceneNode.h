#ifndef ISCENENODE_H
#define ISCENENODE_H

#include <QMap>

#include "IDrawable.h"

class ISceneNode;

class ISceneNodeCallback
{
	public:
		virtual ~ISceneNodeCallback() = default;

		virtual void node(ISceneNode *node) = 0;
};

class ISceneNode
{
	public:
		virtual void iterate(ISceneNodeCallback &callback) = 0;
};

class DrawableCallback : public ISceneNodeCallback
{
	public:
		void node(ISceneNode *node) override
		{
			IDrawable *drawable = dynamic_cast<IDrawable *>(node);

			if (drawable)
			{
				const int order = drawable->order();

				m_drawables.insertMulti(order, drawable);
			}
		}

		void drawDeferred(QPainter &painter)
		{
			for (IDrawable *drawable : m_drawables)
			{
				drawable->draw(painter);
			}
		}

	private:
		QMap<int, IDrawable *> m_drawables;
};

#endif // ISCENENODE_H
