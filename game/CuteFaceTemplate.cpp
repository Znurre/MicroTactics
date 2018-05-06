#include "CuteFaceTemplate.h"
#include "IPalette.h"

void CuteFaceTemplate::apply(FaceDefinition &definition, const IPalette &palette)
{
	// brow 1
	definition[1][1] = palette.brows();
	definition[1][2] = palette.brows();

	// brow 2
	definition[1][5] = palette.brows();
	definition[1][6] = palette.brows();

	// eye 1
	definition[2][1] = palette.eye();
	definition[2][2] = palette.eye();
	definition[3][1] = palette.eye();
	definition[3][2] = palette.iris();
	definition[4][1] = palette.eye();
	definition[4][2] = palette.iris();

	// eye 2
	definition[2][5] = palette.eye();
	definition[2][6] = palette.eye();
	definition[3][5] = palette.iris();
	definition[3][6] = palette.eye();
	definition[4][5] = palette.iris();
	definition[4][6] = palette.eye();

	// blush 1
	definition[5][1] = palette.blush();

	// blush 2
	definition[5][6] = palette.blush();

	// lips
	definition[6][3] = palette.lips();
	definition[6][4] = palette.lips();
}
