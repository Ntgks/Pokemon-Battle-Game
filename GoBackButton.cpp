#include "GoBackButton.h"
#include "sgg/graphics.h"
#include "define.h"
#include <string>

void GoBackButton::draw()
{
	graphics::Brush br;
	br.outline_opacity = 0.0f;
	if (gb_highlighted)
	{
		br.texture = ASSET_PATH + std::string("pokeball.png");
		graphics::drawRect(CANVAS_WIDTH /2.5f, CANVAS_HEIGHT/2, POKEBALL_LOGO, POKEBALL_LOGO, br);
	}
	br.texture = ASSET_PATH + std::string("GoBackButton.png");
	graphics::drawRect(gb[0], gb[1], GO_BACK_BUTTON, GO_BACK_BUTTON, br);
}


bool GoBackButton::contains(float x, float y)
{
	return distance(x, y, gb[0], gb[1]) < GO_BACK_BUTTON * 0.4f;
}


