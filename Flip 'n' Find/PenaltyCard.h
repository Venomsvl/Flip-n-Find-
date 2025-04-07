#ifndef PENALTYCARD_H_INCLUDED
#define PENALTYCARD_H_INCLUDED

#include "Card.h"

class PenaltyCard : public Card {
public:
    PenaltyCard():Card(8){}
    PenaltyCard(int number): Card(number){}
};

#endif
