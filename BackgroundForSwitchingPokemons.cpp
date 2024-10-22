#include "BackgroundForSwitchingPokemons.h"

void BackgroundForSwitchingPokemons::draw()
{
	graphics::Brush br;
	br.outline_opacity = 0.0f;
	br.texture = ASSET_PATH + std::string("Background_for_switching_pokemons.png");
	graphics::drawRect(bfsp_pos[0], bfsp_pos[1], CANVAS_WIDTH, CANVAS_HEIGHT, br);
}
