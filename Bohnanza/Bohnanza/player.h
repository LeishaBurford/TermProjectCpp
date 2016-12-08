#ifndef player_h
#define player_h

#include "chain.h"
#include "hand.h"
#include <string>
#include <iostream>
#include <vector>

class Player {
    friend ostream &operator<<(ostream& out, const Player& player);
    
   
    Chain_Base& getChain(int i){return *(chains.at(i));}
    const Chain_Base& getChain(int i) const {return *(chains.at(i));}
    
    std::string name;
    int numCoins;
    int maxChains;
    int activeChains;
    std::vector<Chain_Base*> chains;
    
    
public:
    void print(std::ostream& out) const;
    Hand hand;
    std::string getName() const;
    Player() = default;
    Player( std::string& _name) : name(_name), numCoins(0), maxChains(2), activeChains(0){
        chains.resize(2);
    }
    
    Player(std::istream&, CardFactory* );
    int getMaxNumChains();
    int getNumChains();
    int getNumCoins(); // returns number of active chains
    void incrNumChains() ;
    int sizeofChainArray() ; // method for testing and dubgging
    Player& operator+=( int i );
    Chain_Base& operator[](int i) {
        return getChain(i);//chain_Base& = chainBase
    };
     const Chain_Base& operator[](int i) const {
        return getChain(i);
    };
    void buyThirdChain();
    void printHand(std::ostream&, bool);
   
};

inline std::ostream& operator<< (std::ostream& o, const Player& player)
{
    std::cout << player.getName() << " " << player.numCoins << " coins"<<  std::endl;
    for(int i = 0; i < player.activeChains; i++) {
        std::cout << player.chains.at(i) << std::endl; //chain is Chain<Card_Base*>
        
    }
    return o;
}


#endif /* player_h */
