#include "pokemon_array.h"
#include <iostream>
#include <ctime>


void PokemonArray::createarray() {
	//charizard, blastoise, venusaur, gyarados , dragonite, gengar , pikachu , nidoking , arcanine , alakazam , rhydon , jolteon , golem , vileplume , aerodactyl
	Move* m1 = new Move("Flamethrower", "Fire", 95);
	Move* m2 = new Move("Slash", "Normal", 70);
	Move* m3 = new Move("Wing Attack", "Flying", 60);
	Move* m4 = new Move("Dragon Claw", "Dragon", 80);
	Pokemon* Charizard = new Pokemon(300, 78, 84, 100, "Charizard", "Fire", "Flying", m1, m2, m3, m4, "Charizard_front", "Charizard_back", 1);
	Charizard->Moves(m1, m2, m3, m4);
	Pokemons.push_back(Charizard);
	Move* m5 = new Move("Petal Blizzard", "Grass", 90);
	Move* m6 = new Move("Sludge Bomb", "Poison", 90);
	Move* m7 = new Move("Solar Beam", "Grass", 120);
	Move* m8 = new Move("Take Down", "Normal", 90);
	Pokemon* Venusaur = new Pokemon(365, 83, 82, 80, "Venusaur", "Grass", "Poison", m5, m6, m7, m8, "Venusaur_front", "Venusaur_back", 2);
	Venusaur->Moves(m5, m6, m7, m8);
	Pokemons.push_back(Venusaur);
	Move* m9 = new Move("Bite", "Dark", 60);
	Move* m10 = new Move("Hydro Pump", "Water", 110);
	Move* m11 = new Move("Ice Beam", "Ice", 90);
	Move* m12 = new Move("Headbutt", "Normal", 80);
	Pokemon* Blastoise = new Pokemon(360, 100, 83, 78, "Blastoise", "Water", "Water", m9, m10, m11, m12, "Blastoise_front", "Blastoise_back", 3);
	Blastoise->Moves(m9, m10, m11, m12);
	Pokemons.push_back(Blastoise);
	Move* m13 = new Move("Crunch", "Dark", 80);
	Move* m14 = new Move("Hurricane", "Flying", 110);
	Move* m15 = new Move("Twister", "Dragon", 60);
	Move* m51 = new Move("Hydro Pump", "Water", 110);
	Pokemon* Gyarados = new Pokemon(390, 79, 125, 81, "Gyarados", "Water", "Flying", m13, m51, m14, m15, "Gyarados_front", "Gyarados_back", 4);
	Gyarados->Moves(m13, m51, m14, m15);
	Pokemons.push_back(Gyarados);
	Move* m16 = new Move("Slam", "Normal", 80);
	Move* m17 = new Move("Outrage", "Dragon", 120);
	Move* m52 = new Move("Wing Attack", "Flying", 60);
	Move* m53 = new Move("Dragon Claw", "Dragon", 80);
	Pokemon* Dragonite = new Pokemon(380, 95, 135, 80, "Dragonite", "Flying", "Dragon", m52, m53, m16, m17, "Dragonite_front", "Dragonite_back", 5);
	Dragonite->Moves(m52, m53, m16, m17);
	Pokemons.push_back(Dragonite);
	Move* m18 = new Move("Shadow Ball", "Ghost", 80);
	Move* m19 = new Move("Dark Pulse", "Dark", 80);
	Move* m20 = new Move("Shadow Claw", "Ghost", 70);
	Move* m54 = new Move("Sludge Bomb", "Poison", 90);
	Pokemon* Gengar = new Pokemon(320, 60, 100, 110, "Gengar", "Ghost", "Poison", m18, m19, m20, m54, "Gengar_front", "Gengar_back", 6);
	Gengar->Moves(m18, m19, m20, m6);
	Pokemons.push_back(Gengar);
	Move* m21 = new Move("Thunder", "Electric", 110);
	Move* m22 = new Move("Iron Tail", "Steel", 100);
	Move* m23 = new Move("Thunderbolt", "Electric", 80);
	Move* m55 = new Move("Slam", "Normal", 80);
	Pokemon* Pikachu = new Pokemon(280, 70, 85, 120, "Pickachu", "Electric", "Electric", m21, m22, m23, m55, "Pikachu_front", "Pikachu_back", 7);
	Pikachu->Moves(m21, m22, m23, m16);
	Pokemons.push_back(Pikachu);
	Move* m24 = new Move("Poison Jab", "Poison", 80);
	Move* m25 = new Move("Horn Attack", "Normal", 80);
	Move* m26 = new Move("Earth Power", "Ground", 90);
	Move* m27 = new Move("Head Smash", "Rock", 110);
	Pokemon* Nidoking = new Pokemon(360, 80, 100, 85, "Nidoking", "Ground", "Poison", m24, m25, m26, m27, "Nidoking_front", "Nidoking_back", 8);
	Nidoking->Moves(m24, m25, m26, m27);
	Pokemons.push_back(Nidoking);
	Move* m28 = new Move("Close Combat", "Fighting", 120);
	Move* m41 = new Move("Flamethrower", "Fire", 95);
	Move* m42 = new Move("Take Down", "Normal", 90);
	Move* m43 = new Move("Crunch", "Dark", 80);
	Pokemon* Arcanine = new Pokemon(380, 80, 110, 95, "Arcanine", "Fire", "Fire", m41, m42, m43, m28, "Arcanine_front", "Arcanine_back", 9);
	Arcanine->Moves(m41, m42, m43, m28);
	Pokemons.push_back(Arcanine);
	Move* m29 = new Move("Psychic", "Psychic", 120);
	Move* m30 = new Move("Knock Off", "Dark", 65);
	Move* m31 = new Move("Focus Blast", "Fighting", 100);
	Move* m32 = new Move("Psycho Cut", "Psychic", 70);
	Pokemon* Alakazam = new Pokemon(310, 65, 90, 120, "Alakazam", "Psychic", "Psychic", m29, m30, m31, m32, "Alakazam_front", "Alakazam_back", 10);
	Alakazam->Moves(m29, m30, m31, m32);
	Pokemons.push_back(Alakazam);
	Move* m33 = new Move("Stone Edge", "Rock", 100);
	Move* m34 = new Move("Hammer Arm", "Fighting", 100);
	Move* m35 = new Move("Earthquake", "Ground", 100);
	Move* m44 = new Move("Horn Attack", "Normal", 80);
	Pokemon* Rhydon = new Pokemon(410, 100, 120, 40, "Rhydon", "Rock", "Ground", m44, m33, m34, m35, "Rhydon_front", "Rhydon_back", 11);
	Rhydon->Moves(m44, m33, m34, m35);
	Pokemons.push_back(Rhydon);
	Move* m45 = new Move("Thunder", "Electric", 110);
	Move* m46 = new Move("Bite", "Dark", 60);
	Move* m47 = new Move("Iron Tail", "Steel", 100);
	Move* m48 = new Move("Take Down", "Normal", 90);
	Pokemon* Jolteon = new Pokemon(330, 75, 90, 130, "Jolteon", "Electric", "Electric", m45, m46, m47, m48, "Jolteon_front", "Jolteon_back", 12);
	Jolteon->Moves(m45, m46, m47, m48);
	Pokemons.push_back(Jolteon);
	Move* m36 = new Move("Rock Smash", "Fighting", 60);
	Move* m60 = new Move("Stone Edge", "Rock", 100);
	Move* m56 = new Move("Earthquake", "Ground", 100);
	Move* m57 = new Move("Take Down", "Normal", 90);
	Pokemon* Golem = new Pokemon(360, 130, 120, 45, "Golem", "Rock", "Ground", m60, m56, m36, m57, "Golem_front", "Golem_back", 13);
	Golem->Moves(m60, m56, m36, m57);
	Pokemons.push_back(Golem);
	Move* m37 = new Move("Cut", "Normal", 55);
	Move* m38 = new Move("Energy Ball", "Grass", 90);
	Move* m58 = new Move("Petal Blizzard", "Grass", 90);
	Move* m59 = new Move("Sludge Bomb", "Poison", 90);
	Pokemon* Vileplume = new Pokemon(350, 85, 95, 50, "Vileplume", "Grass", "Poison", m58, m37, m59, m38, "Vileplume_front", "Vileplume_back", 14);
	Vileplume->Moves(m58, m37, m59, m38);
	Pokemons.push_back(Vileplume);
	Move* m39 = new Move("Ancient Power", "Rock", 80);
	Move* m40 = new Move("Dragon Breath", "Dragon", 65);
	Move* m49 = new Move("Wing Attack", "Flying", 60);
	Move* m50 = new Move("Crunch", "Dark", 80);
	Pokemon* Aerodactyl = new Pokemon(360, 65, 105, 130, "Aerodactyl", "Rock", "Flying", m39, m49, m40, m50, "Aerodactyl_front", "Aerodactyl_back", 15);
	Aerodactyl->Moves(m39, m49, m40, m50);
	Pokemons.push_back(Aerodactyl);

}

