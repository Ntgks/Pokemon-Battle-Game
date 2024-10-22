#include "Pokemon_Button.h"

void Pokemon_Button::draw()
{
	graphics::Brush br;
	br.outline_opacity = 0.0f;
	if (pb_highlighted)
	{
		br.texture = ASSET_PATH + std::string("pokeball.png");
		graphics::drawRect(CANVAS_WIDTH / 2.6f, CANVAS_HEIGHT * 0.84f, POKEBALL_LOGO, POKEBALL_LOGO, br);
	}
	br.texture = ASSET_PATH + std::string("Pokemon_button.png");
	graphics::drawRect(pb_pos[0], pb_pos[1], POKEMON_BUTTON, POKEMON_BUTTON, br);
}

bool Pokemon_Button::contains(float x, float y)
{
	return distance(x, y, pb_pos[0], pb_pos[1]) < POKEMON_BUTTON * 0.4f;
}
