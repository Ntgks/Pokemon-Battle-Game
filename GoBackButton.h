#pragma once
class GoBackButton
{
	float gb[2];
	bool gb_highlighted;


public:
	void draw();
	void setposx(float x) { gb[0] = x; }
	void setposy(float y) { gb[1] = y; }

	void setHighlighted(bool h) { gb_highlighted = h; }
	bool ReturnHighlithed() { return gb_highlighted; }
	bool contains(float x, float y);

};