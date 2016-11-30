#ifndef player_h
#define player_h

#include "chain.h"
#include "hand.h"
#include <string>
#include <iostream>
#include <vector>

class Player {
    friend ostream &operator<<(ostream& out, const Player& player);
    void print(const ostream& out) const;
    Chain_Base& getChain(int i){return *(chains.at(i));}
    const Chain_Base& getChain(int i) const {return *(chains.at(i));}
    std::string name;
    int numCoins;
    int maxChains;
    int activeChains;
    std::vector<Chain_Base*> chains; //should be Chain_Base* ?
public:
    Hand hand;
    std::string getName() const;
    Player() = default;
    Player( std::string& _name) : name(_name), numCoins(0), maxChains(2), activeChains(0){
        chains.resize(2);
    }
    
    Player( const std::istream&, CardFactory* );
    int getMaxNumChains();
    int getNumChains();
    int getNumCoins();
    Player& operator+=( int );
    Chain_Base& operator[](int i) {
        return getChain(i);
    }
    const Chain_Base& operator[](int i) const {
        return getChain(i);
    }
    void buyThirdChain();
    void printHand(std::ostream&, bool);
   
};

inline std::ostream& operator<< (std::ostream& o, const Player& player)
{
    player.print(o);
    return o;
}


#endif /* player_h */
