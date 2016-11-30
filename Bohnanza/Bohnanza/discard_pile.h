/*
The DiscardPile holds cards in a std::vector and is similar to Deck.

.
Also add the insertion operator to insert only the top card of the discard pile to an std::ostream. The DiscardPile needs a constructor which accepts an std::istream and reconstructs the
DiscardPile from file.

 
 */
#include "gemstones.h"
#include <vector>
#include "cardFactory.h"

class DiscardPile {
    friend ostream &operator<<(ostream& out, const DiscardPile& discardPile);
    void print( std::ostream& ) const;
public:
    DiscardPile() = default;
    DiscardPile( std::istream&, CardFactory* ); //TODO
    std::vector<Card*> pile;
    DiscardPile& operator+=( Card* );
    Card* pickUp();
    Card* top();    //maybe make private?
    
    
};

inline std::ostream& operator<< (std::ostream& o, const DiscardPile& discardPile)
{
    if(discardPile.pile.size() > 0){
        std::cout << *(discardPile.pile.back());
    }
    return o;
}