void PokemonArray::ReturnList()
{

	int i = rand() % 15;
	int z = 0;
	for (auto pokemon : Pokemons)
	{
		if (z == i && (pokemon->getName() == "Dragonite"|| pokemon->getName() == "Pikachu"))
		{
			i = i + 1;
			z = z + 1;
		}
		else if (z == i && (pokemon->getName() != "Dragonite" && pokemon->getName() != "Pikachu"))
		{
			first = pokemon;
			z = z + 1;
		}
		else
		{
			z = z + 1;
			List_for_first_pokemon.push_back(pokemon);
		}
	}
	int e = rand() % 14;
	int b = 0;
	for (auto pokemon : List_for_first_pokemon)
	{
		if (b == e)
		{
			second = pokemon;
			b = b + 1;
		}
		else
		{
			b = b + 1;
			List_for_second_pokemon.push_back(pokemon);
		}
	}
	int d = rand() % 13;
	int m = 0;
	for (auto pokemon : List_for_second_pokemon)
	{
		if (m == d)
		{
			third = pokemon;
			m = m + 1;
		}
		else
		{
			m = m + 1;
		}
	}
	Pokemons.clear();
	Pokemons.push_back(first);
	Pokemons.push_back(second);
	Pokemons.push_back(third);

	int j = 0;
	for (auto pokemon : Pokemons)
	{
		if (j == 0)
		{
			pokemon->setposxforminifigure(CANVAS_WIDTH / 2);
			pokemon->setposyforminifigure(CANVAS_HEIGHT * 1.66f / 2.0f);
		}
		else if (j == 1)
		{
			pokemon->setposxforminifigure(CANVAS_WIDTH * 0.42f / 2.0f);
			pokemon->setposyforminifigure(CANVAS_HEIGHT / 2);
		}
		else if (j == 2)
		{
			pokemon->setposxforminifigure(CANVAS_WIDTH * 1.62f / 2.0f);
			pokemon->setposyforminifigure(CANVAS_HEIGHT / 2);
		}
		j = j + 1;
	}
}

Pokemon* PokemonArray::ReturnPokemon1()
{
	int i = 0;
	for (auto pokemon : Pokemons)
	{
		if (i == 0)
		{
			return pokemon;
			i = i + 1;
		}
		else
		{
			i = i + 1;
		}
	}
}

Pokemon* PokemonArray::ReturnPokemon2()
{
	int i = 0;
	for (auto pokemon : Pokemons)
	{
		if (i == 1)
		{
			return pokemon;
			i = i + 1;
		}
		else
		{
			i = i + 1;
		}
	}
}

Pokemon* PokemonArray::ReturnPokemon3()
{
	int i = 0;
	for (auto pokemon : Pokemons)
	{
		if (i == 2)
		{
			return pokemon;
			i = i + 1;
		}
		else
		{
			i = i + 1;
		}
	}
}
