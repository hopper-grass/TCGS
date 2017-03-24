#include <stdio.h> // fixed the missing .h typo --Matt

using namespace std

public class Army{ //Fixed the "plublic" typo --Matt
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
