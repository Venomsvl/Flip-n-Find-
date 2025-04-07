
#ifndef GAME_H
#define GAME_H

#include "Deck.h"
#include "Player.h"

class Game {
protected:
    Deck deck;
    Player player1, player2;
    bool gameEnd;
    bool currentPlayer1;
    bool currentPlayer2;

public:

    Game() : player1("Player 1"), player2("Player 2") {}

 void setPlayer1Name( string& name) {
        player1.setName(name);
    }
    void setPlayer2Name( string& name) {
        player2.setName(name);
    }


void initializeGame() {
    cout << "\nGame Start!\n" << endl;

    deck.shuffle();
    deck.displayGrid();

    cout << "\n" << player1.getName() << "'s Score: " << player1.getScore() << endl;
    cout << player2.getName() << "'s Score: " << player2.getScore() << endl;

     currentPlayer1 = true;// `true` for player1
     currentPlayer2 = false;
    int round = 1;

    while (!isGameEnd()) {
            if(currentPlayer1){
                deck.setCurrentPlayer(&player1);
            }
            else{deck.setCurrentPlayer(&player2);}

        cout << "\nRound: " << round << endl;

              Player& currPlayer = currentPlayer1 ? player1 : player2;


        cout << currPlayer.getName() << ", it's your turn.\n";

        bool playerMatched = false;

        do {
            int x1, y1, x2, y2;

            // First card


    while (true) {
             cout << currPlayer.getName() << ", select the first card (row and column): ";
            cin >> x1 >> y1;

        int grid = sqrt(deck.getSize());
        if (x1 < 1 || y1 < 1 || x1 > grid || y1 > grid ) {
            cout << "Error: insert the right rows and colums." << endl;
        }
        else if(deck.getCard((x1 - 1) * grid + (y1 - 1))->isMatched()){
         cout << "Error: Invalid selection. Card is already matched." << endl;

        }
         else {
            deck.play(x1, y1);
            break;
        }
    }
    //////////

            // Second card
            while(true){
                    cout << currPlayer.getName() << ", select the second card (row and column): ";
                  cin >> x2 >> y2;
              int grid = sqrt(deck.getSize());



        if (x2 < 1 || y2 < 1 || x2 > grid || y2 > grid ) {
            cout << "Error: insert the right rows and colums." << endl;
        }
       else if (x1 == x2 && y1 == y2) {
                //if they pick the same card tani

                    cout << "Error: You cannot select the same card twice. Pick a different card." << endl;
                }
        else if(deck.getCard((x2 - 1) * grid + (y2 - 1))->isMatched()){

                cout << "Error: Invalid selection. Card is already matched." << endl;

        }

         else {
            deck.play(x2, y2);
            break;
        }
    }
deck.setFlippedCards(x1 , y1 , x2 , y2);

            if (deck.checkFlippedCards() &&  deck.getTakeAnotherTurn()) {

                     if (isGameEnd()) {
                        declareWinner();
                        return;
                    }

                cout << "You get another turn.\n";
                //currPlayer.setScore(currPlayer.getScore() + 1);
                playerMatched = true;




            } else {
                cout << "\n";
                playerMatched = false;
            }

            deck.displayGrid();
            cout << "\n" << player1.getName() << "'s Score: " << player1.getScore() << endl;
            cout << player2.getName() << "'s Score: " << player2.getScore() << endl;

        } while (playerMatched && deck.getTakeAnotherTurn());

        currentPlayer1 = !currentPlayer1;

        if (isGameEnd()) {
            declareWinner();
            return;
        }

        round++;
    }


}



bool isGameEnd() {
    for (int i = 0; i < deck.getSize(); i++) {
        if (!deck.getCard(i)->isMatched()) {
            return false;
        }
    }
    return true;
}
void declareWinner() {
    cout << "\nGame Over!" << endl;
    cout << player1.getName() << "'s Score: " << player1.getScore() << endl;
    cout << player2.getName() << "'s Score: " << player2.getScore() << endl;

    if (player1.getScore() > player2.getScore()) {
        cout << player1.getName() << " wins!" << endl;
    } else if (player2.getScore() > player1.getScore()) {
        cout << player2.getName() << " wins!" << endl;
    } else {
        cout << "It's a tie!" << endl;
    }

    gameEnd = true;
}


   ~Game(){}
};

#endif

