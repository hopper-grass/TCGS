#include "player.h"
#include <string>
using namespace std;

Player::Player(string nam, string spec)
{
  name = nam;
  species = spec;
  numV=0;
}

Player::~Player()
{
  numV=0;

}

void Player::gainPlanet(Planet* planet)
{
  planets.push_back(planet);
}

void Player::losePlanet(Planet* planet)
{
  for(unsigned int i=0; i<planets.size(); i++)
    if(planets[i]->name() == planet->name())
    {
      planets.erase(planets.begin()+i);
      break;
    }
}

vector<Planet*> Player::planetsHeld()
{
  return planets;
}

vector<Army*> Player::armiesOwned()
{
  vector<Army*> armies;
  for(unsigned int i=0; i<planets.size(); i++)
    armies.push_back(planets[i]->armyHeld());
  return armies;
}

bool Player::isDead()
{
  return (planets.size()==0);
}
