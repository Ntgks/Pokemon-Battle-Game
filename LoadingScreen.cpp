#include "LoadingScreen.h"
#include "define.h"
#include "sgg/graphics.h"
#include <string>

void LoadingScreen::draw()
{


	graphics::Brush br;
	br.outline_opacity = 0.0f;
	br.texture = ASSET_PATH + std::string("Loading.png");
	graphics::drawRect(l_pos[0], l_pos[1], CANVAS_WIDTH, CANVAS_HEIGHT, br);

}
