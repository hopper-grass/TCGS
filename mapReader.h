#include "Library/Planet.h"
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <fstream>
#include <sstream>

//for now this is a void function this can change later if need be
vector<string> mapReader(string path,vector<Planet*> planets){

	vector<string> map, connections, connected;

	ifstream fileIn(path); // needs error checking

	stringstream ss;
	string line;
	int height,width;
	queue<char> make_me;
	//vector<string> connections; you already declared this

	fileIn >> height;
	fileIn >> width;

	while(getline(fileIn, line)){
		if(fileIn)
			map.push_back(line);
	}	

	for(int i = 0; i < height; i++){ 
		for(int j = 0; j < width; j++){
			if(line[j] >= 65 && line[j] <= 90){ //if the character we are looking at is between A-Z
				make_me.push(line[j]);
			}
			map[i][j] = line[j];
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
			for(auto &i : connections){
				if(i[0] == front){
					string otherP;
					ss << i[1];
					ss >> otherP;
					connected.push_back(otherP);
					connections.pop_back(i);
				}
			}
			planets.push_back(p,nullptr,"",connected);
			connected.clear();
		}

		fileIn.close();  
	} 
	return map;

}
