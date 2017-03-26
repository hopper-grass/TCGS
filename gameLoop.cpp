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

void gameLoop(queue<Player*> players, vector<Planet*> planets){//player will give us all players, planet all planets.  We can do without planets, but it's annoying, so just have it passed in.
//Now has function parameters.

	cout << "Are you ready to take some chances? (enter 'help' for more information)\n\n";

	int turn = 0;
	string command = "";
	string planet1 = "";
	string planet2 = "";
	int size = 0;

	//Nah, we need the game loop to end at some point, I propose the following:
	while(players.size() > 1){ //and then when players are dead, remove them from queue

		//here's where the fun begins
		Player* current = players.front();
		/*if(current->isDead())
		{
		  players.pop();
		  continue;
		}*/
		cout << "Your turn " << current->name << "\n";
		cout << "Turn " << turn << "\n";

		//We really need to cout Map and armies at some point
		bool canAttack=true;
		bool canMove=true; //only one attack and move
		while(canAttack or canMove){
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
			  exit(0); //we're going to want to just end the whole program at this point.
		  }else if(command == "end"){	
			  //change the player and increment turn
		    	  canAttack=false;
			  canMove=false;
			  //it's easier to auto-end turns like this
		  }else{ //read in the rest
			  cin >> planet1;
			  cin >> planet2;
			  cin >> size;
			  vector<Planet*> playerPlans = current->planetsHeld();
			  Planet *plan1;
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
				  cout << "Now attacking " << planet2 << " from " << planet1 << " with " << size << " units.\n";
				  //call battle with our information
				  //Now conveniently stored in plan1 and plan2!!!
				  canAttack=false;//Note that player has made their attack
			  }else if(command == "move"){
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
				  cout << "Now moving " << size << " units from " << planet1 << " to " << planet2 << "\n";
				  Army* temp = plan1->armyHeld()->split(size);
				  plan2->armyHeld()->join(temp);
				  canMove=false;
			  }	
		  }
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
  int rein = plans.size()/3;
  if(rein>0)
    cout << "Reinforcement phase\nEnter <planet> <number> to reinforce\n";
  while (rein >= 0)
  {
    cout << "Have "<<rein<<" reinforcements remaining";
    string planet;
    int num;
    cin >> planet;
    cin >> num;
    Planet* plan;
    bool isOwned=false;
    for(unsigned int i=0; i<plans.size(); i++)
      if(plans[i]->name()==planet)
      {
	isOwned=true;
	plan= plans[i];
	break;
      }
    if(!isOwned)
    {
      cout << "Please input a planet you own\n";
      continue;
    }
    if(num>rein)
    {
      cout << "Please input a number no larger than "<<rein <<endl;
      continue;
    }
    Army* army = plan->armyHeld();
    army->reinforce(num);
  }
  cout << "All reinforcements placed\n";
}