//Matthew Dyer and Michael Lee
//gameloop function

#include <iostream>
#include <vector>
#include <queue>
#include "gameLoop.h"
#include "Library/Planet.h"
#include "Library/player.h"
#include "Library/army.h"
#include "battle.h"

using namespace std;

void reinforce(Player* player);

void gameLoop(queue<Player*> players, vector<Planet*> planets, vector<string> map){//player will give us all players, planet all planets.  We can do without planets, but it's annoying, so just have it passed in.
	//Now has function parameters.
	seed();

	//cout << "Are you ready to take some chances? (enter 'help' for more information)\n\n";

	int turn = 0;
	string command = "";
	string planet1 = "";
	string planet2 = "";
	int size = 0;
	string banner = "----------------------------------------------------------\n|********** Taking Chances on a Galactic Scale **********|\n----------------------------------------------------------\n";

	while(players.size() > 1){ 

		//here's where the fun begins
		Player* current = players.front();
		if(current->isDead())
		{
			players.pop();
			continue;
		}

		cout << "\033[2J\033[1;1H";
		cout << banner << endl;
		cout << "Your turn " << current->name << "\n";

		for(unisigned int i = 0; i < map.size(); ++i){
			cout << map[i] << "\n";
		}

		cout << "You own the following planets: \n";
		vector<Planet*> playerPlans = current->planetsHeld();
		for(unsigned int i=0; i<playerPlans.size(); i++){
			cout << playerPlans[i]->name() << " ";
			cout << playerPlans[i]->armiesHeld() << "\n";
		}

		cout << "Turn " << turn << "\n";

		//We really need to cout Map and armies at some point
		bool canAttack=true;
		bool canMove=true; //only one attack and move
		while(canAttack or canMove){
			cout << "Enter a command:\n";

			while(cin >> command){

				if(command != "help" && command != "quit" && command != "end" && command != "view" && command != "attack" && command != "move"){
					cout << "Not a valid command. Type 'help' for a list of commands.\n";
				}else{
					break;
				}
			}

			if(command == "help"){
				//print out help menu
				cout << "The following are valid commands:\n";
				cout << "\t- attack [from this planet] [to this planet] [size of army]\n";
				cout << "\t\t-> example: attack A C 50\n";
				cout << "\t- move [from this planet] [to this planet] [size of army]\n";
				cout << "\t\t-> example: move A B 25\n";
				cout << "\t- view\n";
				cout << "\t\t-> view game information\n";
				cout << "\t- end\n";
				cout << "\t\t-> used to end your turn\n";
				cout << "\t- quit\n";
				cout << "\t\t-> quit the game\n";
			}else if(command == "quit"){
				cout << "Thanks for playing!\n";
				exit(0); //we're going to want to just end the whole program at this point.
			}else if(command == "end"){	
				//change the player and increment turn
				canAttack=false;
				canMove=false;
				//it's easier to auto-end turns like this

			}else if(command == "view"){
				cout << "Planet:\tUnits:\tOwner:\n";
				for(unsigned int i=0; i<planets.size(); i++){
					cout << planets[i]->name() << "\t";
					cout << planets[i]->armiesHeld() << "\t";
					cout << planets[i]->whoOwnsPlanet() << "\n";
				}

			}else{ //read in the rest
				cin >> planet1;
				cin >> planet2;
				cin >> size;
				if (cin.fail())
				{
				  cout<<"Please enter a number for number of units.\n";
				  cin.clear();
				  cin.get(); //cleaning up cin is a pain...
				  continue;
				}
				vector<Planet*> playerPlans = current->planetsHeld();
				Planet* plan1;
				bool isOwned=false;
				for(unsigned int i=0; i<playerPlans.size(); i++)
					if(playerPlans[i]->name()==planet1)
					{
						isOwned=true;
						plan1= playerPlans[i];
						break;
					}
				if(!isOwned)
				{
					cout << "Please input a planet you own for the planet being moved from\n";
					continue;
				}
				if(size >= plan1->armiesHeld())
				{
					cout << "You must leave at least one unit behind\n";
					continue;
				}
				if(command == "attack"){
				  	if(!canAttack)
					{
					  cout << "You have already attacked this turn.  Please move or end your turn.\n";
					  continue;
					}
					bool isValid=true;
					for(unsigned int i=0; i<playerPlans.size(); i++)
						if(playerPlans[i]->name()==planet2)
						{
							isValid=false;
							break;
						}
					if(!isValid)
					{
						cout <<"You can only attack planets you don't own\n";
						continue;
					}
					Planet* plan2;
					isValid=false;
					for(unsigned int i=0; i<planets.size(); i++)
						if(planets[i]->name()==planet2)
						{
							isValid=true;
							plan2= planets[i];
							break;
						}
					if(!isValid)
					{
						cout<<"Please input an opponent's planet to attack\n";
						continue;
					}
					isValid=false;
					vector<string> cons = plan1->allConnections();
					for(unsigned int i=0; i<cons.size(); i++)
					{
						if(cons[i]==plan2->name())
							isValid=true;
					}
					if(!isValid)
					{
						cout << "Those planets are not connected\n";
						continue;
					}
					cout << "Now attacking " << planet2 << " from " << planet1 << " with " << size << " units.\n";
					//call battle with our information
					//Now conveniently stored in plan1 and plan2!!!
					Army* battleArmy = new Army(size);
					plan1->armyHeld()->eliminate(size);

					bool result = battle(battleArmy, plan2->armyHeld());

					if(result){
						cout << "Victory! The planet is yours\n"<<battleArmy->size()<<" units survived!\n";
						plan2->army = battleArmy;
						Player* loser;
						for(unsigned int i=0; i<players.size(); i++)
						{
							Player* temp = players.front();
							players.pop();
							players.push(temp);
							vector<Planet*> tempP = temp->planetsHeld();
							for(unsigned int j=0; j<tempP.size(); j++)
							{
								if (tempP[j]==plan2)
								{
									loser=temp;
								}
							}
						}
						loser->losePlanet(plan2);
						current->gainPlanet(plan2);
						plan2->setOwner(current->name);
						if((loser->isDead()) && (players.size() == 2))
						{
							cout << "Congratulations, you won!\n";
							return;
						}
					}else{
						cout << "You suffered a tragic defeat\n";
					}

					cout << "\nYou currently own the following planets: \n";
					vector<Planet*> playerPlans = current->planetsHeld();
					for(unsigned int i=0; i<playerPlans.size(); i++){
						cout << playerPlans[i]->name() << " ";
						cout << playerPlans[i]->armiesHeld() << "\n";
					}

					canAttack=false;//Note that player has made their attack
				}else if(command == "move"){
				  	if(!canMove)
					{
					  cout << "You have already moved this turn.  Please attack or end your turn.\n";
					  continue;
					}
					Planet* plan2;
					isOwned=false;
					for(unsigned int i=0; i<playerPlans.size(); i++)
						if(playerPlans[i]->name()==planet2)
						{
							isOwned=true;
							plan2= playerPlans[i];
							break;
						}
					if(!isOwned)
					{
						cout << "Please input a planet you own for the planet being moved to\n";
						continue;
					}
					bool isCon=false;
					vector<string> cons = plan1->allConnections();
					for(unsigned int i=0; i<cons.size(); i++)
					{
						if(cons[i]==plan2->name())
							isCon=true;
					}
					if(!isCon)
					{
						cout << "Those planets are not connected\n";
						continue;
					}
					cout << "Now moving " << size << " units from " << planet1 << " to " << planet2 << "\n";
					Army* temp = plan1->armyHeld()->split(size);
					plan2->armyHeld()->join(temp);

					cout << "\nYour planets after the move: \n";
					vector<Planet*> playerPlans = current->planetsHeld();
					for(unsigned int i=0; i<playerPlans.size(); i++){
						cout << playerPlans[i]->name() << " ";
						cout << playerPlans[i]->armiesHeld() << "\n";
					}
					canMove=false;
				}	
			}
			command = "";
		}
		reinforce(current);	
		players.pop();
		players.push(current);
		++turn;
		cout << "Your turn has ended\n";

	}

}

