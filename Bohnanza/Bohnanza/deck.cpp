#include "deck.h"


//Deck methods
Card* Deck::draw() {
    auto toReturn = back();
    pop_back();
    return toReturn;
}

Deck::Deck(std::istream& in, CardFactory* factory){
    char ch;
    while (in >> ch && ch != '*') {
        this->push_back(factory->getCard(ch));
    }
}
