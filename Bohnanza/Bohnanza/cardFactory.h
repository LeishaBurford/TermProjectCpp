
#ifndef cardfactory_h
#define cardfactory_h

#include <vector>
#include "deck.h"

//class Deck;
/*
 we need a public method in CardFactory to obtain a pointer to an object of the correct subclass of Card. This has been left out on purpose but here you need to add a public method to the CardFactory.
 */
class CardFactory {
    static CardFactory *instance;
public:
    static CardFactory* getFactory();
    Deck getDeck();
    ~CardFactory(){
        for(auto card : deck){
            delete card;
        }
    }
private:
    Deck deck;
    //std::vector<Card*> deck;
    CardFactory();
    CardFactory(const CardFactory&) = delete;
    // I am just doing a practice test for changing through git 

};

#endif /* cardfactory_h */
