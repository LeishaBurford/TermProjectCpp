#ifndef hand_h
#define hand_h

#include "cardFactory.h"
#include "gemstones.h"
#include <queue>

class Hand {
    std::queue<Card*, std::vector<Card*>> hand;
   
public:
    Hand() = default;
    Hand( std::istream&, CardFactory* );
    Hand& operator+=(Card*);
    Card* play();
    Card* top();
    Card* operator[](int);
};

#endif /* hand_h */
