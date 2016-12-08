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
    while(responses.find(s) == std::string::npos) { //true when s is not in responses
        std::cout << "That's not an option, enter " << responses.at(0) << " or " << responses.at(2) << std::endl;
        std::cin >> s;
    }
}



bool checkForChain(Player& player, int& j, Card* card) {
    bool chainExists = false;
    for(int i = 0; i < player.getNumChains(); i++){
        if(player[i].chain.back()->getName() == card->getName()){//checking type of chain
            chainExists = true;
            j = i;
            break;
        }
    }
    return chainExists;
}

int main() {
    //cardfactory
    CardFactory *factory = CardFactory::getFactory();
    //deck
    Deck deck;
    //players
    Player players[2];
    TradeArea tradeArea;
    DiscardPile discardPile;
    //table
    Table table;
    
    std::string loadGame;
    std::cout << "Let's Play Bohnanza!! \nWould you like to load a previous game?(y/n): ";
    std::cin >> loadGame;
    std::string responsesYN("yYnN");
    checkValidInput(loadGame, responsesYN);
    //if user requested to load game
    if(loadGame == "Y" || loadGame == "y"){
        std::ifstream file("/Users/leishaburford/Documents/TermProjectC++/TermProjectCpp/Bohnanza/Bohnanza/pausedGame.txt");
        deck = Deck::Deck(file, factory);
        players[0] = Player::Player(file, factory);
        players[1] = Player::Player(file, factory);
        tradeArea = TradeArea::TradeArea(file, factory);
        discardPile = DiscardPile::DiscardPile(file, factory);
        //initialize table
        table = Table::Table(players[0], players[1], deck, tradeArea, discardPile);
    }else{
    
        //initialize players
        std::string player1, player2;
        std::cout << "Player 1, enter your name: ";
        std::cin >> player1;
        std::cout << "Player 2, enter your name: ";
        std::cin >> player2;
        //create player objects
        players[0] = {player1};
        players[1] ={player2};
        //initialize hands and deck
        deck= Deck::Deck(factory->getDeck());  //this copies deck, not ideal cannot find another way
       
        for(int i = 0; i < 5; i++) {
            players[0].hand += deck.draw();
            players[1].hand += deck.draw();
        }
        //initialize table
        table = Table::Table(players[0], players[1], deck, tradeArea, discardPile);
    }
   
    std::cout << "Let the game begin!" << std::endl;
    //std::cout << deck. << std::endl;
    //while there are cards in deck
    while(!deck.empty()){
        //check if user wants to pause
        std::cout << "Would you like to pause the game?(y/n): ";
        std::string pauseGame;
        std::cin >> pauseGame;
        checkValidInput(pauseGame, responsesYN);
        if(pauseGame == "Y" || pauseGame == "y"){
            std::ofstream outfile("/Users/leishaburford/Documents/TermProjectC++/TermProjectCpp/Bohnanza/Bohnanza/pausedGame.txt");
            outfile << deck << '*'; //asterix used as termination character
            players[0].print(outfile);
            
            players[1].print(outfile);
            tradeArea.print(outfile);
            outfile << '*';
            discardPile.print(outfile);
            outfile << '*';
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
            tradeArea.operator+=(c);//to be removed
            //If TradeArea is not empty
            if(tradeArea.numCards() != 0){
                //Add gemstone cards from the TradeArea to chains or discard them.
                std::cout << "Trade Area: " << tradeArea << std::endl;
                std::cout<< "You may chain a card or discard it" << std::endl;
                std::list<Card*> temp(tradeArea.getTradeArea()); // needed, cannot iterate and change tradeArea
                //for each card in tradeArea
                for(auto card: temp){
                    std::string chainOrDiscard;
                    std::cout << "Card to chain or discard : " << card->getName() << "\ndiscard or chain? (d/c): ";
                    // *** Should also be able to add to hand ***
                    std::cin >> chainOrDiscard;
                    std::string responsesDC("cCdD");
                    checkValidInput(chainOrDiscard, responsesDC);
                    if(chainOrDiscard == "c" || chainOrDiscard == "C") {
                        //chain card
                        //check if chain of card type exists
                        int chainToAdd = 0;
                        bool chainExists = checkForChain(player, chainToAdd, card);
                        //if chain exists, add card
                        if(chainExists){
                            player[chainToAdd]+=card;
                        } else {    //-------not working
                            //if room for another chain
                             std::cout << "num chains "<<player.getNumChains()<<std::endl;
                            
                            if(player.getNumChains() < player.getMaxNumChains()){
                                player.incrNumChains(); // increments the number of chains
                                 std::cout << "chain arrays size: "<<player.sizeofChainArray()<< std::endl;
                                
                                //make chain --line below causes errors
                                
                                Chain<Ruby> derived ; // Chain instance to access make chain method 
                                Chain_Base& newChain = derived.makeChain(card->getName()) ;
       /*                         if(Chain<Ruby> *j = dynamic_cast<Chain<Ruby>*>(&newChain))
                                    std::cout << "Ruby!" << std::endl ;
                                else if (Chain<Quartz> *j = dynamic_cast<Chain<Quartz>*>(&newChain))
                                    std::cout << "Quartz!" << std::endl  ;
                                else if (Chain<Hematite> *j = dynamic_cast<Chain<Hematite>*>(&newChain))
                                    std::cout << "Hematite!" << std::endl  ;
                                else if (Chain<Obsidian> *j = dynamic_cast<Chain<Obsidian>*>(&newChain))
                                    std::cout << "Obsidian!" << std::endl  ;*/
                                
                                
                                std::cout << "num chains "<<player.getNumChains()<<std::endl;
                                std::cout << "Card->getName() :"<<card->getName() << std::endl ; 
                               // player[player.getNumChains()-1] = newChain ;
                                if(Chain<Ruby> *j = dynamic_cast<Chain<Ruby>*>(&player[player.getNumChains()-1]))
                                    std::cout << "Ruby!" << std::endl ;
                                else if (Chain<Quartz> *j = dynamic_cast<Chain<Quartz>*>(&player[player.getNumChains()-1]))
                                    std::cout << "Quartz!" << std::endl  ;
                                else if (Chain<Hematite> *j = dynamic_cast<Chain<Hematite>*>(&player[player.getNumChains()-1]))
                                    std::cout << "Hematite!" << std::endl  ;
                                else if (Chain<Obsidian> *j = dynamic_cast<Chain<Obsidian>*>(&player[player.getNumChains()-1]))
                                    std::cout << "Obsidian!" << std::endl  ;
                                
                               // std::cout << newChain.getChain() << std::endl ;
                                
                                //std::vector<Card*> vect = player[player.getNumChains()-1].getChain()  ;
                                //std::cout << vect.size() << std::endl ;
                                
//                                for( auto i = vect.begin(); i !=vect.end(); ++i){
//                                    std::cout << "hey: " ; 
//                                    std::cout << *i << ", " << std::endl ;
//                                }
                                
                                
                                
                                
                                
                                //std::cout << *(player[player.getNumChains()-1].getChain().back()) << std::endl ;
                                
                                
                                
                                
                                
                                std::cout << "here" << std::endl ; 
                                
                               // derived = dynamic_cast<Chain<Ruby>*>(player[player.getNumChains()-1]);
                                
                                //std::cout << player[player.getNumChains()-1] << std::endl;
                                
                                
                                
                               
                                
                                //->makeChain(card->getName());
                                //add card
                                //player[player.getNumChains() - 1]+=card;
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
            //If chain is ended, cards for chain are removed and player receives coin(s).
            //If player decides to
                //Play the now topmost card from Hand.
            //If chain is ended, cards for chain are removed and player receives coin(s).
            //If player decides to
                //Show the player's full hand and player selects an arbitrary card
                //Discard the arbitrary card from the player's hand and place it on the discard pile.
            //Draw three cards from the deck and place cards in the trade area
            //while topcardofdiscardpilematchesanexistingcardinthetradearea
                //draw the top-most card from the discard pile and place it in the trade area
            //end
            //for all cards in the trade area
                //if player wants to chain the card
                    //chain the card
                //else
                    //card remains in trade area for the next player
            //end
            //Draw two cards from Deck and add the cards to the player's hand (at the back).
        //end
    //end
        }
    }
    //delete players[0];
    delete factory;
}






















