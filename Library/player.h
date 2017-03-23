#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
using namespace std;
class Planet{int COMPILE;};
class Army{int compile;};


class Player{
  public:
    Player(string nam, string spec);
    ~Player();
    void gainPlanet(Planet planet);
    void losePlanet(Planet planet);
    vector<Planet> planetsHeld();
    vector<Army> armiesOwned();
    string name;
    string species;
    bool isDead();
  private:
    vector<Planet> planets;
};

#endif 
