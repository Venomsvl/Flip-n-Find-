#ifndef BONUSCARD_H_INCLUDED
#define BONUSCARD_H_INCLUDED

#include "Card.h"

class BonusCard : public Card {

public:
    BonusCard():Card(7){}
    BonusCard(int number) : Card(number){}
};

#endif // BONUSCARD_H_INCLUDED
