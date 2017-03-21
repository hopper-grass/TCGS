//Matthew Dyer, Bryan Studanaker, Zachary Baldwin
//Planet Object

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#ifndef PLANET__H
#define PLANET__H

//class for the Planet object
class Planet{
	public:
		Planet();
		Planet(string pName, int armies,string owner, vector<string> connections); //constructor
		string name(); //returns the name of the planet as a string
		int armiesHeld(); // returns the number of armies on a planet as an integer
		string whoOwnsPlanet(); // returns the owner of a planet as a string
		vector<string> allConnections(); // returns a vector of all connections
		bool isConnected(Planet x); // returns true if planet x is connected to planet

	private:
		string planetName;
		int numArmies;
		string planetOwner;
		vector<string> planetConnections;
};

#endif
