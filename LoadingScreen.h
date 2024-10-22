#pragma once
class LoadingScreen
{


	float l_pos[2];

public:
	void draw();
	void update();

	float getPosX() { return l_pos[0]; }
	float getPosY() { return l_pos[1]; }
	void setPosX(float x) { l_pos[0] = x; }
	void setPosY(float y) { l_pos[1] = y; }
};