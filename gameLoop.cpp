//Matthew Dyer and Michael Lee
//gameloop function

#include <iostream>
#include <vector>
#include "gameLoop.h"
#include "Library/Planet.h"
//#include "Library/player.h"
//#include "Library/army.h"

using namespace std;

void gameLoop(){
	
	int turn = 0;
//	while(){//while condition?

		//here's where the fun begins
		string command = "";
		cout << "Enter a command (type 'help' for help)\n";
		getline(cin, command);
		
		if(command == "help"){
			//print out help menu
			cout << "The following are valid commands:\n";
			cout << "\t- attack [from this planet] [to this planet] [size of army]\n";
			cout << "\t\t-> example: attack A C 50\n";
			cout << "\t- move [from this planet] [to this planet] [size of army]\n";
			cout << "\t\t-> example: move A B 25\n";
		}	
		
		//change the player and increment turn
		++turn;
//	}

}
