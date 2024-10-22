#pragma once
#include "PreGameBackground.h"
#include <string>
#include <list>
#include "define.h"
#include "Start.h"
#include "sgg/graphics.h"
#include "GameBackground.h"
#include "Player.h"
#include "LoadingScreen.h"
#include "Fight.h"
#include "MoveSelectionBackground.h"
#include "Move.h"
#include "Pokemon_Button.h"
#include "BackgroundForSwitchingPokemons.h"
#include "Damage.h"
#include "ContinueButton.h"
#include "VictoryBackground.h"
#include "GoBackButton.h"
class Game {

	static Game* m_instance;
	enum game_state {
		STATE_INIT, STATE_LOADING, STATE_START, STATE_PREGAME, STATE_GAME_FOR_PLAYER_ONE, STATE_GAME_FOR_PLAYER_TWO, STATE_MOVE_SELECTION, STATE_MOVE_SELECTION_2, STATE_SELECT_POKEMON, STATE_SELECT_POKEMON_2, STATE_FIGHT_FOR_PLAYER_ONE, STATE_FIGHT_FOR_PLAYER_TWO, STATE_FIGHT_FOR_PLAYER_ONE_PARTB, STATE_FIGHT_FOR_PLAYER_TWO_PARTB, STATE_DEADPOKEMON_PLAYERTWO, STATE_DEADPOKEMON_PLAYERONE, STATE_SELECT_DEADPOKEMON_TWO, STATE_SELECT_DEADPOKEMON_ONE, STATE_PLAYERONE_WINNER, STATE_PLAYERTWO_WINNER
	};
	game_state g_state = STATE_INIT;


	std::list<Player*>Players;
	std::list<Player*>Players_2;
	std::list<Pokemon*>Pokemons_Player1;
	std::list<Pokemon*>Pokemons_Player2;
	std::list<PreGameBackground*>background;
	std::list<Start*>Start_button;
	std::list<GameBackground*>background_2;
	std::list<LoadingScreen*>background_3;
	std::list<Fight*>fight_button;
	std::list<Move*>moves;
	std::list<MoveSelectionBackground*>msb;
	std::list<Pokemon_Button*>pb;
	std::list<BackgroundForSwitchingPokemons*>bfsp;
	std::list<Move*>moves_2;
	std::list<ContinueButton*>cb_list;
	std::list<VictoryBackground*> vb_list;
	std::list<GoBackButton*> gb_list;
	float minifigure_pos_x;
	float minifigure_pos_y;
	Pokemon* activepokemon;

	Pokemon* bench;
	Pokemon* bench_2;
	Pokemon* bench_b;
	Move* move_for_player_1;
	Move* move_for_player_2;
	bool player1_used_move = false;
	bool player1_switched_pokemon = false;
	bool player2_used_move = false;
	bool player2_switched_pokemon = false;
	int pokemon_player1 = 3;
	int pokemon_player2 = 3;
	Game() {}
public:
	void draw();
	void update();

	void init_for_PreGameBackground();
	void init_for_Start_Button();
	void init_for_Gamebackground();
	void init_for_Player();
	void init_for_LoadingScreen();
	void init_for_Fight_Button();
	void init_for_MoveSelectionBackground();
	void init_for_Moves();
	void init_for_Pokemon_Button();
	void init_for_SwitchingPokemonsBackground();
	void init_for_continue_button();
	void init_for_VictoryBackground();
	void init_for_GoBackButton();
	static void releaseInstance() {
		if (m_instance) {
			delete m_instance;
			m_instance = nullptr;
		}
	}

	~Game();
	static Game* getInstance();

};