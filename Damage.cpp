#include "Damage.h"
#include <iostream>

int Damage::damage(Pokemon* Attack, Pokemon* Defence, Move* Move)
{
	int damage = (Move->getpower() * ((float)Attack->getAtt() / (float)Defence->getDef()));
	if (Attack->getType1() != Move->getType() || Attack->getType2() != Move->getType())
	{
		damage = damage * 0.75;
	}
	Effectiveness* e = new Effectiveness();
	int option1 = e->iseffective(Move->getType(), Defence->getType1());
	int option2 = e->iseffective(Move->getType(), Defence->getType2());
	if (option1 == 3 || option2 == 3)
	{
		damage = 0;
		return damage;
	}
	else if (option1 == 2 && option2 == 0)
	{
		return damage;
	}
	else if (option1 == 0 && option2 == 2)
	{
		return damage;
	}
	else if (option1 == 2 || option2 == 2)
	{
		damage = damage * 2;
		return damage;
	}
	else if (option1 == 0 || option2 == 0)
	{
		damage = damage / 2;
		return damage;
	}
	else if (option2 == 4)
	{
		damage = damage * 4;
		return damage;
	}
	else
	{
		return damage;
	}
}

string Damage::dmg(Pokemon* Attack, Pokemon* Defence, Move* Move)
{
	int damage = (Move->getpower() * ((float)Attack->getAtt() / (float)Defence->getDef())) / 2;
	if (Attack->getType1() != Move->getType() || Attack->getType2() != Move->getType())
	{
		damage = damage * 0.75;
	}
	Effectiveness* e = new Effectiveness();
	int option1 = e->iseffective(Move->getType(), Defence->getType1());
	int option2 = e->iseffective(Move->getType(), Defence->getType2());
	if (option1 == 3 || option2 == 3)
	{
		damage = 0;
		return "It doesn't affect....";
	}
	else if (option1 == 2 && option2 == 0)
	{
		return "Normal damage";
	}
	else if (option1 == 0 && option2 == 2)
	{
		return "Normal damage";
	}
	else if (option1 == 2 || option2 == 2)
	{
		damage = damage * 2;
		return "It's super effective!";
	}
	else if (option1 == 0 || option2 == 0)
	{
		damage = damage / 2;
		return "It's not very effective....";
	}
	else
	{
		return "Normal damage";
	}
}