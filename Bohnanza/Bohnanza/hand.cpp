
#include "hand.h"


//adds the card to the rear of the hand
Hand& Hand::operator+=(Card* card) {
    return *this;
}

// returns and removes the top card from the player's hand.
Card* Hand::play() {
    return hand.back();
}


// returns but does not remove the top card from the player's hand.
Card* Hand::top() {
    return hand.back();
}

//returns and removes the Card at a given index.
Card* Hand::operator[](int) {
    return hand.back();
    
}

