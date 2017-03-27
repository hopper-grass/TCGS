#include "Library/planet.h"
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>

//for now this is a void function this can change later if need be
vector<string> mapReader(string path,vector<Planet>* planets){
  FILE* file;
  vecotr<string> map, connections, connected;
  file = fopen(path);
  stringstream ss;
  string line;
  int height,width;
  queue<char> make_me;
  vector<string> connections;

  if(file.is_Open()){
    getline(file,line);
    ss << line;
    ss >> height;
    ss >> width;

    map.resize(height);

    for(int i = 0; i < height; i++){
      getline(file,line);
      for(int j = 0; j < width; j++){
        if((int)line[j] >= 65 && (int)line[j] <= 90){ //if the character we are looking at is between A-Z
          make_me.push(line[j]);
        }
        vector[i][j] = line[j];
      }
    }

    getline(file,line);//gets last line in file which is the connections string

    ss << line;

    while(ss >> line){//put all of the connections into a vector until I make the planets themselves
      connections.push_back(line);
    }

    while(!make_me.empty()){
      string p = make_me.front();
      make_me.pop();
      for(auto &i : connections){
        if(i[0] == p){
          connected.push_back(i[1]);
          connections.erase(i);
        }
      }
      planets.push_back(p,nullptr,"",connected);
      connected.clear();
    }
    file.close();  
  } 
  return map;

}
