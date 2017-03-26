#include "battle.h"
void seed(){
  srand(time(0));
}
void battle(Army* attacker, Army* defender){
  while(attacker->size() > 0 && defender->size() > 0){
    vector<int> aRolls, dRolls;
    int units,aLoss=0,bLoss=0;

    for(int i = 0; i < attacker->size();++i){
      aRolls.push_back(rollDie());
    }
    for(int i = 0; i < defender->size();++i){
      dRolls.push_back(rollDie());
    }

    sort(aRolls.end(),aRolls.begin());
    sort(dRolls.end(),dRolls.begin());

    if(aRolls.size() < dRolls.size()){
      units = aRolls.size();
    }else{
      units = dRolls.size();
    }

    for(int i = 0;i<units;++i){
      if(aRolls[i] > dRolls[i]){
        bLoss++;
      }else{
        aLoss++;
      }
    }
    
    if(attacker->size() - aLoss <= 0){//if attacker loses more than it has then delete it
      delete attacker;
      if(defender->size() - bLoss <= 0){ //If both are reduced to 0 leave defender with 1 unit
        defender->eliminate(defender->size()-1);
        return;
      }
    }else{
      attacker->eliminate(aLoss);//otherwise reduce by loss
    }

    if(defender->size() - bLoss <= 0){//if defender loses more than it has then delete it
      delete defender;
    }else{
		defender->eliminate(bLoss);//otherwise reduce by loss
    }
    
  }
}

int rollDie(){
  return ((rand()%6));
}
