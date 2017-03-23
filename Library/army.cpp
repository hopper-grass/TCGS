#include "army.h"

/**
 * Default constructor
 */
Army::Army(){
    m_size = 0;
    m_loc = NULL;
    m_owner = NULL;
}

/**
 * Full Constructor
 * @Param[in] s int representing size
 * @Param[in] p pointer to the planet the army is on
 * @Param[in] o pointer to the owner of the planet
 */
Army::Army(int s, Planet* p, Player* o){
    m_size = s;
    m_loc = p;
    m_owner = o;
}

/**
 * Default Destructor
 */
Army::~Army(){
    delete m_loc;
    delete m_owner;
}
/**
 * Accessor for m_size
 * @Param[out] m_size the size of the army
 */
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
