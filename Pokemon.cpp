#include <string>
using namespace std;
#include "Pokemon.h"
#include "sgg/graphics.h"
#include "define.h"
#include <iostream>


Pokemon::Pokemon() {}
Pokemon::Pokemon(int hp, int def, int att, int speed, string name, string type1, string type2, Move* m1, Move* m2, Move* m3, Move* m4, string photo_front, string photo_back, int id) {
	HP = hp;
	DEF = def;
	ATT = att;
	SPEED = speed;
	NAME = name;
	TYPE1 = type1;
	TYPE2 = type2;
	PHOTO_FRONT = photo_front;
	PHOTO_BACK = photo_back;
	ID = id;
	Static_Hp = hp;
}

void Pokemon::applydamage(int dmg) {
	HP -= dmg;
	if (HP < 0) {
		HP = 0;
	}
}

int Pokemon::getHP() {
	return HP;
}

string Pokemon::getName() {
	return NAME;
}
int Pokemon::getDef() {
	return DEF;
}

int Pokemon::getAtt() {
	return ATT;
}
int Pokemon::getSpeed() {
	return SPEED;
}
string Pokemon::getType1() {
	return TYPE1;
}
string Pokemon::getType2() {
	return TYPE2;
}
string Pokemon::draw_front()
{
	return PHOTO_FRONT + ".png";
}

string Pokemon::draw_back()
{
	return PHOTO_BACK + ".png";
}

int Pokemon::ReturnId()
{
	return ID;
}

void Pokemon::Moves(Move* m1, Move* m2, Move* m3, Move* m4)
{
	moves.push_back(m1);
	moves.push_back(m2);
	moves.push_back(m3);
	moves.push_back(m4);
}

Move* Pokemon::ReturnMove1()
{
	int i = 0;
	for (auto move : moves)
	{
		if (i == 0)
		{
			return move;
			i = i + 1;
		}
		else {
			i = i + 1;
		}
	}
}

Move* Pokemon::ReturnMove2()
{
	int i = 0;
	for (auto move : moves)
	{
		if (i == 1)
		{
			return move;
			i = i + 1;
		}
		else {
			i = i + 1;
		}
	}
}

Move* Pokemon::ReturnMove3()
{
	int i = 0;
	for (auto move : moves)
	{
		if (i == 2)
		{
			return move;
			i = i + 1;
		}
		else {
			i = i + 1;
		}
	}
}

Move* Pokemon::ReturnMove4()
{
	int i = 0;
	for (auto move : moves)
	{
		if (i == 3)
		{
			return move;
			i = i + 1;
		}
		else {
			i = i + 1;
		}
	}
}

void Pokemon::drawminifigure(Pokemon* Pokemon)
{
	graphics::Brush br;
	br.outline_opacity = 0.0f;
	if (getName() == Pokemon->getName())
	{
		if (p_alive == false)
		{
			SETCOLOR(br.fill_color, 0.0f, 0.0f, 0.0f)
		}
		br.texture = ASSET_PATH + std::string(draw_front());
		graphics::drawRect(minifigure_pos[0], minifigure_pos[1], BENCH_MINI_FIGURE, BENCH_MINI_FIGURE, br);

	}
	else if (getName() != Pokemon->getName() && ValueDone == true)
	{
		if (p_alive == false)
		{
			SETCOLOR(br.fill_color, 0.0f, 0.0f, 0.0f);
			br.texture = ASSET_PATH + std::string(draw_front());
			graphics::drawRect(minifigure_pos[0], minifigure_pos[1], MINI_SIZE, MINI_SIZE, br);
		}
		else {
			if (minifigure_highlighted == true)
			{
				br.texture = ASSET_PATH + std::string("pokeball.png");
				graphics::drawRect(CANVAS_WIDTH / 14.5f, CANVAS_HEIGHT / 2, POKEBALL_LOGO, POKEBALL_LOGO, br);
			}
			br.texture = ASSET_PATH + std::string(draw_front());
			graphics::drawRect(minifigure_pos[0], minifigure_pos[1], MINI_SIZE, MINI_SIZE, br);
		}
	}
	else if (getName() != Pokemon->getName() && ValueDone == false)
	{
		if (p_alive == false)
		{
			SETCOLOR(br.fill_color, 0.0f, 0.0f, 0.0f);
			br.texture = ASSET_PATH + std::string(draw_front());
			graphics::drawRect(minifigure_pos[0], minifigure_pos[1], MINI_SIZE, MINI_SIZE, br);
		}
		else
		{
			if (minifigure_highlighted == true)
			{
				br.texture = ASSET_PATH + std::string("pokeball.png");
				graphics::drawRect(CANVAS_WIDTH / 1.5f, CANVAS_HEIGHT / 2, POKEBALL_LOGO, POKEBALL_LOGO, br);
			}
			br.texture = ASSET_PATH + std::string(draw_front());
			graphics::drawRect(minifigure_pos[0], minifigure_pos[1], MINI_SIZE, MINI_SIZE, br);
		}
	}
}

bool Pokemon::contains(float x, float y)
{
	return distance(x, y, minifigure_pos[0], minifigure_pos[1]) < MINI_SIZE * 0.4f;
}

void Pokemon::switchPokemonsPos(Pokemon* Pokemon)
{
	float tempx = minifigure_pos[0];
	float tempy = minifigure_pos[1];
	setposxforminifigure(Pokemon->returnposxforminifigure());
	setposyforminifigure(Pokemon->returnposyforminifigure());
	Pokemon->setposxforminifigure(tempx);
	Pokemon->setposyforminifigure(tempy);
}

string Pokemon::ReturnHp()
{
	std::string hp = std::to_string(HP);
	return hp;

}

void Pokemon::ReduceHP(int a)
{
	HP = HP - a;
	if (HP < 0)
	{
		HP = 0;
	}
}

string Pokemon::ReturnStaticHp()
{
	std::string hp = std::to_string(Static_Hp);
	return hp;
}
