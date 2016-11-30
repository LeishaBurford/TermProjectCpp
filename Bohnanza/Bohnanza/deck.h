#ifndef deck_h
#define deck_h

#include "gemstones.h"
#include <vector>

class Deck : public std::vector<Card*>{
    friend ostream &operator<<(ostream& out, const Deck& deck);
    void print(const ostream& out) const;

public:
    Deck() : std::vector<Card*>() {};
    Card* draw();
    //Deck(const istream&, CardFactory*) TODO
};

inline std::ostream& operator<< (std::ostream& o, const Deck& deck){
    deck.print(o);
    return o;//cout << 5;
}

#endif /* deck_h */
