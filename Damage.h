#pragma once
#include "Pokemon.h"
#include "Move.h"
#include "Effectiveness.h"
#include <string>
class Damage
{

public:
	int damage(Pokemon* Attack, Pokemon* Defence, Move* Move);
	string dmg(Pokemon* Attack, Pokemon* Defence, Move* Move);



};