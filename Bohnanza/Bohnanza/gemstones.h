
#ifndef gemstones_hpp
#define gemstones_hpp

#include <iostream>
#include <string>

using std::string;
using std::ostream;


//make constructor private?
// Base Abstract Class
class Card {
    friend ostream &operator<<(ostream& out, const Card& card);
public:
    virtual int getCardsPerCoin(int coins) = 0;
    virtual string getName() const = 0;
    virtual void print(const ostream& out) const = 0;
    //virtual ~Card();
};

inline std::ostream& operator<< (std::ostream& o, const Card& card)
{
    card.print(o);
    return o;
}

// Quartz
class Quartz: public Card {
public:
    int getCardsPerCoin(int coins) override;
    string getName() const override;
    void print(const ostream& out) const override;
    
};

// Hematite
class Hematite: public Card {
public:
    int getCardsPerCoin(int coins) override;
    string getName() const override;
    void print(const ostream& out) const override;
    
};

//Obsidian
class Obsidian: public Card {
public:
    int getCardsPerCoin(int coins) override;
    string getName() const override;
    void print(const ostream& out) const override;
    
};

//Malachite
class Malachite: public Card {
public:
    int getCardsPerCoin(int coins) override;
    string getName() const override;
    void print(const ostream& out) const override;
    
};

//Turquoise
class Turquoise: public Card {
public:
    int getCardsPerCoin(int coins) override;
    string getName() const override;
    void print(const ostream& out) const override;
    
};

//Ruby
class Ruby: public Card {
public:
    int getCardsPerCoin(int coins) override;
    string getName() const override;
    void print(const ostream& out) const override;
    
};

//Amethyst
class Amethyst: public Card {
public:
    int getCardsPerCoin(int coins) override;
    string getName() const override;
    void print(const ostream& out) const override;
    
};

//Emerald
class Emerald: public Card {
public:
    int getCardsPerCoin(int coins) override;
    string getName() const override;
    void print(const ostream& out) const override;
    
};

#endif /* gemstones_hpp */
