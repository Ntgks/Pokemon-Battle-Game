#pragma once
class ContinueButton
{
	float cb[2];
	bool cb_highlighted = false;

public:
	void draw();
	void Setposx(float x) { cb[0] = x; }
	void Setposy(float y) { cb[1] = y; }
	void SetHighlighted(bool h) { cb_highlighted = h; }
	bool ReturnHighlighted() { return cb_highlighted; }
	bool contains(float x, float y);







};