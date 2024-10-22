#pragma once
#include "define.h"
#include "sgg/graphics.h"
#include <string>
class BackgroundForSwitchingPokemons
{

	float bfsp_pos[2];

public:
	void draw();
	void setposx(float x) { bfsp_pos[0] = x; }
	void setposy(float y) { bfsp_pos[1] = y; }
};