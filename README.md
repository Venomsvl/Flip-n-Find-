# Memory Match Card Game (C++)

This C++ console game lets two players test their memory by flipping cards on a 4x4 grid to find matching pairs. Built with object-oriented programming principles, it includes standard, bonus, and penalty cards. Players take turns, score points, and compete to collect the most pairs before the deck runs out.

## Features

- Turn-based gameplay for 2 players  
- 4x4 grid of hidden cards  
- Standard, Bonus, and Penalty card types  
- Score tracking and winner announcement  
- Fully object-oriented design  

## Classes

- `Card` (base class), with subclasses: `StandardCard`, `BonusCard`, `PenaltyCard`  
- `Deck` handles card creation, shuffling, and display  
- `Player` manages name and score  
- `Game` controls game flow, scoring, and logic  
