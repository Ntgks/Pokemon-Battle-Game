#include "Effectiveness.h"
#include <string>
using namespace std;

int Effectiveness::iseffective(string t1, string t2)
{
	if (t1 == "Fire") {
		if (t2 == "Grass") { return 2; }
		else if (t2 == "Water") { return 0; }
		else if (t2 == "Rock") { return 0; }
		else if (t2 == "Fire") { return 0; }
		else if (t2 == "Dragon") { return 0; }
		else { return 1; }
	}
	else if (t1 == "Grass") {
		if (t2 == "Water") { return 2; }
		else if (t2 == "Ground") { return 2; }
		else if (t2 == "Rock") { return 2; }
		else if (t2 == "Grass") { return 0; }
		else if (t2 == "Poison") { return 0; }
		else if (t2 == "Fire") { return 0; }
		else if (t2 == "Dragon") { return 0; }
		else if (t2 == "Flying") { return 0; }
		else { return 1; }
	}
	else if (t1 == "Water") {
		if (t2 == "Fire") { return 2; }
		else if (t2 == "Ground") { return 2; }
		else if (t2 == "Rock") { return 2; }
		else if (t2 == "Grass") { return 0; }
		else if (t2 == "Dragon") { return 0; }
		else if (t2 == "Water") { return 0; }
		else { return 1; }
	}
	else if (t1 == "Electric") {
		if (t2 == "Water") { return 2; }
		else if (t2 == "Ground") { return 3; }
		else if (t2 == "Flying") { return 2; }
		else if (t2 == "Grass") { return 0; }
		else if (t2 == "Dragon") { return 0; }
		else if (t2 == "Electric") { return 0; }
		else { return 1; }
	}
	else if (t1 == "Fighting") {
		if (t2 == "Normal") { return 2; }
		else if (t2 == "Ghost") { return 3; }
		else if (t2 == "Rock") { return 2; }
		else if (t2 == "Dark") { return 2; }
		else if (t2 == "Poison") { return 0; }
		else if (t2 == "Psychic") { return 0; }
		else if (t2 == "Flying") { return 0; }
		else { return 1; }
	}
	else if (t1 == "Normal") {
		if (t2 == "Ghost") { return 3; }
		else if (t2 == "Rock") { return 0; }
		else { return 1; }
	}
	else if (t1 == "Poison") {
		if (t2 == "Grass") { return 2; }
		else if (t2 == "Rock") { return 0; }
		else if (t2 == "Ghost") { return 0; }
		else if (t2 == "Poison") { return 0; }
		else if (t2 == "Ground") { return 0; }
		else { return 1; }
	}
	else if (t1 == "Ground") {
		if (t2 == "Fire") { return 2; }
		else if (t2 == "Flying") { return 3; }
		else if (t2 == "Poison") { return 2; }
		else if (t2 == "Electric") { return 2; }
		else if (t2 == "Grass") { return 0; }
		else if (t2 == "Rock") { return 2; }
		else { return 1; }
	}
	else if (t1 == "Flying") {
		if (t2 == "Grass") { return 2; }
		else if (t2 == "Fighting") { return 2; }
		else if (t2 == "Electric") { return 0; }
		else if (t2 == "Rock") { return 0; }
		else { return 1; }
	}
	else if (t1 == "Psychic") {
		if (t2 == "Fighting") { return 2; }
		else if (t2 == "Dark") { return 3; }
		else if (t2 == "Poison") { return 2; }
		else if (t2 == "Psychic") { return 0; }
		else { return 1; }
	}
	else if (t1 == "Rock") {
		if (t2 == "Fire") { return 2; }
		else if (t2 == "Flying") { return 2; }
		else if (t2 == "Fighting") { return 0; }
		else if (t2 == "Ground") { return 0; }
		else { return 1; }
	}
	else if (t1 == "Ghost") {
		if (t2 == "Normal") { return 3; }
		else if (t2 == "Psychic") { return 2; }
		else if (t2 == "Ghost") { return 2; }
		else if (t2 == "Dark") { return 0; }
		else { return 1; }
	}
	else if (t1 == "Dragon") {
		if (t2 == "Dragon") { return 2; }
		else if (t2 == "Ice") { return 0; }
		else { return 1; }
	}
	else if (t1 == "Dark") {
		if (t2 == "Psychic") { return 2; }
		else if (t2 == "Ghost") { return 2; }
		else if (t2 == "Fighting") { return 0; }
		else if (t2 == "Dark") { return 0; }
		else { return 1; }
	}
	else if (t1 == "Steel") {
		if (t2 == "Rock") { return 2; }
		else if (t2 == "Electric") { return 0; }
		else if (t2 == "Fire") { return 0; }
		else if (t2 == "Water") { return 0; }
		else { return 1; }
	}
	else if (t1 == "Ice") {
		if (t2 == "Dragon") { return 4; }
		else if (t2 == "Grass") { return 2; }
		else if (t2 == "Fire") { return 0; }
		else if (t2 == "Water") { return 0; }
		else if (t2 == "Flying") { return 2; }
		else if (t2 == "Ground") { return 2; }
		else { return 1; }
	}
}