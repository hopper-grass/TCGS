#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include "Planet.h"//I added these lines for the game loop to compile and commented out the placeholders
//#include "army.h"
using namespace std;
//class Planet{int COMPILE;};
class Army{
	public:
		int size;
};


class Player{
  public:
    Player(string nam, string spec);
    ~Player();
    void gainPlanet(Planet planet);
    void losePlanet(Planet planet);
    vector<Planet> planetsHeld();
    int armiesOwned();
    string name;
    string species;
    bool isDead();
  private:
    vector<Planet> planets;
};

#endif 
