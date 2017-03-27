//Matthew Dyer and Michael Lee
//test file for the game loop

#include <iostream>
#include <vector>
#include <queue>
#include "gameLoop.h"
#include "Library/Planet.h"
#include "Library/player.h"
#include "Library/army.h"
#include "battle.h"

using namespace std;

int main(){
	Army* armyOne = new Army(50);
	Army* armyTwo = new Army(50);

	vector<string> connectA;
	connectA.push_back("B");
	Planet* A = new Planet("A",armyOne,"Matt",connectA);

	vector<string> connectB;
	connectB.push_back("A");
	Planet* B = new Planet("B",armyTwo,"Michael",connectB);

	vector<string> connectC;
	connectC.push_back("A");
	connectC.push_back("B");
	Planet* C = new Planet("C",armyOne,"Matt",connectC);

	Player* x = new Player("Matt","Robot");
	Player* y = new Player("Michael","Human");

	x->gainPlanet(A);
	x->gainPlanet(C);
	y->gainPlanet(B);

	queue<Player*> players;
	players.push(x);
	players.push(y);

	vector<Planet*> planets;
	planets.push_back(A);
	planets.push_back(B);

	gameLoop(players,planets);

	return 0;
}
