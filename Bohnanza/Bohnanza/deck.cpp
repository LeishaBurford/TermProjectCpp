#include "deck.h"


//Deck methods
Card* Deck::draw() {
    auto toReturn = back();

    pop_back();
    return toReturn;
}

void Deck::print(const ostream& out) const {
    for(auto card : *this) {//for(at(i))
        std::cout << *card << " ";
    }
    std::cout << std::endl;
}
