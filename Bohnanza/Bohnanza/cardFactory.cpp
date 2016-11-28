//CardFactory generates all cards
#include <algorithm>    // std::shuffle
#include <random>       // std::mt19937 r{std::random_device{}()};

#include "cardFactory.h"

CardFactory *CardFactory::instance = 0;

CardFactory* CardFactory::getFactory(){
    if (!instance)
        instance = new CardFactory;
    return instance;
}

//return all 104 cards, shuffled
Deck CardFactory::getDeck(){
    return deck;
}


//create all cards needed
CardFactory::CardFactory(){
    //add cards with iterators to local deck*
    for(int i = 0; i < 20; i++) {
        deck.push_back(new Quartz());
    }
    for(int i = 0; i < 18; i++) {
        deck.push_back(new Hematite());
    }
    for(int i = 0; i < 16; i++) {
        deck.push_back(new Obsidian());
    }
    for(int i = 0; i < 14; i++) {
        deck.push_back(new Malachite());
    }
    for(int i = 0; i < 12; i++) {
        deck.push_back(new Turquoise());
    }
    for(int i = 0; i < 10; i++) {
        deck.push_back(new Ruby());
    }
    for (int i = 0; i < 8; i++) {
        deck.push_back(new Amethyst());
    }
    for (int i = 0; i < 6; i++) {
        deck.push_back(new Emerald());
    }
    std::mt19937 r{std::random_device{}()};
    std::shuffle(deck.begin(), deck.end(), r);
   

}
