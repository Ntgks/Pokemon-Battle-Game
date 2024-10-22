#include "Fight.h"
#include "sgg/graphics.h"
#include "define.h"
#include <string>

void Fight::draw()
{
	graphics::Brush br;
	br.outline_opacity = 0.0f;
	if (f_highlighted)
	{
		br.texture = ASSET_PATH + std::string("pokeball.png");
		graphics::drawRect(f_pos[0] * 0.9f / 1.0f, f_pos[1] * 1.0f, POKEBALL_LOGO, POKEBALL_LOGO, br);
	}
	br.texture = ASSET_PATH + std::string("fight_button.png");
	graphics::drawRect(f_pos[0], f_pos[1], FIGHT_BUTTON, FIGHT_BUTTON, br);
}

bool Fight::contains(float x, float y)
{
	return distance(x, y, f_pos[0], f_pos[1]) < FIGHT_BUTTON * 0.4f;
}
