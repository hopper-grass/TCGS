#include <stdio>

using namespace std

#ifndef
#define ARMY_H
plublic class Army{
    private:
        int m_size;
        Planet* m_loc;
        Player* m_owner;
    public:
        Army();
        Army(int s,Planet* p, Player* o);
        ~Army();
        int size();
        Planet* location();
        void reinforce(int amnt);
        void eliminate(int amnt);
        Army* split(int amnt);
        void join(Army* absorb);
        Player* whoOwnsArmy();
};
#endif
