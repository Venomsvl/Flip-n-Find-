#include <cmath>
#include <cstdlib>
#include "BonusCard.h"
#include "PenaltyCard.h"
#include "StandardCard.h"
#include "Player.h"


#ifndef DECK_H
#define DECK_H


#include "Card.h"



class Deck {
protected:
    Card** cards;
    int size;
    Player* currentPlayer;
    bool takeAnotherTurn = false;
    bool skipNextTurn = false;
        Card* flippedCards[2] = {nullptr, nullptr};




public:

Deck() {
    size = 16; // law a 4x4 grid
    cards= new Card*[size];
    for (int i = 0; i < size; i++) {
        cards[i] = new Card((i % (size / 2)) + 1); // ha npair el cards
    }

}

Deck(int size) {
    this->size = size;
    cards = new Card*[size];
    for (int i = 0; i < size; i++) {
        if (i < 2) {
            cards[i] = new BonusCard();
        } else if (i < 4) {
            cards[i] = new PenaltyCard();
        } else {
            cards[i] = new StandardCard((i % (size / 2)) + 1);
        }
    }
    shuffle();
}



~Deck() {
        for (int i = 0; i < size; i++) {
            delete cards[i];
        }
        delete[] cards;
    }


void shuffle() {
    for (int i = 0; i < size; i++) {
        int randIndex = rand() % size;

        Card* temp = cards[i];
        cards[i] = cards[randIndex];
        cards[randIndex] = temp;
    }
}


void play(int x, int y) {
    x = x - 1;
    y = y - 1;

    int grid = sqrt(size);

    if (x<0 || y<0 || x >=grid || y >=grid)
    {
        cout << "err. insert the right rows and colums" << endl;
        return;
    }
    int v = x * grid+y;


    if (v >= size) {
        cout << "err. insert the right rows and colums" << endl;
        return;
    }

    //////////////////////////////////////

    if (v >= size || cards[v]->isMatched()) {
        cout << "Error: Invalid selection. Card is already matched." << endl;
        return;
    }

    //////////////////////////////

    cards[v]->setFaceUp(true);


    for (int i = 0; i < size; i++) {
        cards[i]->display();
        if ((i + 1) % grid == 0) {
            cout << endl;
        }
    }
}



void displayGrid() {
    for (int i = 0; i < size; i++) {
        cards[i]->display();
        if ((i + 1) % 4 == 0) {
            cout <<endl;
        }
    }
}

int getSize(){

    return size;
}
void setSize(int size){
    this-> size = size;
}

// a Getter le specific card

Card* getCard(int index) {
    return cards[index];
}



 void setCurrentPlayer(Player* player) {
        currentPlayer = player;
    }
void setFlippedCards(int x1 , int y1 , int x2 , int y2){
            int grid = sqrt(size);

    flippedCards[0] =cards[ x1 * grid+y1];
    flippedCards[1]= cards[x2 * grid+y2];
    }

void setFlippedCards(int index, int cardIndex) {
    if (index >= 0 && index < 2) {
        flippedCards[index] = cards[cardIndex];
    }
}

Card* getFlippedCards(int index) {
    return flippedCards[index];
}


bool checkFlippedCards() {
    ///////////
    int flippedCount = 0;

    for (int i = 0; i < size; i++) {
        if (cards[i]->getFaceUp() && !cards[i]->isMatched()) {
            if (flippedCount < 2) {
                flippedCards[flippedCount] = cards[i];
                flippedCount++;
            } else {
                cout << "Error: More than two cards are flipped!" << endl;
                return false;
            }
        }
    }

    if (flippedCount < 2) {
        cout << "Error: Less than two cards are flipped!" << endl;
        return false;
    }
    ////////////

    Card* card1 = flippedCards[0];
    Card* card2 = flippedCards[1];

    if (card1->getNumber() == BonusCard().getNumber() || card2->getNumber() == BonusCard().getNumber()) {

        if (card1->getNumber() == BonusCard().getNumber() && card2->getNumber() == BonusCard().getNumber()) {
            // Both are Bonus Cards
            cout << "You revealed two Bonus Cards! Choose an option:\n";
            cout << "1. Gain 2 points.\n";
            cout << "2. Gain 1 point and take another turn.\n";
            int choice;
            cin >> choice;
            if (choice == 1) {
                currentPlayer->setScore(currentPlayer->getScore() + 2);
                takeAnotherTurn = false;

            } else {
                currentPlayer->setScore(currentPlayer->getScore() + 1);
                takeAnotherTurn = true;
            }
            card1->setMatched(true);
            card2->setMatched(true);
            return true;
        } else {
            // One Bonus Card
            cout << "You revealed one Bonus Card! Gained +1 point.\n";
            currentPlayer->setScore(currentPlayer->getScore() + 1);
            card1->setFaceUp(false);
            card2->setFaceUp(false);
            takeAnotherTurn = false;
            return false;
        }
         card1->setMatched(true);
            card2->setMatched(true);
            return true;

    }

    if (card1->getNumber() == PenaltyCard().getNumber() || card2->getNumber() == PenaltyCard().getNumber()) {
        if (card1->getNumber() == PenaltyCard().getNumber() && card2->getNumber() == PenaltyCard().getNumber()) {
            // Both are Penalty Cards
            cout << "You revealed two Penalty Cards! Choose an option:\n";
            cout << "1. Lose 2 points.\n";
            cout << "2. Lose 1 point and skip your next turn.\n";
            int choice;
            cin >> choice;
            if (choice == 1) {
                currentPlayer->setScore(currentPlayer->getScore() - 2);
                takeAnotherTurn = true;

            } else {
                currentPlayer->setScore(currentPlayer->getScore() - 1);
                skipNextTurn = true;
                takeAnotherTurn = false;

            }
             card1->setMatched(true);
            card2->setMatched(true);
            return true;
        } else {
            // One Penalty Card
            cout << "You revealed one Penalty Card! Lost 1 point.\n";
            currentPlayer->setScore(currentPlayer->getScore() - 1);
            card1->setFaceUp(false);
            card2->setFaceUp(false);
            takeAnotherTurn = false;
            return false;

        }
        card1->setMatched(true);
        card2->setMatched(true);
        return true;
    }

    if (card1->getNumber() == card2->getNumber()) {
        // Standard card match logic
        cout << "Match found!" << endl;
        card1->setMatched(true);
        card2->setMatched(true);
        currentPlayer->setScore(currentPlayer->getScore() + 1);
        takeAnotherTurn = true;

        return true;
    } else {
        // No match
        cout << "No match. Cards will be flipped back." << endl;
        card1->setFaceUp(false);
        card2->setFaceUp(false);
        takeAnotherTurn = false;
        return false;
    }
}


bool getTakeAnotherTurn(){
return takeAnotherTurn;

}




};

#endif

