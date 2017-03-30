#include "Library/Planet.h"
#include <iostream>
#include <vector>
#include <string>
#include <queue>
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

	fileIn >> height;
	fileIn >> width;

  getline(fileIn,line);
	while(getline(fileIn, line)){
		if(fileIn)
			map.push_back(line);
	}	

	for(int i = 0; i < height; i++){ 
		for(int j = 0; j < width; j++){
			if(line[j] >= 65 && line[j] <= 90){ //if the character we are looking at is between A-Z
				make_me.push(line[j]);
			}
		}

		getline(fileIn,line);//gets last line in file which is the connections string

		ss << line;

		while(ss >> line){//put all of the connections into a vector until I make the planets themselves
			connections.push_back(line);
		}


		while(!make_me.empty()){
			string p;
			char front = make_me.front();
			ss << front;
			ss >> p;
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
			planets.push_back(new Planet(p,nullptr,"",connected));
			connected.clear();
		}

		fileIn.close();  
	} 
}
