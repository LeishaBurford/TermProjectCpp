

#include "discard_pile.h"



DiscardPile::DiscardPile( std::istream& i, CardFactory* factory){
    char ch;
    while (i >> ch && ch != '*') {
        pile.push_back(factory->getCard(ch));
    }
}

//discards the card to the pile.
DiscardPile& DiscardPile::operator+=( Card* card) {
    pile.push_back(card);
    return *this;
}

//returns and removes the top card from the discard pile.
Card* DiscardPile::pickUp() {
    auto card = top();
    pile.pop_back();
    return card;
}

// returns but does not remove the top card from the discard pile.
Card* DiscardPile::top() {
    return pile.back();
}

void DiscardPile::print( std::ostream& out) const {
    for(auto card : pile) {
        std::cout << *card << " ";
    }
    std::cout << std::endl;
}
