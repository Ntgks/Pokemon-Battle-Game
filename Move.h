#pragma once
#include <string>


using namespace std;


class Move {
private:
	string TYPE;
	string NAME;
	int POWER;
	float X;
	float Y;
	bool CRITICAL = false;
	float  move_pos[2];
	bool move_highlighted = false;
public:

	Move(string name, string type, int att);
	string getName();
	string getType();
	int getpower();
	void setcritfalse();
	void setcrittrue();
	bool getcrit();
	string move_pic() { return TYPE + "_Move.png"; }
	void setposx(float x) { move_pos[0] = x; }
	void setposy(float y) { move_pos[1] = y; }
	float returnposx() { return move_pos[0]; }
	float returnposy() { return move_pos[1]; }
	void draw(int i);
	bool contains(float x, float y);
	void SetHighlighted(bool h) { move_highlighted = h; }
	bool ReturnHighlighted() { return move_highlighted; }
};