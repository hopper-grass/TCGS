#include "mapReader.h"
#include "Library/Planet.h"
#include <vector>

using namespace std;

int main(int argc, char* argv[]){
  vector<string> map;
  vector<Planet*> planets;
  string path = "./Library/Maps/2Player/p2_1.txt";

  mapReader(path, planets, map);
  cout << "map" << endl;
  for(int i = 0; i < map.size(); i++){
      cout << map[i] << endl;
  }

  cout << "planets" << endl;
  cout << planets.size() << endl;
  for(int i = 0; i < planets.size(); i++){
    cout << planets[i]->name() << " is connected to: "  << endl;
		for(int j = 0; j < planets[i]->allConnections().size(); ++j){
			cout << planets[i]->allConnections()[j] << " ";
		}
	cout << endl;
  }

}
