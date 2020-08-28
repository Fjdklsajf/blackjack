#include <string>
#include <cassert>
#include "card.h"

/******************************************************************************
 *
 *  Constructor Card: Class Card
 *_____________________________________________________________________________
 *  initialize private member variables
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    _suit = 0, _rank = 0
 ******************************************************************************/
Card::Card() : _suit(0), _rank(0) {
}

/******************************************************************************
 *
 *  Constructor Card: Class Card
 *_____________________________________________________________________________
 *  initialize private member variables with given parameters
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    1 <= suit <= 4
 *    1 <= rank <= 13
 *
 *  POST-CONDITIONS
 *    _suit and _rank are initialized
 ******************************************************************************/
Card::Card(int suit, int rank) : _suit(suit), _rank(rank) {
}

/******************************************************************************
 *
 *  Copy constructor Card: Class Card
 *_____________________________________________________________________________
 *  initialize private member variables with copy's values
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    _suit and _rank are initialized
 ******************************************************************************/
Card::Card(const Card& copy) {
    _suit = copy.getSuit();
    _rank = copy.getRank();
}

/******************************************************************************
 *
 *  Mutator setSuit: Class Card
 *_____________________________________________________________________________
 *  This method will update the _suit attribute to the parameter suit value
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    1 <= suit <= 4
 *
 *  POST-CONDITIONS
 *    _suit is updated
 ******************************************************************************/
void Card::setSuit(int suit) {
    assert(suit >= 1 && suit <= 4);
    _suit = suit;
}

/******************************************************************************
 *
 *  Mutator setRank: Class Card
 *_____________________________________________________________________________
 *  This method will update the _rank attribute to the parameter rank value
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    1 <= rank <= 13
 *
 *  POST-CONDITIONS
 *    _rank is updated
 ******************************************************************************/
void Card::setRank(int rank) {
    assert(rank >= 1 && rank <= 13);
    _rank = rank;
}

/******************************************************************************
 *
 *  Accessor getSuit: Class Card
 *_____________________________________________________________________________
 *  This method will return _suit
 *  - returns int
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    _suit is returned
 ******************************************************************************/
int Card::getSuit() const {
    return _suit;
}

/******************************************************************************
 *
 *  Accessor getRank: Class Card
 *_____________________________________________________________________________
 *  This method will return _rank
 *  - returns int
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    _rank is returned
 ******************************************************************************/
int Card::getRank() const {
    return _rank;
}

/******************************************************************************
 *
 *  Method getValue: Class Card
 *_____________________________________________________________________________
 *  Return value of the card in Blackjack,
 *      1-1, ..., 10-10, J-10, Q-10, K-10
 *  - returns int
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    Value of card in Blackjack is returned
 ******************************************************************************/
int Card::getValue() const {
    if(_rank >= 10) {
        return 10;
    }
    return _rank;
}

/******************************************************************************
 *
 *  Method getName: Class Card
 *_____________________________________________________________________________
 *  Return the name of the card in the form of:
 *      Three of Diamonds, Aces of Spades ...
 *  - returns std::string
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    _suits and _rank are valid
 *
 *  POST-CONDITIONS
 *    Name of the card is returned
 ******************************************************************************/
std::string Card::getName() const {
    assert(_suit >= 1 && _suit <= 4);
    assert(_rank >= 1 && _rank <= 13);
    std::string name = "";

    switch (_rank) {
        case 1:
            name += "Ace";
            break;
        case 2:
            name += "Two";
            break;
        case 3:
            name += "Three";
            break;
        case 4:
            name += "Four";
            break;
        case 5:
            name += "Five";
            break;
        case 6:
            name += "Six";
            break;
        case 7:
            name += "Seven";
            break;
        case 8:
            name += "Eight";
            break;
        case 9:
            name += "Nine";
            break;
        case 10:
            name += "Ten";
            break;
        case 11:
            name += "Jack";
            break;
        case 12:
            name += "Queen";
            break;
        default:
            name += "King";
            break;
    }

    name += " of ";

    switch (_suit) {
        case 1:
            name += "Spades";
            break;
        case 2:
            name += "Hearts";
            break;
        case 3:
            name += "Clubs";
            break;
        default:
            name += "Diamonds";
    }

    return name;
}

/******************************************************************************
 *
 *  Method isAce: Class Card
 *_____________________________________________________________________________
 *  Determine whether or not the card is an Ace
 *  - returns bool
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    returns true for is an Ace or false for not
 ******************************************************************************/
bool Card::isAce() const {
    return _rank == 1;
}
