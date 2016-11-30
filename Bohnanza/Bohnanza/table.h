
#include "player.h"
#include "deck.h"
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
    Table(std::istream&, CardFactory*);//TODO
    bool win(std::string&);
    void print(std::ostream&) const;
    
};

inline std::ostream& operator<< (std::ostream& o, const Table& table)
{
    table.print(o);
    return o;
}
