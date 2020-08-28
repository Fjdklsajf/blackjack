#include <string>
#include <deque>
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include "deck.h"
#include "card.h"

/******************************************************************************
 *
 *  Constructor Deck: Class Deck
 *_____________________________________________________________________________
 *  initalize 52 playing cards without the Jokers into _cards
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    52 regular playing Cards are added to _cards
 ******************************************************************************/
Deck::Deck() {
    for(int s = 1; s <= 4; s++) {       //suits
        for(int r = 1; r <= 13; r++) {  //ranks
            _cards.push_back(Card(s, r));
        }
    }
}

/******************************************************************************
 *
 *  Accessor getRemainingCards: Class Deck
 *_____________________________________________________________________________
 *  This method will return _cards
 *  - returns std::deque<Card>
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    return _cards
 ******************************************************************************/
std::deque<Card> Deck::getReminingCards() const {
    return _cards;
}

/******************************************************************************
 *
 *  Accessor getUsedCards: Class Deck
 *_____________________________________________________________________________
 *  This method will return _used
 *  - returns std::deque<Card>
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    return _used
 ******************************************************************************/
std::deque<Card> Deck::getUsedCards() const {
    return _used;
}

/******************************************************************************
 *
 *  Method drawCard: Class Deck
 *_____________________________________________________________________________
 *  Draw the top card from the deck and returns it
 *  - returns Card
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    cardsLeft() > 0
 *
 *  POST-CONDITIONS
 *    the top card is returned
 ******************************************************************************/
Card Deck::drawCard() {
    assert(cardsLeft() > 0);

    Card temp = _cards.front();
    _used.push_back(temp);
    _cards.pop_front();

    return temp;
}

/******************************************************************************
 *
 *  Method shuffle: Class Deck
 *_____________________________________________________________________________
 *  Shuffle the draw pile randomly
 *  - returns void
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    _cards is shuffled
 ******************************************************************************/
void Deck::shuffle() {
    std::random_shuffle(_cards.begin(), _cards.end(), shuffleHelper);
}

/******************************************************************************
 *
 *  Method returnCards: Class Deck
 *_____________________________________________________________________________
 *  Add used Cards back to the draw pile
 *  - returns Card
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    _used is emptied and _cards is back to 52 cards
 ******************************************************************************/
void Deck::returnCards() {
    while(!_used.empty()) {
        _cards.push_back(_used.front());
        _used.pop_front();
    }
}

/******************************************************************************
 *
 *  Method seeTop: Class Deck
 *_____________________________________________________________________________
 *  Reveal the top Card in the draw pile
 *  - returns Card
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    cardsLeft() > 0
 *
 *  POST-CONDITIONS
 *    first Card in _cards is returned
 ******************************************************************************/
Card Deck::seeTop() const {
    assert(cardsLeft() > 0);

    return _cards.front();
}

/******************************************************************************
 *
 *  Method cardsLeft: Class Deck
 *_____________________________________________________________________________
 *  Return the number of cards remaining in the draw pile
 *  - returns int
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    none
 *
 *  POST-CONDITIONS
 *    size of _cards is returned
 ******************************************************************************/
int Deck::cardsLeft() const {
    return _cards.size();
}

/******************************************************************************
 *
 *  FUNCTION shuffleHelper
 *_____________________________________________________________________________
 *  Helper function for shuffling Cards
 *  - returns int
 *_____________________________________________________________________________
 *  PRE-CONDITIONS
 *    int
 *
 *  POST-CONDITIONS
 *    A random number is returned
 ******************************************************************************/
int shuffleHelper(int i) {
    return std::rand() % i;
}
