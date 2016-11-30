//#include <iostream>

#include <string>
#include <exception>
#include "chain.h"
#include "cardfactory.h"
#include "player.h"
#include "discard_pile.h"
#include "trade_area.h"

int main() {
    /*The simplified pseudo-code of the main loop is as follows. Setup:
     Input the names of 2 players.                                          --Done
     Initialize the Deck and draw 5 cards for the Hand of each Player; or   --Done
     Load paused game from file.
     While there are still cards on the Deck
        if pause save game to file and exit
        For each Player
            Display Table
            If Player has 3 coins and two chains and decides to buy extra chain 
                Add chain to player
            Player draws top card from Deck 
            If TradeArea is not empty
                Add gemstone cards from the TradeArea to chains or discard them. 
            Play topmost card from Hand.
            If chain is ended, cards for chain are removed and player receives coin(s). 
            If player decides to
                Play the now topmost card from Hand.
            If chain is ended, cards for chain are removed and player receives coin(s). 
            If player decides to
                Show the player's full hand and player selects an arbitrary card
                Discard the arbitrary card from the player's hand and place it on the discard pile. 
            Draw three cards from the deck and place cards in the trade area
            while topcardofdiscardpilematchesanexistingcardinthetradearea
                draw the top-most card from the discard pile and place it in the trade area
            end
            for all cards in the trade area
                if player wants to chain the card 
                    chain the card
                else
                    card remains in trade area for the next player
            end
            Draw two cards from Deck and add the cards to the player's hand (at the back).
        end
     end
     */

    
    std::string loadGame;
    std::string responses("YyNn");
    std::cout << "Let's Play Bohnanza!! \nWould you like to load a previous game?(y/n)" <<std::endl;
    std::cin >> loadGame;
    while(responses.find(loadGame) == std::string::npos) { //true when loadGame is not in responses
        std::cout << "That's not an option, enter y or n" << std::endl;
        std::cin >> loadGame;
    }
    //if user requested to load game
    if(responses.substr(0, 2).find(loadGame) != std::string::npos){
        std::cout << "Come on! You know that isn't implemented yet!" << std::endl;
        return 0;
    }
    //initialize players
    std::string player1, player2;
    std::cout << "Player 1, enter your name: ";
    std::cin >> player1;
    std::cout << "Player 2, enter your name: ";
    std::cin >> player2;
    //test
    std::cout << "testing name input...\n\tPlayer1: " << player1 << "\n\tPlayer2: " << player2 << "\n...end test" <<std::endl;
    std::cout << "Let the game begin!" << std::endl;
    //initialize hands and deck
    CardFactory* factory = CardFactory::getFactory();
    Hand p1;
    Hand p2;
    Deck deck(factory->getDeck());  //this copies deck, not ideal cannot find another way
    
    for(int i = 0; i < 5; i++) {
        p1 += deck.draw();
        p2 += deck.draw();
    }
    std::cout << "testing player hands...\n\tP1: " << p1 << "\n\tP2: " << p2 << "\n...end test" <<std::endl;
    auto card1 = p1[2];
    auto card2 = p2[2];
    std::cout << "testing hand subscript operator...\n\tRemoved: " << *card1 << ", P1: " << p1 << std::endl;
    std::cout <<"\tRemoved: " << *card2 << ", P2: " << p2 << "\n...end test" <<std::endl;
    delete factory;
}
