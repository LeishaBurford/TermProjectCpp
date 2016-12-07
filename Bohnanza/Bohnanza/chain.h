#ifndef chain_h
#define chain_h

#include <vector>
#include <exception>
#include <typeinfo>
#include "cardfactory.h"

class Chain_Base {
    friend std::ostream &operator<<(std::ostream& out, const Chain_Base& chain_base);
public:
    virtual int sell() = 0;
    virtual Chain_Base& operator+=(Card*) =0;
    std::vector<Card*> chain;
    
};

template <class T>
class Chain : public Chain_Base {
    friend std::ostream &operator<<(std::ostream& out, const Chain<T>& chain);
    std::vector<Card*> chain;
public:
    
    Chain() = default;
    Chain(std::istream& i, CardFactory* factory){
        char ch;
        while (i >> ch && ch != '*') {
            chain.push_back(factory->getCard(ch));
        }
    };
    
    // adds a card to the Chain.
    Chain<T>& operator+=(Card* card) {
        if(typeid(T) != typeid(*(dynamic_cast<T*>(card)))){
            throw "IllegalType";
        }
        chain.push_back(card);
        return *this;
    }
    
    //counts the number cards in the current chain and returns the number coins according to the function Card::getCardsPerCoin.
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
    Chain_Base& makeChain(std::string cardName) {
        Chain_Base* newChain;
        if(cardName == "Quartz"){
            newChain = new Chain<Quartz>();
        } else if(cardName == "Hematite") {
            newChain = new Chain<Hematite>();
        } else if(cardName == "Obsidian") {
            newChain = new Chain<Obsidian>();
        } else if(cardName == "Malachite") {
            newChain = new Chain<Malachite>();
        } else if(cardName == "Turquoise") {
            newChain = new Chain<Turquoise>();
        } else if(cardName == "Ruby") {
            newChain = new Chain<Ruby>();
        } else if(cardName == "Amethyst") {
            newChain = new Chain<Amethyst>();
        } else if(cardName == "Emerald") {
            newChain = new Chain<Emerald>();
        } else {
            //this should never occur
            std::cout << cardName << " is not a valid card name" << std::endl;
            newChain = nullptr;
        }
        return *newChain;
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
#endif /* chain_h */