void reinforce(Player* player)
{
	vector<Planet*> plans = player->planetsHeld();
	int rein = plans.size();
	if(rein>0)
		cout << "\nReinforcement phase:\nEnter '<planet> <number>' to reinforce\n";
	while (rein >= 0)
	{
		if(rein == 0){
			cout << "You have "<< rein <<" reinforcements remaining\n";
			break;
		}
		cout << "You have "<< rein <<" reinforcements remaining\n";
		string planet;
		int num;
		cin >> planet;
		cin >> num;
		if (cin.fail())
		{
		  cout<<"Please enter a number for number of units.\n";
		  cin.clear();
		  cin.get(); //cleaning up cin is a pain...
		  continue;
		}
		Planet* plan;
		bool isOwned=false;
		for(unsigned int i=0; i<plans.size(); i++)
			if(plans[i]->name()==planet)
			{
				isOwned=true;
				plan = plans[i];
				break;
			}
		if(!isOwned)
		{
			cout << "Please input a planet you own\n";
			continue;
		}
		if(num>rein)
		{
			cout << "Please input a number no larger than "<< rein << endl;
			continue;
		}
		Army* army = plan->armyHeld();
		army->reinforce(num);
		rein = rein - num;
	}
	cout << "All reinforcements placed\n";
}
