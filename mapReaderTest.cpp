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

  /*
  cout << "planets" << endl;
  for(int i = 0; i < planets.size(); i++){
    planets[i]->name();
  }
  */

}
