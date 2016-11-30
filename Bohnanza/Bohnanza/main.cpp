//#include <iostream>

#include <string>
#include <exception>
#include "chain.h"
#include "cardfactory.h"
#include "player.h"
#include "discard_pile.h"
#include "trade_area.h"

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
    //Chain<Ruby> rchain =leisha.operator[]<Ruby>(0);//cast into child class
    Chain<Ruby> rchain;
    Card* rcard = new Ruby();
    rchain += rcard;
    std::cout << *rchain.chain.back();
    //std::cout << rchain << std::endl;
    //leisha.operator[0]<Ruby>..operator+=(card);
    std::cout << "Leisha test\n" << leisha << std::endl;
    //Chain_Base* chain = &(leisha.operator[]<Card>(0));
    
    //std::cout << *chain1 << std::endl;
    //*(chain1) += *card;
    //card = deck.draw();
    //*(chain1) += card;
    
    //testing DiscardPile - its working :)
    std::cout << "DiscardPile test" << std::endl;
    DiscardPile pile;
    pile.operator+=(card);
    std::cout << pile;
    auto card2 = pile.pickUp();
    std::cout << *card2 << std::endl;
    //std::cout << leisha;
    
    //testing tradeArea
    std::cout << "TradeArea test" << std::endl;
    TradeArea tradeArea;
    tradeArea.operator+=(card);
    std::cout << tradeArea;
    std::cout << "should be true: " << tradeArea.legal(card) << std::endl;
    tradeArea.trade(card->getName());
    std::cout << "should be empty: " << tradeArea<< std::endl;
    
    
    delete factory ;
}
