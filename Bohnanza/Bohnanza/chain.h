#ifndef chain_h
#define chain_h

#include <vector>
#include <exception>
#include <typeinfo>
#include "cardfactory.h"

class Chain_Base {
  //  friend std::ostream &operator<<(std::ostream& out, const Chain_Base& chain_base);
public:
    virtual int sell() = 0;
    virtual Chain_Base& operator+=(Card*) =0;
    
};

template <class T>
class Chain : public Chain_Base {
    friend std::ostream &operator<<(std::ostream& out, const Chain<T>& chain);
    //std::vector<Card*> chain;
    T* type;
public:
    std::vector<Card*> chain; //make private after testing!
    Chain() = default;
    //Chain<T>(string){
    //    chain<Ruby>
    
    Chain( const std::istream&, CardFactory* ){}; // TODO
    
    // adds a card to the Chain. If the run-time type does not match the template type of the chain an exception of type IllegalType needs to be raised.
    Chain<T>& operator+=(Card* card) {
        chain.push_back(card);
        return *this;
    }
    
    //counts the number cards in the current chain and returns the number coins according to the function Card::getCardsPerCoin. TODO check if working
    //when called, update player num active coins
    int sell() {
        if(!chain.empty()){
            
            T* card =dynamic_cast<T*>(chain.back());
            for(int coins = 4; ;coins--) {
                int neededCards = card->getCardsPerCoin(coins);
                if(chain.size() >= neededCards) return coins;
            }
        }
        return 0;
    }
};

template <typename T>
inline std::ostream& operator<< (std::ostream& o, const Chain<T>& _chain)
{
    if(!_chain.chain.empty()){
        auto card = _chain.chain.back();
        o <<  card->getName() << " ";
        for(int i = 0; i < _chain.chain.size(); ++i) {
            o << *(_chain.chain.at(i)) << " ";
        }
        o << std::endl;
    }
    return o;
}

template class Chain<Card>;
//template class Chain<Quartz>;
//template class Chain<Hematite>;
//template class Chain<Obsidian>;
//template class Chain<Malachite>;
//template class Chain<Turquoise>;
//template class Chain<Ruby>;
//template class Chain<Amethyst>;
//template class Chain<Emerald>;
#endif /* chain_h */
