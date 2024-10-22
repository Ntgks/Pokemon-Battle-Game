#include "VictoryBackground.h"

void VictoryBackground::draw()
{
	graphics::Brush br;
	br.outline_opacity = 0.0f;
	br.texture = ASSET_PATH + std::string("Victory.png");
	graphics::drawRect(vb[0], vb[1], CANVAS_WIDTH, CANVAS_HEIGHT, br);
}
