#include <string>
#include "Move.h"
#include <stdlib.h>
#include <time.h>
#include "define.h"
#include "sgg/graphics.h"
#include <iostream>
using namespace std;


Move::Move(string name, string type, int power) {
	TYPE = type;
	NAME = name;
	POWER = power;
}
string Move::getName() {
	return NAME;
}
string Move::getType() {
	return TYPE;
}
int Move::getpower() {
	return POWER;
}
void Move::setcritfalse() {
	CRITICAL = false;
}
void Move::setcrittrue() {
	CRITICAL = true;
}
bool Move::getcrit() {
	return CRITICAL;
}

void Move::draw(int i)
{
	graphics::Brush br;
	br.outline_opacity = 0.0f;
	if (i == 0) {
		if (move_highlighted)
		{
			br.texture = ASSET_PATH + std::string("pokeball.png");
			graphics::drawRect(CANVAS_WIDTH * 0.2f / 2.0f, CANVAS_HEIGHT / 3.8f, POKEBALL_LOGO, POKEBALL_LOGO, br);
		}
		br.texture = ASSET_PATH + std::string(move_pic());
		graphics::drawRect(move_pos[0], move_pos[1], MOVES, MOVES, br);
		SETCOLOR(br.fill_color, 0.0f, 0.0f, 0.0f);
		graphics::setFont("FreeSans.ttf");
		graphics::drawText(move_pos[0] * 0.6f, move_pos[1] * 0.6f, 0.8f, getName(), br);
		SETCOLOR(br.fill_color, 0.0f, 0.0f, 0.0f);
		graphics::setFont("FreeSans.ttf");
		graphics::drawText(move_pos[0] * 0.6f, move_pos[1] * 1.4f, 0.6f, getType(), br);
	}
	else if (i == 1)
	{
		if (move_highlighted)
		{
			br.texture = ASSET_PATH + std::string("pokeball.png");
			graphics::drawRect(CANVAS_WIDTH * 0.6f, CANVAS_HEIGHT / 3.8f, POKEBALL_LOGO, POKEBALL_LOGO, br);
		}
		br.texture = ASSET_PATH + std::string(move_pic());
		graphics::drawRect(move_pos[0], move_pos[1], MOVES, MOVES, br);
		SETCOLOR(br.fill_color, 0.0f, 0.0f, 0.0f);
		graphics::setFont("FreeSans.ttf");
		graphics::drawText(move_pos[0] * 0.87f, move_pos[1] * 0.6f, 0.8f, getName(), br);
		SETCOLOR(br.fill_color, 0.0f, 0.0f, 0.0f);
		graphics::setFont("FreeSans.ttf");
		graphics::drawText(move_pos[0] * 0.875f, move_pos[1] * 1.4f, 0.6f, getType(), br);
	}
	else if (i == 2)
	{
		if (move_highlighted)
		{
			br.texture = ASSET_PATH + std::string("pokeball.png");
			graphics::drawRect(CANVAS_WIDTH * 0.6f, CANVAS_HEIGHT * 0.75f, POKEBALL_LOGO, POKEBALL_LOGO, br);
		}
		br.texture = ASSET_PATH + std::string(move_pic());
		graphics::drawRect(move_pos[0], move_pos[1], MOVES, MOVES, br);
		SETCOLOR(br.fill_color, 0.0f, 0.0f, 0.0f);
		graphics::setFont("FreeSans.ttf");
		graphics::drawText(move_pos[0] * 0.87, move_pos[1] * 0.87, 0.8f, getName(), br);
		SETCOLOR(br.fill_color, 0.0f, 0.0f, 0.0f);
		graphics::setFont("FreeSans.ttf");
		graphics::drawText(move_pos[0] * 0.87f, move_pos[1] * 1.132f, 0.6f, getType(), br);
	}
	else if (i == 3)
	{
		if (move_highlighted)
		{
			br.texture = ASSET_PATH + std::string("pokeball.png");
			graphics::drawRect(CANVAS_WIDTH * 0.2f / 2.0f, CANVAS_HEIGHT * 0.75f, POKEBALL_LOGO, POKEBALL_LOGO, br);
		}
		br.texture = ASSET_PATH + std::string(move_pic());
		graphics::drawRect(move_pos[0], move_pos[1], MOVES, MOVES, br);
		SETCOLOR(br.fill_color, 0.0f, 0.0f, 0.0f);
		graphics::setFont("FreeSans.ttf");
		graphics::drawText(move_pos[0] * 0.6f, move_pos[1] * 0.87f, 0.8f, getName(), br);
		SETCOLOR(br.fill_color, 0.0f, 0.0f, 0.0f);
		graphics::setFont("FreeSans.ttf");
		graphics::drawText(move_pos[0] * 0.6f, move_pos[1] * 1.132f, 0.6f, getType(), br);
	}

}

bool Move::contains(float x, float y)
{
	return distance(x, y, move_pos[0], move_pos[1]) < MOVES * 0.4f;
}
