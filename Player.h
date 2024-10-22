#pragma once
#include <string>
#include <list>
#include "define.h"
#include "Pokemon.h"
#include "Move.h"
#include "sgg/graphics.h"
#include "Pokemon_Array.h"
class Player
{
	float pos[2];
	std::list<Pokemon*>Pokemons;
	enum game_state { GAME, FIGHTONE, FIGHTTWO };

	game_state p_state = GAME;
public:
	void draw(bool h, Pokemon* Pokemon);
	void update();

	float getPosX() { return pos[0]; }
	float getPosY() { return pos[1]; }
	void setPosX(float x) { pos[0] = x; }
	void setPosY(float y) { pos[1] = y; }
	void create_players_team();
	void Change_To_FightOne() { p_state = FIGHTONE; }
	void Change_To_Game() { p_state = GAME; }
	void Change_To_FightTwo() { p_state = FIGHTTWO; }
	Pokemon* ReturnPokemon1();
	Pokemon* ReturnPokemon2();
	Pokemon* ReturnPokemon3();
	void draw_minifigure(Pokemon* Pokemon);

};