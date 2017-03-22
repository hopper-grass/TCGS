#include "player.h"
#include <string>
using namespace std;

Player::Player(string nam, string spec)
{
  name = nam;
  species = spec;
}

Player::~Player()
{

}

void Player::gainPlanet(Planet planet)
{
  planets.push_back(planet);
}

void Player::losePlanet(Planet planet)
{
  for(unsigned int i=0; i<planets.size(); i++)
    if(planets[i] == planet)
    {
      planets.erase(planets.begin()+i);
      break;
    }
}

vector<Planet> Player::planetsHeld()
{
  return planets;
}

vector<Army> Player::armiesOwned()
{
  vector<Army> armies;
  for(unsigned int i=0; i<planets.size(); i++)
    armies.push_back(planets[i].armiesHeld());
  return armies;
}

bool Player::isDead()
{
  return (planets.size()==0);
}
