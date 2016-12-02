//#include <iostream>

#include <string>
#include <exception>
#include "chain.h"
#include "cardfactory.h"
#include "player.h"
//#include "discard_pile.h"
//#include "trade_area.h"
#include "table.h"


void checkValidInput(std::string& s, std::string responses){
    while(responses.find(s) == std::string::npos) { //true when loadGame is not in responses
        std::cout << "That's not an option, enter " << responses.at(0) << " or " << responses.at(2) << std::endl;
        std::cin >> s;
    }
}

Chain_Base& makeChain(std::string cardName) {
    Chain_Base* newChain;
    if(cardName == "Quartz"){
        //chainBase = dynamic_cast<Chain<Quartz>&>(chainBase);
        //chainBase = Chain<Quartz>();
        newChain = new Chain<Quartz>;
    } else if(cardName == "Hematite") {
        //chainBase = dynamic_cast<Chain<Hematite>&>(chainBase);
        //chainBase = Chain<Hematite>();
        newChain = new Chain<Hematite>;
    } else if(cardName == "Obsidian") {
        //chainBase = dynamic_cast<Chain<Obsidian>&>(chainBase);
        //chainBase = Chain<Obsidian>();
        newChain = new Chain<Obsidian>;
    } else if(cardName == "Malachite") {
        //chainBase = dynamic_cast<Chain<Malachite>&>(chainBase);
        //chainBase = Chain<Malachite>();
        newChain = new Chain<Malachite>;
    } else if(cardName == "Turquoise") {
        //chainBase = dynamic_cast<Chain<Turquoise>&>(chainBase);
        //chainBase = Chain<Turquoise>();
        newChain = new Chain<Turquoise>;
    } else if(cardName == "Ruby") {
        //chainBase = dynamic_cast<Chain<Ruby>&>(chainBase);
        //chainBase = Chain<Ruby>();
        newChain = new Chain<Ruby>;
    } else if(cardName == "Amethyst") {
        //chainBase = dynamic_cast<Chain<Amethyst>&>(chainBase);
        //chainBase = Chain<Amethyst>();
        newChain = new Chain<Amethyst>;
    } else if(cardName == "Emerald") {
        //chainBase = dynamic_cast<Chain<Emerald>&>(chainBase);
        //chainBase = Chain<Emerald>();
        newChain = new Chain<Emerald>;
    } else {
        //this should never occur
        std::cout << cardName << " is not a valid card name" << std::endl;
        newChain = nullptr;
    }
    return *newChain;
}

