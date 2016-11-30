

#include "player.h"


//get the name of the player
std::string Player::getName() const{
    return name;
}

//TODO
//Player needs a constructor which accepts an istream and reconstruct the Player from file.
Player::Player( const std::istream&, CardFactory* ) {

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

//Also add the insertion operator to print a Player to an std::ostream. The player's name, the number of coins in the player's possession and each of the chains (2 or 3, some possibly empty) should be printed. Note that the Hand is printed with a separate function. The player printout may look as follows:
//    Jane     3 coins
//    Ruby     R R R R
//    Quartz   Q
void Player::print(const ostream& out) const {
    std::cout << this->getName() << " " << this->numCoins << " coins"<<  std::endl;
    for(int i = 0; i < activeChains; i++) {
        std::cout << chains.at(i) << std::endl; //chain is Chain<Card_Base*>
        
    }
}

//prints the top card of the player's hand(with argument false) or all of the player's hand (with argument true) to the supplied ostream.
void Player::printHand(std::ostream& out, bool all) {
//    if(all) {
//        for()
//    }
}









