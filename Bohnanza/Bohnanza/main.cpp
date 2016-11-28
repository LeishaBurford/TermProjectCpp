//#include <iostream>

#include <string>
#include <exception>
#include "chain.h"
#include "cardfactory.h"

int main() {
    CardFactory* factory = CardFactory::getFactory();
    
    std::cout << factory->getDeck();
    auto card = factory->getDeck().draw();
    std::cout << *card << std::endl;
    //std::string p1Name("Leisha");
    //testing player class
    //Player leisha = Player(p1Name);
    //std::cout << leisha;
    //testing adding coins
    //leisha += 50;
    //auto card = deck.draw();
    //std::cout << typeid(*card).name() << std::endl;
    //testing chain, adding card to chain
   // Chain<Card*> *chain1 = &(leisha.operator[]<Card*>(0));
    //*(chain1) += card;
    //card = deck.draw();
    //*(chain1) += card;

    //std::cout << leisha;
    
    delete factory ; 
}
