
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

using namespace std;

class Player {
protected:
    string name;
    int score;

public:


    Player() {
    this-> name="";
    this->score=0;
    }

Player(string name) {
this-> name=name;
this-> score =0;
}


~Player() {}

void setName(string name){
this->name = name;
}

string getName()  {
    return name;
}

void setScore(int newScore) {
    score = newScore;
}


int getScore()  {
    return score;
}


void displayScore()  {
    cout << name << "'s score: " << score << endl;
}

};

#endif

