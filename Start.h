#pragma once
class Start
{

	float s_pos[2];
	bool s_highlighted = false;
	bool s_active = false;

public:
	Start();
	void draw();
	void update();
	float returnposx() { return s_pos[0]; }
	float returnposy() { return s_pos[1]; }
	void setposx(float x) { s_pos[0] = x; }
	void setposy(float y) { s_pos[1] = y; }

	void setHighlighted(bool h) { s_highlighted = h; }
	bool ReturnHighlighted() { return s_highlighted; }
	bool contains(float x, float y);

};
