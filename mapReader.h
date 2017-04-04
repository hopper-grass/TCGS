//Sam Wiles
#include "Library/Planet.h"
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <fstream>
#include <sstream>

using namespace std;

//for now this is a void function this can change later if need be
void mapReader(string path,vector<Planet*>& planets,vector<string>& map){

  vector<string> connections;
  vector<string> connected;

  ifstream fileIn(path); // needs error checking

  stringstream ss;
  string line;
  int height,width;
  queue<char> make_me;
  set<char> make_that;

  fileIn >> height;
  fileIn >> width;

  getline(fileIn,line);
  while(getline(fileIn, line)){
    if(fileIn){
      map.push_back(line);
      for(int j = 0; j < line.size(); j++){
        if((int)line[j] >= 65 && (int)line[j] <= 90){ //if the character we are looking at is between A-Z
          make_that.insert(line[j]);
        }
      }

    }
  }	


  getline(fileIn,line);//gets last line in file which is the connections string

  ss << line;

  while(ss >> line){//put all of the connections into a vector until I make the planets themselves
    connections.push_back(line);
  }


for(auto make: make_that){
  make_me.push(make);
}

while(!make_me.empty()){
  string p = "";
  char front = make_me.front();
  p += front;
  make_me.pop();
  for(vector<string>::const_iterator i = connections.begin(); i != connections.end(); ++i){
    if(i[0][0] == front){
      string otherP;
      ss << i[0][1];
      ss >> otherP;
      connected.push_back(otherP);
      connections.erase(i);
    }
  }

  Planet* newP = new Planet(p,nullptr,"",connected);
  planets.push_back(newP);
  connected.clear();
}

fileIn.close();  
} 
