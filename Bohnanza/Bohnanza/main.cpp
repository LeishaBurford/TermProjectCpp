//#include <iostream>

#include <string>
#include <exception>
#include "chain.h"
#include "cardfactory.h"
#include "player.h"
#include "discard_pile.h"

int main() {
    CardFactory* factory = CardFactory::getFactory();
    
    std::cout << factory->getDeck();
    auto card = factory->getDeck().draw();
    std::cout << *card << std::endl;
    std::string p1Name("Leisha");
    //testing player class
    Player leisha = Player(p1Name);
    std::cout << leisha;
    //testing adding coins
    leisha += 50;
    std::cout << leisha;
    //std::cout << typeid(*card).name() << std::endl;
    //testing chain, adding card to chain
    //Chain_Base* chain1 = &(leisha.operator[]<Card>(0));
    //std::cout << *chain1 << std::endl;
    //*(chain1) += *card;
    //card = deck.draw();
    //*(chain1) += card;
    
    //testing DiscardPile - its working :)
    DiscardPile pile;
    pile.operator+=(card);
    std::cout << pile;
    auto card2 = pile.pickUp();
    std::cout << *card2 << std::endl;
    //std::cout << leisha;
    
    delete factory ; 
}
