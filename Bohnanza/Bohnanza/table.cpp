
#include "table.h"

//returns true when a player has won. The name of the player is returned by reference (in the argument). The winning condition is that all cards from the deck must have been picked up and then the player with the most coins wins.
bool Table::win( std::string& name) {
    if(deck.empty()) {
        name = (player1.getNumCoins() > player2.getNumCoins()) ? player1.getName() : player2.getName();
        return 1;
    }
    return 0;
}

//prints the complete table with all content. Intended for serialization to file.
void Table::print(std::ostream&) const {
    std::cout << player1 << player2 << deck << tradeArea << discardPile << std::endl;
}
