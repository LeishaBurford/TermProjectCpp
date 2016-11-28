#ifndef chain_h
#define chain_h

#include <vector>
#include <exception>
#include <typeinfo>
#include "cardfactory.h"

class Chain_Base {};

template <class T>
class Chain : public Chain_Base {
    friend std::ostream &operator<<(std::ostream& out, const Chain<T>& chain);
    std::vector<T> chain;
    typename std::vector<T>::value_type type;
public:
    Chain<T>() = default;    //default constructor
    Chain( const std::istream&, CardFactory* ); // TODO
    Chain<T>& operator+=(T*);
    int sell();
};

inline std::ostream& operator<< (std::ostream& o, const Chain<Card*>& _chain)
{
    
    if(!_chain.chain.empty()){
        auto card = _chain.chain.back();
        o << card->getName() << " ";
        for(int i = 0; i < _chain.chain.size(); ++i) {
            o << *(_chain.chain.at(i)) << " ";
        }
        o << std::endl;
    }
    return o;
}

//Chain methods


//TODO
// The Chain needs a constructor which accepts an istream and reconstructs the chain from file when a game is resumed.
template <class T>
Chain<T>::Chain( const std::istream&, CardFactory* ){}

// adds a card to the Chain. If the run-time type does not match the template type of the chain and exception of type IllegalType needs to be raised.
template<class T>//method calling this must handle exception
Chain<T>& Chain<T>::operator+=( T* card){
    try {
        //auto _card = dynamic_cast<Card*>(card);
        //std::cout << typeid(type).name() << " " << typeid(card).name() << std::endl;
        if(typeid(type) != typeid(card)) {
            throw std::invalid_argument("Cannot add card to this chain");
        }
        chain.push_back(*card);
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

#endif /* chain_h */
