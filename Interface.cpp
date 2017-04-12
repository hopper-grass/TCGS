#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include "gameLoop.h"
#include "Library/Planet.h"
#include "Library/player.h"
#include "Library/army.h"
#include "battle.h"
#include "mapReader.h"

using namespace std; 


int main()
{
  // New Game
  	// Num Players (2 min ; 6 max)
	// Choose Species & Name
	// Choose Map
  
  int numPlayers;
  string response, species, name, map, mapName;
  vector<string> gameMap;
  // string stream initialization?
  

  string banner = "----------------------------------------------------------\n|********** Taking Chances on a Galactic Scale **********|\n----------------------------------------------------------\n";

  cout << "\033[2J\033[1;1H"; // This clears the terminal so that it looks like the banner doesn't move
  cout << banner << endl;

  string numPlayersPrompt = "\nEnter the number of players (2 min ; 6 max): ";

  do // Allows user to re-enter number of players
    {
      cout << "\033[2J\033[1;1H";
      cout << banner << endl;

      cout << numPlayersPrompt;
      cin >> numPlayers;
      if ( cin.fail() )
      {
	cin.clear();
	cin.get();
	continue;
      }

      cout << "\033[2J\033[1;1H";
      cout << banner << endl;

      cout << "\nYou have chosen " << numPlayers << " players, is that correct? (Y/N) ";
      cin >> response;
      if ( cin.fail() )
      {
	cin.clear();
	cin.get();
	continue;
      }

      if (response != "Y" && response != "N" )	// Handles case when user enters in the wrong response
      { response = "N"; }
    } 
  while (response == "N");

  // Initialize Players here

  queue<Player*> players;	


  // Allow each player to choose their Species and Name
  for (int i = 0; i < numPlayers; ++i)
  {


    do
    {
      cout << "\033[2J\033[1;1H";
      cout << banner << endl;
      cout << "PLAYER " << i+1 << endl << endl;

      cout << "\n********* Choose your species *********" << endl << endl;
      cout << "A. Human		B. Robot\nC. Mermaid		D. Alien\nE. Gazorpian		F. Centaur" << endl << endl;
  /*
  	Allow the user to choose which map they would like to play on
		-> Give the user the option of viewing each available map according to the number of players that are playing 
  */
      cout << "Enter the Letter of Species: ";
      cin >> species;
      if ( cin.fail() )
      {
	cin.clear();
	cin.get();
	continue;
      }

      /*
	 Handles the choosing of a species according to the letter that the user chooses
      */
      
      if ( species == "A" )
      {
	species = "Human";
      }

      else if ( species == "B" )
      {
	species = "Robot";
      }

      else if ( species == "C" )
      {
	species = "Mermaid";
      }

      else if ( species == "D" )
      {
	species = "Alien";
      }

      else if ( species == "E" )
      {
	species = "Gazorpian";
      }

      else if ( species == "F" )
      {
	species = "Centaur";
      }

      else
      {
	species = "Unkown";
      }


      

      cout << "\033[2J\033[1;1H";
      cout << banner << endl;
      cout << "PLAYER " << i+1 << endl << endl;

      cout << "\nYou chose " << species << ", is that correct? (Y/N) ";
      cin >> response;
      if ( cin.fail() )
      {
	cin.clear();
	cin.get();
	continue;
      }

      if (response != "Y" && response != "N" )	// Handles case when user enters in the wrong response
      { response = "N"; }

    }
    while (response == "N");


    do
    {

      cout << "\033[2J\033[1;1H";
      cout << banner << endl;
      cout << "PLAYER " << i+1 << endl << endl;

      cout << "********* Enter your desired name *********" << endl << endl;
      cin >> name;
      if ( cin.fail() )
      {
	cin.clear();
	cin.get();
	continue;
      }

      cout << "\033[2J\033[1;1H";
      cout << banner << endl;
      cout << "PLAYER " << i+1 << endl << endl;

      cout << "You would like to be called:  " << name << " , is that correct? (Y/N) ";
      cin >> response;
      if ( cin.fail() )
      {
	cin.clear();
	cin.get();
	continue;
      }

      if (response != "Y" && response != "N" )	// Handles case when user enters in the wrong response
      { response = "N"; }

    }
    while (response == "N");

    Player* p = new Player(name, species);
    players.push(p);
    
  }




  // Quit

  // Initialize Defaults
	// Create Planets for players?
	// Give each player an army?
	

  // Start Game Loop

  Army* armyOne = new Army(50);
  Army* armyTwo = new Army(50);
  Army* armyThree = new Army(0);

  vector<string> connectA;
  connectA.push_back("B");
  //Planet* A = new Planet("A",armyOne,"Matt",connectA);

  vector<string> connectB;
  connectB.push_back("A");
  //Planet* B = new Planet("B",armyTwo,"Michael",connectB);

  vector<string> connectC;
  connectC.push_back("A");
  connectC.push_back("B");
  //Planet* C = new Planet("C",armyThree,"Matt",connectC);

  int i = 1;

  vector<Planet*> planets;
  queue<Player*> players2;
/*
  while (!players.empty())
  {
    if ( i == 1 )
    {
      Planet* A = new Planet("A", armyOne, players.front()->name, connectA); 
      Planet* C = new Planet("C", armyThree, players.front()->name, connectC);
      players.front()->gainPlanet(A);
      players.front()->gainPlanet(C);
      planets.push_back(A);
      planets.push_back(C);
      players2.push(players.front());
    }
    if ( i == 2 )
    {
      Planet* B = new Planet("B", armyTwo, players.front()->name, connectB);
      players.front()->gainPlanet(B);
      planets.push_back(B);
      players2.push(players.front());
    }

    ++i;
    players.pop();
  }
*/

  /*
  	Allow the user to choose which map they would like to play on
		-> Give the user the option of viewing each available map according to the number of players that are playing 
  */

  if ( numPlayers == 2 )
  {
    do 
    {
      cout << "\033[2J\033[1;1H";
      cout << banner << endl;

      cout << "********* Maps *********" << endl << endl;
      cout << "A. Map 1		B. Map 2\nC. Map 3" << endl;
      cout << "\nEnter the letter of the map you would like to view: ";
      cin >> map;
      if ( cin.fail() )
      {
	cin.clear();
	cin.get();
	continue;
      }

      if ( map == "A" )
      {
	map = "Map 1";
	mapName = "Library/Maps/2Player/p2_1.txt";
      }
      else if ( map == "B" )
      {
	map = "Map 2";
	mapName = "Library/Maps/2Player/p2_2.txt";
      }
      else if ( map == "C" )
      {
	map = "Map 3";
	mapName = "Library/Maps/2Player/p2_3.txt";
      }
      else
      {
	map = "Map 1";
	mapName = "Library/Maps/2Player/p2_1.txt";
      }

      cout << "\033[2J\033[1;1H";
      cout << banner << endl;

      cout << "You have chosen " << map << " , is that correct? (Y/N) ";
      cin >> response;
      if ( cin.fail() )
      {
	cin.clear();
	cin.get();
	continue;
      }

      if ( response != "Y" && response != "N" )	// Handles case when user enters in the wrong response
      { response = "N"; }


      if ( response == "Y" )
      {
	cout << "\033[2J\033[1;1H";
	cout << banner << endl;

	string line;
	
	ifstream in(mapName);	// open file path for the desired map
	in >> line;
	in >> line;

	cout << map << endl << endl;

	for ( int i = 0; i < 26; ++i )	// read in map and display it on the screen
	{
	  in >> line;
	  cout << line << endl;
	}

	cout << "\n Would you like to use this map? (Y/N) ";
	cin >> response;
      if ( cin.fail() )
      {
	cin.clear();
	cin.get();
	continue;
      }

	if ( response != "Y" && response != "N" )	// Handles case when user enters in the wrong response
	{ response = "N"; }
      }

    }
    while ( response == "N" );

    // call map reader function
    mapReader(mapName, planets, gameMap); 

  }

  // handle 3 player maps

  if ( numPlayers == 3 )
  {
    do 
    {
      cout << "\033[2J\033[1;1H";
      cout << banner << endl;

      cout << "********* Maps *********" << endl << endl;
      cout << "A. Map 1		B. Map 2\nC. Map 3" << endl;
      cout << "\nEnter the letter of the map you would like to view: ";
      cin >> map;
      if ( cin.fail() )
      {
	cin.clear();
	cin.get();
	continue;
      }

      if ( map == "A" )
      {
	map = "Map 1";
	mapName = "Library/Maps/3Player/p3_1.txt";
      }
      else if ( map == "B" )
      {
	map = "Map 2";
	mapName = "Library/Maps/3Player/p3_2.txt";
      }
      else if ( map == "C" )
      {
	map = "Map 3";
	mapName = "Library/Maps/3Player/p3_3.txt";
      }
      else
      {
	map = "Map 1";
	mapName = "Library/Maps/3Player/p3_1.txt";
      }

      cout << "\033[2J\033[1;1H";
      cout << banner << endl;

      cout << "You have chosen " << map << " , is that correct? (Y/N) ";
      cin >> response;
      if ( cin.fail() )
      {
	cin.clear();
	cin.get();
	continue;
      }

      if ( response != "Y" && response != "N" )	// Handles case when user enters in the wrong response
      { response = "N"; }


      if ( response == "Y" )
      {
	cout << "\033[2J\033[1;1H";
	cout << banner << endl;

	string line;
	
	ifstream in(mapName);	// open file path for the desired map
	in >> line;
	in >> line;

	cout << map << endl << endl;

	for ( int i = 0; i < 26; ++i )	// read in map and display it on the screen
	{
	  in >> line;
	  cout << line << endl;
	}

	cout << "\n Would you like to use this map? (Y/N) ";
	cin >> response;
      if ( cin.fail() )
      {
	cin.clear();
	cin.get();
	continue;
      }

	if ( response != "Y" && response != "N" )	// Handles case when user enters in the wrong response
	{ response = "N"; }
      }

    }
    while ( response == "N" );

    // call map reader function
    mapReader(mapName, planets, gameMap); 
  }

  // handle 4 player maps

  if ( numPlayers == 4 )
  {
    do 
    {
      cout << "\033[2J\033[1;1H";
      cout << banner << endl;

      cout << "********* Maps *********" << endl << endl;
      cout << "A. Map 1		B. Map 2\nC. Map 3" << endl;
      cout << "\nEnter the letter of the map you would like to view: ";
      cin >> map;
      if ( cin.fail() )
      {
	cin.clear();
	cin.get();
	continue;
      }

      if ( map == "A" )
      {
	map = "Map 1";
	mapName = "Library/Maps/4Player/p4_1.txt";
      }
      else if ( map == "B" )
      {
	map = "Map 2";
	mapName = "Library/Maps/4Player/p4_2.txt";
      }
      else if ( map == "C" )
      {
	map = "Map 3";
	mapName = "Library/Maps/4Player/p4_3.txt";
      }
      else
      {
	map = "Map 1";
	mapName = "Library/Maps/3Player/p4_1.txt";
      }

      cout << "\033[2J\033[1;1H";
      cout << banner << endl;

      cout << "You have chosen " << map << " , is that correct? (Y/N) ";
      cin >> response;
      if ( cin.fail() )
      {
	cin.clear();
	cin.get();
	continue;
      }

      if ( response != "Y" && response != "N" )	// Handles case when user enters in the wrong response
      { response = "N"; }


      if ( response == "Y" )
      {
	cout << "\033[2J\033[1;1H";
	cout << banner << endl;

	string line;
	
	ifstream in(mapName);	// open file path for the desired map
	in >> line;
	in >> line;

	cout << map << endl << endl;

	for ( int i = 0; i < 31; ++i )	// read in map and display it on the screen
	{
	  in >> line;
	  cout << line << endl;
	}

	cout << "\n Would you like to use this map? (Y/N) ";
	cin >> response;
      if ( cin.fail() )
      {
	cin.clear();
	cin.get();
	continue;
      }

	if ( response != "Y" && response != "N" )	// Handles case when user enters in the wrong response
	{ response = "N"; }
      }

    }
    while ( response == "N" );

    // call map reader function
    mapReader(mapName, planets, gameMap); 
  }

  // handle 5 player maps

  if ( numPlayers == 5 )
  {
    do 
    {
      cout << "\033[2J\033[1;1H";
      cout << banner << endl;

      cout << "********* Maps *********" << endl << endl;
      cout << "A. Map 1		B. Map 2\nC. Map 3" << endl;
      cout << "\nEnter the letter of the map you would like to view: ";
      cin >> map;
      if ( cin.fail() )
      {
	cin.clear();
	cin.get();
	continue;
      }

      if ( map == "A" )
      {
	map = "Map 1";
	mapName = "Library/Maps/5Player/p5_1.txt";
      }
      else if ( map == "B" )
      {
	map = "Map 2";
	mapName = "Library/Maps/5Player/p5_2.txt";
      }
      else if ( map == "C" )
      {
	map = "Map 3";
	mapName = "Library/Maps/5Player/p5_3.txt";
      }
      else
      {
	map = "Map 1";
	mapName = "Library/Maps/5Player/p5_1.txt";
      }

      cout << "\033[2J\033[1;1H";
      cout << banner << endl;

      cout << "You have chosen " << map << " , is that correct? (Y/N) ";
      cin >> response;
      if ( cin.fail() )
      {
	cin.clear();
	cin.get();
	continue;
      }

      if ( response != "Y" && response != "N" )	// Handles case when user enters in the wrong response
      { response = "N"; }


      if ( response == "Y" )
      {
	cout << "\033[2J\033[1;1H";
	cout << banner << endl;

	string line;
	
	ifstream in(mapName);	// open file path for the desired map
	in >> line;
	in >> line;

	cout << map << endl << endl;

	for ( int i = 0; i < 31; ++i )	// read in map and display it on the screen
	{
	  in >> line;
	  cout << line << endl;
	}

	cout << "\n Would you like to use this map? (Y/N) ";
	cin >> response;
      if ( cin.fail() )
      {
	cin.clear();
	cin.get();
	continue;
      }

	if ( response != "Y" && response != "N" )	// Handles case when user enters in the wrong response
	{ response = "N"; }
      }

    }
    while ( response == "N" );

    // call map reader function
    mapReader(mapName, planets, gameMap); 
  }

  // handle 6 player maps

  if ( numPlayers == 6 )
  {
    do 
    {
      cout << "\033[2J\033[1;1H";
      cout << banner << endl;

      cout << "********* Maps *********" << endl << endl;
      cout << "A. Map 1		B. Map 2\nC. Map 3" << endl;
      cout << "\nEnter the letter of the map you would like to view: ";
      cin >> map;
      if ( cin.fail() )
      {
	cin.clear();
	cin.get();
	continue;
      }

      if ( map == "A" )
      {
	map = "Map 1";
	mapName = "Library/Maps/6Player/p6_1.txt";
      }
      else if ( map == "B" )
      {
	map = "Map 2";
	mapName = "Library/Maps/6Player/p6_2.txt";
      }
      else if ( map == "C" )
      {
	map = "Map 3";
	mapName = "Library/Maps/6Player/p6_3.txt";
      }
      else
      {
	map = "Map 1";
	mapName = "Library/Maps/6Player/p6_1.txt";
      }

      cout << "\033[2J\033[1;1H";
      cout << banner << endl;

      cout << "You have chosen " << map << " , is that correct? (Y/N) ";
      cin >> response;
      if ( cin.fail() )
      {
	cin.clear();
	cin.get();
	continue;
      }

      if ( response != "Y" && response != "N" )	// Handles case when user enters in the wrong response
      { response = "N"; }


      if ( response == "Y" )
      {
	cout << "\033[2J\033[1;1H";
	cout << banner << endl;

	string line;
	
	ifstream in(mapName);	// open file path for the desired map
	in >> line;
	in >> line;

	cout << map << endl << endl;

	for ( int i = 0; i < 31; ++i )	// read in map and display it on the screen
	{
	  in >> line;
	  cout << line << endl;
	}

	cout << "\n Would you like to use this map? (Y/N) ";
	cin >> response;
      if ( cin.fail() )
      {
	cin.clear();
	cin.get();
	continue;
      }

	if ( response != "Y" && response != "N" )	// Handles case when user enters in the wrong response
	{ response = "N"; }
      }

    }
    while ( response == "N" );

    // call map reader function
    mapReader(mapName, planets, gameMap); 
  }


  cout << "\033[2J\033[1;1H";
  cout << banner << endl;

  gameLoop(players,planets, gameMap);

  return 0;
}

