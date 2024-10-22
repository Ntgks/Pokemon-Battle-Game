#pragma once
#include "define.h"
#include "sgg/graphics.h"
#include <string>
class VictoryBackground
{

	float vb[2];

public:
	void draw();
	void setposx(float x) { vb[0] = x; }
	void setposy(float y) { vb[1] = y; }



};
