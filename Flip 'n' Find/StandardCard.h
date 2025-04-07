#ifndef STANDARDCARD_H_INCLUDED
#define STANDARDCARD_H_INCLUDED

#include "Card.h"
class StandardCard : public Card {
public:
    StandardCard(): Card(){}
    StandardCard(int number): Card(number){}


};
#endif
