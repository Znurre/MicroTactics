#ifndef IFACETEMPLATE_H
#define IFACETEMPLATE_H

#include <QColor>

using FaceDefinition = const QColor *[8][8];

class IPalette;

class IFaceTemplate
{
	public:
		virtual void apply(FaceDefinition &definition, const IPalette &palette) = 0;
};

#endif // IFACETEMPLATE_H
