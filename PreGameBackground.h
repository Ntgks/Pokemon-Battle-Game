#pragma once
class PreGameBackground
{

	float b_pos[2];



public:
	void draw();
	void update();

	float getPosX() { return b_pos[0]; }
	float getPosY() { return b_pos[1]; }
	void setPosX(float x) { b_pos[0] = x; }
	void setPosY(float y) { b_pos[1] = y; }
};