int main() {
    /*The simplified pseudo-code of the main loop is as follows. Setup:
     Input the names of 2 players.                                          --Done
     Initialize the Deck and draw 5 cards for the Hand of each Player; or   --Done
     Load paused game from file.
     While there are still cards on the Deck`                               --Done
        if pause save game to file and exit
        For each Player                                                     --Done
            Display Table                                                   --Done
            If Player has 2 coins and two chains and decides to buy extra chain     --Done
                Add chain to player                                                 --Done
            Player draws top card from Deck                                         --Done
            If TradeArea is not empty                                               --Done
                Add gemstone cards from the TradeArea to chains or discard them.    --Done
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
    std::cout << "Let's Play Bohnanza!! \nWould you like to load a previous game?(y/n): ";
    std::cin >> loadGame;
    std::string responsesYN("yYnN");
    checkValidInput(loadGame, responsesYN);
    //if user requested to load game
    if(loadGame == "Y" || loadGame == "y"){
        std::cout << "Come on! You know that isn't implemented yet!" << std::endl;
        return 0;
    }
    
    //initialize players
    std::string player1, player2;
    std::cout << "Player 1, enter your name: ";
    std::cin >> player1;
    std::cout << "Player 2, enter your name: ";
    std::cin >> player2;
    //test name input
//    std::cout << "testing name input...\n\tPlayer1: " << player1 << "\n\tPlayer2: " << player2 << "\n...end test" <<std::endl;
    
    //create player objects
    Player players[2] = {{player1}, {player2}};
    //initialize hands and deck
    CardFactory* factory = CardFactory::getFactory();
    Deck deck(factory->getDeck());  //this copies deck, not ideal cannot find another way
    
    for(int i = 0; i < 5; i++) {
        players[0].hand += deck.draw();
        players[1].hand += deck.draw();
    }
    //test
//    std::cout << "testing player hands...\n\tP1: " << p1 << "\n\tP2: " << p2 << "\n...end test" <<std::endl;
//    p1[2];
//    p2[2];
//    std::cout << "testing hand subscript operator...\n\tP1: " << p1 << std::endl;
//    std::cout <<"\tP2: " << p2 << "\n...end test" <<std::endl;
    //initialize tradeArea and discardPile
    TradeArea tradeArea;
    DiscardPile discardPile;
    //initialize table
    Table table(players[0], players[1], deck, tradeArea, discardPile);
    std::cout << "Let the game begin!" << std::endl;    
    //while there are cards in deck
    while(!deck.empty()){
        //check if user wants to pause
        std::cout << "Would you like to pause the game?(y/n): ";
        std::string pauseGame;
        std::cin >> pauseGame;
        checkValidInput(pauseGame, responsesYN);
        if(pauseGame == "Y" || pauseGame == "y"){
            std::cout << "Come on! You know that isn't implemented yet!" << std::endl;
            return 0;
        }
        //for each player
        for(auto player : players) {
            std::cout << player.getName() <<"'s turn" << std::endl;
            //display table
            table.update(deck, tradeArea, discardPile);
            std::cout << table << std::endl;
            //If Player has 2 coins and two chains
            if(player.getNumCoins() >= 2 && player.getNumChains() == 2){
                //output here not tested yet
                //ask for third chain purchase
                std::string thirdChain;
                std::cout << "Would you like to purchase a third chain for 2 coins?(y/n): " << std::endl;
                std::cin >> thirdChain;
                checkValidInput(thirdChain, responsesYN);
                if(thirdChain == "Y" || thirdChain == "y") {
                    //Add chain to player
                    player.buyThirdChain();
                    std::cout << "Ok, you now have 3 chains" << std::endl;
                }
            }
            //Player draws top card from Deck -- assumed to go into hand
            auto drawCard = deck.draw();
            player.hand += drawCard;
            std::cout << drawCard->getName() <<" drawn from deck, added to back of hand"<< std::endl;
            //test
            //std::cout << "testing += to hand...\n\tHand: " << player.hand << "\n...end test" << std::endl;
            //variable below for testing
            auto c = deck.draw();
            tradeArea.operator+=(c);
            //If TradeArea is not empty
            if(tradeArea.numCards() != 0){
                //Add gemstone cards from the TradeArea to chains or discard them.
                std::cout << "Trade Area: " << tradeArea << std::endl;
                std::cout<< "You may chain a card or discard it" << std::endl;
                std::list<Card*> temp(tradeArea.getTradeArea()); // needed, cannot iterate and change tradeArea
                //for each card in tradeArea
                for(auto card: temp){
                    std::string chainOrDiscard;
                    std::cout << "Card to chain or discard: " << card->getName() << "\ndiscard or chain? (d/c): ";
                    
                    std::cin >> chainOrDiscard;
                    std::string responsesDC("cCdD");
                    checkValidInput(chainOrDiscard, responsesDC);
                    if(chainOrDiscard == "c" || chainOrDiscard == "C") {
                        //chain card
                        //check if chain of card type exists
                        bool chainExists = false;
                        int chainToAdd = 0;
                        for(int i = 0; i < player.getNumChains(); i++){
                            if(player[i].chain.back()->getName() == card->getName()){//checking type of chain
                                std::cout << "In loop :)" << std::endl;
                                chainExists = true;
                                chainToAdd = i;
                                break;
                            }
                        }
                        //if chain exists, add card
                        if(chainExists){
                            player[chainToAdd]+=card;
                        } else {    //-------not working
                            //if room for another chain
                            if(player.getNumChains() < player.getMaxNumChains()){
                                //make chain --line below causes errors
                                //player[player.getNumChains()] = makeChain(card->getName());
                                //add card
                                player[player.getNumChains() - 1]+=card;
                            }else{
                                //tie and sell a chain
                            }
                        }
                        
                    }else {
                        //discard card
                        discardPile+=(tradeArea.trade(card->getName()));
                        //test
//                        std::cout << "testing += to discardPile...\n\tTradeArea: " << tradeArea << "\n\tDiscardPile: " << discardPile << "\n...end test" << std::endl;
                    }
                    
                }
            }
            //play top most card from hand
            //card must be added to chain of same stones
            //if chain is ended, cards are removed and player recieves coins
        }
        
    }
    //delete players[0];
    delete factory;
}






















