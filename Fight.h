#pragma once
class Fight
{
	float f_pos[2];
	bool f_highlighted = false;
public:
	void draw();
	float returnposx() { return f_pos[0]; }
	float returnposy() { return f_pos[1]; }
	void setposx(float x) { f_pos[0] = x; }
	void setposy(float y) { f_pos[1] = y; }
	void SetHighlighted(bool h) { f_highlighted = h; }
	bool ReturnHighlighted() { return f_highlighted; }
	bool contains(float x, float y);


};