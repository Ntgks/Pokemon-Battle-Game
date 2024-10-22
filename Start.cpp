#include "Start.h"
#include "sgg/graphics.h"
#include "define.h"
#include <string>

Start::Start()
{
}

void Start::draw()
{
	graphics::Brush br;
	br.outline_opacity = 0.0f;
	if (s_highlighted) {
		br.outline_opacity = 0.0f;
		br.texture = ASSET_PATH + std::string("pokeball.png");
		graphics::drawRect(s_pos[0] * 0.8f / 1.0f, s_pos[1] * 1.05f, POKEBALL_LOGO, POKEBALL_LOGO, br);
	}
	//SETCOLOR(br.fill_color, p_color[0], p_color[1], p_color[2]);
	br.texture = ASSET_PATH + std::string("play_button1.png");
	graphics::drawRect(s_pos[0], s_pos[1], PLAY_BUTTON_SIZE, PLAY_BUTTON_SIZE, br);
}

void Start::update()
{
}

bool Start::contains(float x, float y)
{
	return distance(x, y, s_pos[0], s_pos[1]) < PLAY_BUTTON_SIZE * 0.4f;
}