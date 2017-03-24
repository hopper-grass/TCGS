//Matthew Dyer
//this file exists to test the functions used in the planet class
//  as well as to serve as an example of how to declare a planet
//To compile: g++ planetTests.cpp Planet.cpp

#include <iostream>
#include <vector>
#include "Planet.h"

using namespace std;

int main(){
	vector<string> connectA;
	connectA.push_back("B");
	connectA.push_back("C");
	Planet A = Planet("A",50,"Bob",connectA);

	vector<string> connectB;
	connectB.push_back("A");
	Planet B = Planet("B",50,"Bob",connectB);

	cout << "A.name(): " << A.name() << endl;
	cout << "A.armiesHeld(): " << A.armiesHeld() << endl;
	cout << "A.whoOwnsPlanet(): " << A.whoOwnsPlanet() << endl;
	cout << "Is A connected to B?: " << A.isConnected(B) << endl;

	return 0;	
}
