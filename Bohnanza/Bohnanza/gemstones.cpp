

/*Card will be abstract base class, eight different gemstones will
 be derived from it. All containers hold cards through the base type. slicing will occur
 we will delete the copy constructor and assignment operator in Card*/

/*Create the gemstone card hierarchy. A gemstone card can be printed to console with its first character of its name.
 The base class Card should be abstract, derived classes Quartz, Hematite,
 Obsidian, Malachite, Turquoise, Ruby, Amethyst, and Emerald will have to be concrete classes.
 Card will have the following pure virtual functions:
 
 virtual int getCardsPerCoin( int coins ) will implement in the derived classes the
 above table for how many cards are necessary to receive the corresponding number of coins.
 
 virtual string getName() returns the full name of the card(e.g.,Ruby).
 virtual void print(const ostream& out) inserts the first character for the card into the
 output stream supplied as argument.
 You will also need to create a global stream insertion operator for
 printing any objects of such a class which implements the “Virtual Friend Function Idiom”
 with the class hierarchy*/
#include "gemstones.h"

using std::string;
using std::ostream;

//Quartz

//will implement in the derived classes the above table for how many cards are necessary to receive the corresponding number of coins.
int Quartz::getCardsPerCoin(int coins) {
    //assuming coins is 1, 2, 3, 4
    int numCards[4] = {4, 6, 8, 10};
    return numCards[coins - 1];
}

//returns the full name of the card(e.g.,Ruby).
string Quartz::getName() const{
    return string("Quartz");
}

//inserts the first character for the card into the output stream supplied as argument.
void Quartz::print(ostream& out) const {
    out << Quartz::getName()[0];
    return;
}

//Hematite

//will implement in the derived classes the above table for how many cards are necessary to receive the corresponding number of coins.
int Hematite::getCardsPerCoin(int coins) {
    //assuming coins is 1, 2, 3, 4
    int numCards[4] = {4, 6, 8, 10};
    return numCards[coins - 1];
}

//returns the full name of the card(e.g.,Ruby).
string Hematite::getName() const{
    return string("Hematite");
}

//inserts the first character for the card into the output stream supplied as argument.
void Hematite::print(ostream& out) const {
    out << Hematite::getName()[0];
    return;
}

//Obsidian

//will implement in the derived classes the above table for how many cards are necessary to receive the corresponding number of coins.
int Obsidian::getCardsPerCoin(int coins) {
    //assuming coins is 1, 2, 3, 4
    int numCards[4] = {4, 6, 8, 10};
    return numCards[coins - 1];
}

//returns the full name of the card(e.g.,Ruby).
string Obsidian::getName() const {
    return string("Obsidian");
}

//inserts the first character for the card into the output stream supplied as argument.
void Obsidian::print(ostream& out) const {
    out << Obsidian::getName()[0];
    return;
}

//Malachite

//will implement in the derived classes the above table for how many cards are necessary to receive the corresponding number of coins.
int Malachite::getCardsPerCoin(int coins) {
    //assuming coins is 1, 2, 3, 4
    int numCards[4] = {4, 6, 8, 10};
    return numCards[coins - 1];
}

//returns the full name of the card(e.g.,Ruby).
string Malachite::getName() const{
    return string("Malachite");
}

//inserts the first character for the card into the output stream supplied as argument.
void Malachite::print(ostream& out) const {
    out << Malachite::getName()[0];
    return;
}

//Turquoise

//will implement in the derived classes the above table for how many cards are necessary to receive the corresponding number of coins.
int Turquoise::getCardsPerCoin(int coins) {
    //assuming coins is 1, 2, 3, 4
    int numCards[4] = {4, 6, 8, 10};
    return numCards[coins - 1];
}

//returns the full name of the card(e.g.,Ruby).
string Turquoise::getName() const{
    return string("Turquoise");
}

//inserts the first character for the card into the output stream supplied as argument.
void Turquoise::print(ostream& out) const {
    out << Turquoise::getName()[0];
    return;
}

//Ruby

//will implement in the derived classes the above table for how many cards are necessary to receive the corresponding number of coins.
int Ruby::getCardsPerCoin(int coins) {
    //assuming coins is 1, 2, 3, 4
    int numCards[4] = {4, 6, 8, 10};
    return numCards[coins - 1];
}

//returns the full name of the card(e.g.,Ruby).
string Ruby::getName() const{
    return string("Ruby");
}

//inserts the first character for the card into the output stream supplied as argument.
void Ruby::print(ostream& out) const {
    out << Ruby::getName()[0];
    return;
}

//Amethyst

//will implement in the derived classes the above table for how many cards are necessary to receive the corresponding number of coins.
int Amethyst::getCardsPerCoin(int coins) {
    //assuming coins is 1, 2, 3, 4
    int numCards[4] = {4, 6, 8, 10};
    return numCards[coins - 1];
}

//returns the full name of the card(e.g.,Amethyst).
string Amethyst::getName() const{
    return string("Amethyst");
}

//inserts the first character for the card into the output stream supplied as argument.
void Amethyst::print(ostream& out) const {
    out << Amethyst::getName()[0];
    return;
}

//Emerald

//will implement in the derived classes the above table for how many cards are necessary to receive the corresponding number of coins.
int Emerald::getCardsPerCoin(int coins) {
    return 0;
}

//returns the full name of the card(e.g.,Emerald).
string Emerald::getName() const{
    return string("Emerald");
}

//inserts the first character for the card into the output stream supplied as argument.
void Emerald::print(ostream& out) const {
    out << Emerald::getName()[0];
    return;
}





