
#include "cardFactory.h"
#include "gemstones.h"
#include <list>
#include <string>

class TradeArea {
    friend ostream &operator<<(ostream& out, const TradeArea& tradeArea);
    std::list<Card*> _tradeArea;
public:
    std::list<Card*>& getTradeArea(){return _tradeArea;}
    TradeArea() = default;
    TradeArea( std::istream&, CardFactory* ); //TODO
    TradeArea& operator+=( Card* );
    void print(const ostream& out) const;
    bool legal( Card* );
    Card* trade( std::string );
    int numCards();
    
};

inline std::ostream& operator<< (std::ostream& o, const TradeArea& tradeArea)
{
    tradeArea.print(o);
    return o;
}
