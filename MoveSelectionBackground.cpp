#include "MoveSelectionBackground.h"

void MoveSelectionBackground::draw()
{
	graphics::Brush br;
	br.outline_opacity = 0.0f;
	br.texture = ASSET_PATH + std::string("move_selection.png");
	graphics::drawRect(b_pos[0], b_pos[1], CANVAS_WIDTH, CANVAS_HEIGHT, br);
}
