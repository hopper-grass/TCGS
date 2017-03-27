#include <iostream>
#include <vector>
#include <queue>
#include "gameLoop.h"
#include "Library/Planet.h"
#include "Library/player.h"
#include "Library/army.h"
#include "battle.h"

using namespace std; 


int main()
{
  // New Game
  	// Num Players (2 min ; 6 max)
	// Choose Species & Name
	// Choose Map
  
  int numPlayers;
  string response, species, name;
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

      cout << "\033[2J\033[1;1H";
      cout << banner << endl;

      cout << "\nYou have chosen " << numPlayers << " players, is that correct? (Y/N) ";
      cin >> response;

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
      cout << "Enter the Letter of Species: ";
      cin >> species;

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

      cout << "\033[2J\033[1;1H";
      cout << banner << endl;
      cout << "PLAYER " << i+1 << endl << endl;

      cout << "You would like to be called:  " << name << " , is that correct? (Y/N) ";
      cin >> response;

      if (response != "Y" && response != "N" )	// Handles case when user enters in the wrong response
      { response = "N"; }

    }
    while (response == "N");

    Player* p = new Player(name, species);
    players.push(p);
    
  }


  /*
  	Allow the user to choose which map they would like to play on
		-> Give the user the option of viewing each available map according to the number of players that are playing 
  */


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


  cout << "\033[2J\033[1;1H";
  cout << banner << endl;

  gameLoop(players2,planets);

  return 0;
}

