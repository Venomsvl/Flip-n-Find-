#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

#include <iostream>
using namespace std;

class Card {

protected:
    int number;
    bool faceUp;
    bool matched; // New member variable to track if the card is matched

public:
    Card() : number(0), faceUp(false), matched(false) {}

    Card(int number) : number(number), faceUp(false), matched(false) {}

    virtual ~Card() {}

    //display the card
    virtual void display() {
        if (matched) {
            cout << "   "; // Display nothing for matched cards
        } else if (faceUp) {
            cout << " " << number << " "; // Display the number if the card is face-up
        } else {
            cout << " * "; // Display "*" -> the card is face-down
        }
    }

    int getNumber() {
        return number;
    }

    void setNumber(int number) {
        this->number = number;
    }

    bool getFaceUp() {
        return faceUp;
    }

    void setFaceUp(bool faceUp) {
        if (!matched) { // Only allow flipping if the card is not matched
            this->faceUp = faceUp;
        }
    }

    bool isMatched() {
        return matched;
    }

    void setMatched(bool matched) {
        this->matched = matched;
        if (matched) {
            faceUp = false; // return card to face down after the turn
        }
    }
};

#endif
