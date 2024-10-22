#pragma once
#include "sgg/graphics.h"
#include "define.h"
#include <string>
class Pokemon_Button
{

	float pb_pos[2];
	bool pb_highlighted = false;


public:
	void draw();
	void setposx(float x) { pb_pos[0] = x; }
	void setposy(float y) { pb_pos[1] = y; }
	float returnposx() { return pb_pos[0]; }
	float returnposy() { return pb_pos[1]; }
	void SetHighlighted(bool h) { pb_highlighted = h; }
	bool ReturnHighlighted() { return pb_highlighted; }
	bool contains(float x, float y);
};