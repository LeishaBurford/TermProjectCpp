#ifndef hand_h
#define hand_h

#include "cardFactory.h"
#include "gemstones.h"
#include <queue>
#include <list>

class Hand {
    std::queue<Card*, std::list<Card*>> hand;
   
public:
    Hand() = default;
    Hand( std::istream&, CardFactory* );
    Hand& operator+=(Card*);
    Card* play();
    Card* top();
    Card* operator[](int);
};

#endif /* hand_h */
