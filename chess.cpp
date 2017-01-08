//---------------
//author: Michael Neuder
//date: Jan 2017
//function: creates a chess game simulation and prints out final pgn file
//---------------

#include <iostream>
#include <string>
#include "chess.hpp"
using namespace std;

void board::defaultBoard(){
	for(int i=0; i<8; i++){
		squares[1][i].rowLocation = 1;
		squares[1][i].columnLocation = i;
		squares[1][i].pieceType = "pawn";
	}
}

void board::setBoard(){}
void board::clearBoard(){}
void board::printBoard(){}
void board::writeToFile(){}

void piece::move(){}
void piece::capture(){}
void piece::setLocation(){}
void piece::promote(){}


