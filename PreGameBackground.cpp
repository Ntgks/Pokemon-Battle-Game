#include "PreGameBackground.h"
#include "sgg/graphics.h"
#include "define.h"
#include <string>

void PreGameBackground::draw()
{
	graphics::Brush br;
	br.outline_opacity = 0.0f;
	br.texture = ASSET_PATH + std::string("Screenshot_1.png");
	graphics::drawRect(b_pos[0], b_pos[1], CANVAS_WIDTH, CANVAS_HEIGHT, br);
}

void PreGameBackground::update()
{
}