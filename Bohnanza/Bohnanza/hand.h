#ifndef hand_h
#define hand_h

#include "cardFactory.h"
#include "gemstones.h"
#include <queue>
#include <list>

class Hand {
    friend ostream &operator<<(ostream& out, const Hand& hand);
    std::queue<Card*, std::list<Card*>> hand;
   
public:
    Hand() = default;
    Hand( std::istream&, CardFactory* );
    Hand& operator+=(Card*);
    Card* play();
    Card* top();
    Card* operator[](int);
    void print(std::ostream&) const;
};

inline std::ostream& operator<< (std::ostream& o, const Hand& hand)
{
    hand.print(o);
    return o;
}

#endif /* hand_h */
