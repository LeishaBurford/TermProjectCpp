
#include "player.h"
//#include "deck.h"
#include "trade_area.h"
#include "discard_pile.h"
#include "cardFactory.h"

class Table {
    friend ostream &operator<<(ostream& out, const Table& table);
    Player player1;
    Player player2;
    Deck deck;
    TradeArea tradeArea;
    DiscardPile discardPile;
public:
    Table() = default;
    Table(Player& _p1, Player& _p2, Deck& _deck, TradeArea& _ta, DiscardPile& _dp) : player1(_p1), player2(_p2), deck(_deck), tradeArea(_ta), discardPile(_dp){}
    Table(std::istream&, CardFactory*);//TODO
    bool win(std::string&);
    void print(std::ostream&) const;//this one is for putting into file
    
};

inline std::ostream& operator<< (std::ostream& o, const Table& table)//this one is for the game
{
    std::cout << "---------------Table--------------" << std::endl;
    std::cout << "\tPlayers:\n" << table.player1 << table.player2 << std::endl;
    std::cout << "\tTrade Area:\n" << table.tradeArea << std::endl;
    std::cout << "\tDiscard Pile, top card: " << table.discardPile << std::endl;
    std::cout << "----------------------------------" << std::endl;
    return o;
}
