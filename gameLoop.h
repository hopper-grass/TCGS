//Matthew Deyr and Michael Lee
//this file is needed to include gameLoop.cpp
#include <iostream>
#include "Library/player.h"
#include "Library/Planet.h"

using namespace std;

#ifndef GAMELOOP__H
#define GAMELOOP__H

void gameLoop(queue<Player*> players, vector<Planet*> planets);

#endif
