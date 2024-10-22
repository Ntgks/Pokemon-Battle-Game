#pragma once
#include "Pokemon.h"
#include "Move.h"
#include <list>
class PokemonArray {
	std::list<Pokemon*>Pokemons;
	std::list<Pokemon*>List_for_first_pokemon;
	std::list<Pokemon*>List_for_second_pokemon;

	Pokemon* first;
	Pokemon* second;
	Pokemon* third;

public:
	//creates an array with the pokemon available to the players
	Pokemon* array[15];
	void createarray();

	void ReturnList();
	Pokemon* ReturnPokemon1();
	Pokemon* ReturnPokemon2();
	Pokemon* ReturnPokemon3();
	~PokemonArray()
	{
		delete first;
		delete second;
		delete third;
		for (auto p : Pokemons)
		{
			delete p;
		}
		for (auto p : List_for_first_pokemon)
		{
			delete p;
		}
		for (auto p : List_for_second_pokemon)
		{
			delete p;
		}
	}

};