

#include "player.h"


//get the name of the player
std::string Player::getName() const{
    return name;
}


Player::Player(std::istream& i, CardFactory* factory) {
    std::string _name;
    getline(i, name);
    name = _name;
    i >>numCoins >> activeChains;
    for(int i = 0; i < activeChains; i++) {
        char ch;
        while(i >> ch && ch != '-') {
            chains.at(i)->operator+=(factory->getCard(ch));
        }
    }
    
}

//returnseither2or3
int Player::getMaxNumChains() {
    return maxChains;
}

//returns the number of non-zero chains
int Player::getNumChains() {
    return activeChains;
}

//get the number of coins currently held by the player
int Player::getNumCoins() {
    return numCoins;
}

//add a number of coins
Player& Player::operator+=(int i) {
    numCoins += i;
    return *this;
}

//adds an empty third chain to the player for two coins.The functions reduces the coin count for the player by two. If the player does not have enough coins then an exception NotEnoughCoins is thrown
void Player::buyThirdChain() {
    if(chains.size() < 3 && numCoins >= 2) {
        activeChains++;
        numCoins -= 2;
         //else throw NotEnoughCoins Exception TODO
    }
}

void Player::print(std::ostream& out) const {
    out << this->getName() << std::endl << numCoins << activeChains;
    for(int i = 0; i < activeChains; i++) {
        //line below causing errors
        //out << *(chains.at(i));
        out << "-"; //used for read in, to distinguish between chains
    }
}

//prints the top card of the player's hand(with argument false) or all of the player's hand (with argument true) to the supplied ostream.
void Player::printHand(std::ostream& out, bool all) {
//    if(all) {
//        for()
//    }
}









