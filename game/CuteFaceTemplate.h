#ifndef CUTEFACETEMPLATE_H
#define CUTEFACETEMPLATE_H

#include "IFaceTemplate.h"

class CuteFaceTemplate : public IFaceTemplate
{
	public:
		void apply(FaceDefinition &definition, const IPalette &palette) override;
};

#endif // CUTEFACETEMPLATE_H
