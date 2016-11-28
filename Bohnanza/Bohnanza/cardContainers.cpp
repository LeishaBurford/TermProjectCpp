/*We note that Deck, DiscardPile, TradeArea,Hand and Chain are all containers holding cards.

Deck will initially hold all the cards which will have to be shuffled to produce a randomized order, then players' hands are dealt and during game play players draw cards from the Deck
	 extend a std::vector

DiscardPile 
	 extend a std::vector will work fine, but here we can use simple aggregation

TradeArea
	 extend a std::vector

Hand players have to keep their hand in order and the first card drawn is the first card played.
	Therefore, we can use a std::vector to remove at an arbitrary location with a std::queue adapter

	Chain
	extend a std::vector
	will hold the cards by pointer in a std::vector<GemName*>*/


#include "Header.h"
#include <exception>
#include <typeinfo>

//Deck methods
Card* Deck::draw() {
    auto toReturn = Deck::cards.back();
    Deck::cards.pop_back();
    return toReturn;
}

void Deck::print(const ostream& out) const {
    for(auto card: Deck::cards) {
        //deck.cards.back()->print(o);
        //card->print(out);
        std::cout << *card << " ";
    }
    std::cout << std::endl;
}

//Chain methods


//TODO
// The Chain needs a constructor which accepts an istream and reconstructs the chain from file when a game is resumed.
template <class T>
Chain<T>::Chain( const std::istream&, CardFactory* ){}

// adds a card to the Chain. If the run-time type does not match the template type of the chain and exception of type IllegalType needs to be raised.
template<class T>//method calling this must handle exception
Chain<T>& Chain<T>::operator+=( T card){
    try {
        //auto _card = dynamic_cast<Card*>(card);
        //std::cout << typeid(type).name() << " " << typeid(card).name() << std::endl;
        if(typeid(type) != typeid(card)) {
            throw std::invalid_argument("Cannot add card to this chain");
        }
        chain.push_back(card);
    } catch(const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }
    return *this;
}
//counts the number cards in the current chain and returns the number coins according to the function Card::getCardsPerCoin. TODO check if working
//when called, update player num active coins
template<class T>
int sell(){
    int total = 0;
    while(Chain<T>::chain.back()) {
        total += Chain<T>::chain.back()->getCardsPerCoin(Chain<T>::chain.size());
        Chain<T>::chain.pop_back();
    }
    return total;
}

template class Chain<Card*>;
template class Chain<Quartz>;
template class Chain<Hematite>;
template class Chain<Obsidian>;
template class Chain<Malachite>;
template class Chain<Turquoise>;
template class Chain<Ruby>;
template class Chain<Amethyst>;
template class Chain<Emerald>;












