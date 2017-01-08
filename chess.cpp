//---------------
//author: Michael Neuder
//date: Jan 2017
//function: creates a chess game simulation and prints out final pgn file
//---------------

#include <iostream>
#include <string>
#include "chess.hpp"
using namespace std;

board::defaultBoard(){
	for(int i=0; i<dimension; i++){
		squares[1][i].rowLocation = 1;
		squares[1][i].columnLocation = i;
		squares[1][i].pieceType = "pawn";
	}
}

board::setBoard(){}
board::clearBoard(){}
board::printBoard(){}
board::writeToFile(){}

piece::move(){}
piece::capture(){}
piece::setLocation(){}
piece::promote(){}


