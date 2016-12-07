#ifndef deck_h
#define deck_h
#include "gemstones.h"
#include "cardFactory.h"
#include <vector>
#include <fstream>
#include <iostream>

class CardFactory;

class Deck : public std::vector<Card*>{
    friend ostream &operator<<(ostream& out, const Deck& deck);

public:
    Deck() : std::vector<Card*>() {};
    
    Card* draw();
    ~Deck(){
        
    }
   Deck(std::istream&, CardFactory*);
};

inline std::ostream& operator<< (std::ostream& o, const Deck& deck){
    for(auto card : deck) {
        o << *card;
    }
    return o;
}

#endif /* deck_h */
