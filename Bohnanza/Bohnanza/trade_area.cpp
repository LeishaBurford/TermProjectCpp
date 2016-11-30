#include "trade_area.h"


//adds the card to the tradearea but it does not check if it is legal to place the card.
TradeArea& TradeArea::operator+=( Card* card) {
    _tradeArea.push_back(card);
    return *this;
}

//returns true if the card can be legally added to the TradeArea,i.e.,a card of the same gemstone is already in the TradeArea.
bool TradeArea::legal( Card* _card) {
    for(auto card : _tradeArea) {
        if(card->getName() == _card->getName()) {
            return 1;
        }
    }
    return 0;
}

//removes a card of the corresponding gemstone name from the tradearea.
Card* TradeArea::trade( std::string name) {
    Card* card;
    for (std::list<Card*>::const_iterator i = _tradeArea.begin(), end = _tradeArea.end(); i != end; ++i) {
        if((*i)->getName() == name) {
            card = *i;
            _tradeArea.remove(*i);
            break;
        }
    }
    return card;    //returns null card if card not found
}

//returns the number of cards currently in the tradearea
int TradeArea::numCards() {
    return (int)_tradeArea.size();
}


void TradeArea::print(const ostream& out) const {
    for(auto card : _tradeArea) {
        std::cout << *card << " ";
    }
}
