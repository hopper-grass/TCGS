#include "Library/planet.h"
#include <iostream>
#include <vector>
#include <string>
#include <queue>

//for now this is a void function this can change later if need be
vector<string> mapReader(string path,vector<Planet>* planets){
  FILE* file;
  vecotr<string> map;
  file = fopen(path);
  stringstream ss;
  string line;
  int height,width;
  queue

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
          planets.push_back(string(line[j]),nullptr,"",vector<strings>());//This might work but planet needs changes
        }
        vector[i][j] = line[j];
      }
    }

    //The following code doesn't actually work just yet because changes need to be made to planets class
    getline(file,line);//gets last line in file which is the connections string

    ss << line;

    while(ss >> line){
      //below comment has partial logic for building connections
      //http://www.java2s.com/Tutorial/Cpp/0500__STL-Algorithms-Non-modifying-sequence-operations/FindanElementandItsPositioninaVector.htm
    }
    file.close();  
  } 
  return map;

}
