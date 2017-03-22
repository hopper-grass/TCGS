#include "army.h"

/**
 * Default constructor
 */
Army::Army(){
    m_size = 0;
    m_loc = NULL;
    m_owner = NULL;
}

Army::Army(int s, Planet* p, Player* o){
    m_size = s;
    m_loc = p;
    m_owner = o;
}

Army::~Army{
    delete m_loc;
    delete m_owner
}

int size(){
    return m_size;
}

Planet* location(){
    return m_loc;
}

void reinforce(int amnt){
    m_size += amnt;
}

void eliminate(int amnt){
    m_size -= amnt;
    if(m_size < 0){
        m_size = 0;
    }
}

Army* split(int amnt){
    //TODO:Make logic so we can't reduce army size below 0
    m_size -= amnt;
    return new Army(amnt, m_loc, m_owner);
}

void join(Army* absorb){
    if(m_owner == absorb->whoOwnsArmy() && m_loc == absorb->location()){
        m_size += absorb->size();
        delete absorb;
    }
}

Player* whoOwnsArmy(){
    return m_owner;
}
