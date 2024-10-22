#pragma once
#include "define.h"
#include "sgg/graphics.h"
#include <string>
class MoveSelectionBackground
{
	float b_pos[2];


public:
	void draw();
	void setposx(float x) { b_pos[0] = x; }
	void setposy(float y) { b_pos[1] = y; }
};