//Matthew Dyer and Michael Lee
//gameloop function

#include <iostream>
#include <vector>
#include "gameLoop.h"
#include "Library/Planet.h"

//I couldnt get these two to compile in properly
//#include "Library/player.h"
//#include "Library/army.h"
//#include "battle.h"

using namespace std;

void gameLoop(){

	cout << "Are you ready to take some chances? (enter 'help' for more information)\n\n";

	//Player x = Player("Matt","Robot");
	int turn = 0;
	string command = "";
	string planet1 = "";
	string planet2 = "";
	int size = 0;

	while(cin){//is this a decent while condition?

		//here's where the fun begins
		//cout << "Your turn " << x.name << "\n";

		cout << "Enter a command:\n";
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
			if(command == "attack"){
				cout << "Now attacking " << planet2 << " from " << planet1 << " with " << size << " units.\n";
				//call battle with our information
			}else if(command == "move"){
				cout << "Now moving " << size << " units from " << planet1 << " to " << planet2 << "\n";
				//handle splitting and joining armies for movement
				//needs armies to work
			}
		}	
		
		//change the player and increment turn
		++turn;
	}

}
