#include "ContinueButton.h"
#include "sgg/graphics.h"
#include "define.h"
#include <string>
void ContinueButton::draw()
{
	graphics::Brush br;
	br.outline_opacity = 0.0f;
	if (cb_highlighted)
	{
		br.texture = ASSET_PATH + std::string("pokeball.png");
		graphics::drawRect(cb[0] * 0.9f / 1.0f, cb[1] * 1.0f, POKEBALL_LOGO, POKEBALL_LOGO, br);
	}
	br.texture = ASSET_PATH + std::string("ContinueButton.png");
	graphics::drawRect(cb[0], cb[1], CONTINUE_BUTTON_SIZE, CONTINUE_BUTTON_SIZE, br);
}

bool ContinueButton::contains(float x, float y)
{
	return distance(x, y, cb[0], cb[1]) < FIGHT_BUTTON * 0.4f;
}