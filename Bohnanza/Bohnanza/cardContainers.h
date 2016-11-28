/*
 Deck will initially hold all the cards which will have to be shuffled to produce a randomized order, then players' hands are dealt and during game play players draw cards from the Deck
 extend a std::vector
 */
#ifndef cardContainers_h
#define cardContainers_h

#include <vector>
#include "Header.h"


class Deck {
    friend ostream &operator<<(ostream& out, const Deck& deck);
    std::vector<Card*> cards;
    void print(const ostream& out) const;
public:

    Deck(std::vector<Card*> _cards) : cards(_cards){}
    Card* draw(); 
    //Deck(const istream&, CardFactory*) TODO
};

inline std::ostream& operator<< (std::ostream& o, const Deck& deck)
{
    deck.print(o);
    return o;
}

class Chain_Base {
public:
    Chain_Base& getChain(int);
};

template <class T>
class Chain : public Chain_Base {
    friend ostream &operator<<(ostream& out, const Chain<T>& chain);
    std::vector<T> chain;
    typename std::vector<T>::value_type type;
public:
    Chain<T>() = default;    //default constructor
    Chain( const std::istream&, CardFactory* ); // TODO
    Chain<T>& operator+=(T);
    int sell();
};

inline std::ostream& operator<< (std::ostream& o, const Chain<Card*>& _chain)
{
    
    if(!_chain.chain.empty()){
        auto card = _chain.chain.back();
        o << card->getName() << " ";
        for(int i = 0; i < _chain.chain.size(); ++i) {
            o << *(_chain.chain.at(i)) << " ";
        }
        o << std::endl;
    }
    return o;
}

class Hand {
    
    
};



#endif /* cardContainers_h */
