//Matthew Dyer, Bryan Studabaker, Zachary Baldwin
#include <iostream>
#include <vector>
#include <string>
#include "Planet.h"
#include "army.h"

Planet::Planet(string pName, Army* armies, string owner ,vector<string> connections){
	planetName = pName;
	//numArmies = armies;
	army=armies;
	planetOwner = owner;
	planetConnections = connections;
}

string Planet::name(){
	return planetName;
}

int Planet::armiesHeld(){
  	return army->size();
}

Army* Planet::armyHeld(){
  	return army;
}

string Planet::whoOwnsPlanet(){
	return planetOwner;
}

vector<string> Planet::allConnections(){
	return planetConnections;
}

bool Planet::isConnected(Planet x){
	for(unsigned int i = 0; i < x.allConnections().size(); ++i){
		if(planetName == x.allConnections()[i]){
			return true;
		}
	}
	return false;
}
