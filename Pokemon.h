#pragma once
#pragma once
#include <string>
using namespace std;
#include "Move.h"
#include <list>
#include "define.h"
#include <iostream>


class Pokemon {
	int HP;
	int DEF;
	int ATT;
	int SPEED;
	int Static_Hp;
	string NAME;
	string TYPE1;
	string TYPE2;
	string PHOTO_FRONT;
	string PHOTO_BACK;
	int ID;
	float pok_pos[2];
	bool p_alive = true;
	std::list<Move*>moves;
	bool minifigure_highlighted = false;
	bool minifigure_active = false;

public:
	float minifigure_pos[2];
	Pokemon(int hp, int def, int att, int speed, string name, string type1, string type2, Move* m1, Move* m2, Move* m3, Move* m4, string photo_front, string photo_back, int id);
	Pokemon();
	void applydamage(int dmg);
	int getHP();
	string getName();
	int getDef();
	int getAtt();
	int getSpeed();
	string getType1();
	string getType2();
	void isalive(bool h) { p_alive = h; }
	string draw_front();
	string draw_back();
	int ReturnId();
	bool ValueDone = false;

	void Moves(Move* m1, Move* m2, Move* m3, Move* m4);
	float backposx() { return CANVAS_WIDTH * 1.6f / 4.0f; }
	float backposy() { return CANVAS_HEIGHT * 1.2f / 2.0f; }
	float frontposx() { return CANVAS_WIDTH * 2.9f / 4.0f; }
	float frontposy() { return CANVAS_HEIGHT * 0.65f / 2.0f; }
	float backposx2() { return CANVAS_WIDTH / 2; }
	float backposy2() { return CANVAS_HEIGHT / 2; }
	Move* ReturnMove1();
	Move* ReturnMove2();
	Move* ReturnMove3();
	Move* ReturnMove4();
	void setposxforminifigure(float x) { minifigure_pos[0] = x; }
	void setposyforminifigure(float y) { minifigure_pos[1] = y; }
	float returnposxforminifigure() { return minifigure_pos[0]; }
	float returnposyforminifigure() { return minifigure_pos[1]; }
	void drawminifigure(Pokemon* Pokemon);
	bool contains(float x, float y);
	void SetHighlighted(bool h) { minifigure_highlighted = h; }
	bool ReturnHighlighted() { return minifigure_highlighted; }
	void switchPokemonsPos(Pokemon* Pokemon);
	void setValueDone(bool h) { ValueDone = h; }
	bool ReturnValueDone() { return ValueDone; }
	string ReturnHp();
	void ReduceHP(int a);
	string ReturnStaticHp();
	float ReturnConstHp() { return Static_Hp; }
	bool ReturnAlive() { return p_alive; }
};
