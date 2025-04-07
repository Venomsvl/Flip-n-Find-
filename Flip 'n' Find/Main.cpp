#include <iostream>
using namespace std;
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Game.h"
#include "StandardCard.h"
#include "BonusCard.h"
#include "PenaltyCard.h"


int main() {
    string name1 , name2;
    Game game;

    cout<<"Enter player_1's name: ";
    cin>> name1;
    game.setPlayer1Name(name1);
    cout<<"\nEnter player_2's name: ";
    cin>>name2;
    game.setPlayer2Name(name2);



    game.initializeGame(); // Initialize and display el game grid
    return 0;
}

