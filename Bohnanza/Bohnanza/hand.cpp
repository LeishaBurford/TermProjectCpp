
#include "hand.h"

Hand::Hand( std::istream& i, CardFactory* factory) {
    char ch;
    while (i >> ch && ch != '*') {
        hand.push(factory->getCard(ch));
    }

}

//adds the card to the rear of the hand
Hand& Hand::operator+=(Card* card) {
    hand.push(card);
    return *this;
}

// returns and removes the top card from the player's hand.
Card* Hand::play() {
    auto card = top();
    hand.pop();
    return card;
}


// returns but does not remove the top card from the player's hand.
Card* Hand::top() {
    return hand.front();
}

//returns and removes the Card at a given index.
//add handler for index out of bounds
Card* Hand::operator[](int j) {
    Card* card = nullptr;
    std::queue<Card*, std::list<Card*>> temp;
    int handSize = (int)hand.size();
    for(int i = 0; i < handSize; i++) {
        if(i == j){         // this is the card to remove
            card = play();   // card is now pointing to indexed value, to be returned.
                            // card is removed from queue
        }else {
            temp.push(play());    //card not to be removed, put in temp
        }
    }
    hand = temp;
    return card;    //returns nullptr if index not in range
}

void Hand::print(std::ostream&) const {
    std::queue<Card*, std::list<Card*>> temp(hand);
    for(int i = 0; i < hand.size(); i++) {
        auto card = temp.front();
        std::cout << *card << " ";
        temp.pop();
    }
}

