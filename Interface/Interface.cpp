#include <iostream>
#include "../Library/player.h"
//#include "../Library/army.h"
#include "../Library/Planet.h"
#include <vector>
#include <string>

using namespace std; 

void addPlayer(vector<Player*> players, Player* p)
{
  players.push_back (p);
}

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

  vector<Player*> players;	


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
    addPlayer(players, p);

    // add Player object to vector

    //players.push_back (new Player(name, species));

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

}

