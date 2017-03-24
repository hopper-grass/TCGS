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
	string command = "";
	string planet1 = "";
	string planet2 = "";
	int size = 0;

	while(cin){//is this a decent while condition?

		//here's where the fun begins
		cout << "Enter a command (type 'help' for more information):\n";
		cin >> command;

		if(command == "help"){
			//print out help menu
			cout << "The following are valid commands:\n";
			cout << "\t- attack [from this planet] [to this planet] [size of army]\n";
			cout << "\t\t-> example: attack A C 50\n";
			cout << "\t- move [from this planet] [to this planet] [size of army]\n";
			cout << "\t\t-> example: move A B 25\n";
			cout << "\t- end\n";
			cout << "\t\t-> used to end your turn\n";
			cout << "\t- quit\n";
			cout << "\t\t-> quit the game\n";
		}else if(command == "quit"){
			cout << "Thanks for playing!\n";
			break;
		}else if(command == "end"){
			//end the turn?
			cout << "Turn Ended\n";
		}else{ //read in the rest
			cin >> planet1;
			cin >> planet2;
			cin >> size;
		}	
		
		//change the player and increment turn
		++turn;
	}

}
