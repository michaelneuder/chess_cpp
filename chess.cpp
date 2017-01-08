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
	for(int i=0; i<8; i++){//initializing pawns
		squares[1][i].rowLocation = 2;
		squares[1][i].columnLocation = i+1;
		squares[1][i].pieceType = "p";
		squares[1][i].pieceColor = 1;

		squares[6][i].rowLocation = 7;
		squares[6][i].columnLocation = i+1;
		squares[6][i].pieceType = "p";
		squares[6][i].pieceColor = 0;
	}
	for(int j=0; j<8;j++){//intializing the empty squares to 00
		for(int k=2; k<6;k++){
			squares[k][j].rowLocation = k+1;
			squares[k][j].columnLocation = j+1;
			squares[k][j].pieceType = " ";
			squares[k][j].pieceColor = 2;
		}
	}
	//initializing rooks
	squares[0][0].rowLocation = 1;
	squares[0][0].columnLocation = 1;
	squares[0][0].pieceType = "r";
	squares[0][0].pieceColor = 1;

	squares[0][7].rowLocation = 1;
	squares[0][7].columnLocation = 8;
	squares[0][7].pieceType = "r";
	squares[0][7].pieceColor = 1;

	squares[7][0].rowLocation = 8;
	squares[7][0].columnLocation = 1;
	squares[7][0].pieceType = "r";
	squares[7][0].pieceColor = 0;

	squares[7][7].rowLocation = 8;
	squares[7][7].columnLocation = 8;
	squares[7][7].pieceType = "r";
	squares[7][7].pieceColor = 0;

	//initializing bishops
	squares[0][2].rowLocation = 1;
	squares[0][2].columnLocation = 3;
	squares[0][2].pieceType = "b";
	squares[0][2].pieceColor = 1;

	squares[0][5].rowLocation = 1;
	squares[0][5].columnLocation = 6;
	squares[0][5].pieceType = "b";
	squares[0][5].pieceColor = 1;

	squares[7][2].rowLocation = 8;
	squares[7][2].columnLocation = 3;
	squares[7][2].pieceType = "b";
	squares[7][2].pieceColor = 0;

	squares[7][5].rowLocation = 8;
	squares[7][5].columnLocation = 6;
	squares[7][5].pieceType = "b";
	squares[7][5].pieceColor = 0;

	//initializing knights
	squares[0][1].rowLocation = 1;
	squares[0][1].columnLocation = 2;
	squares[0][1].pieceType = "n";
	squares[0][1].pieceColor = 1;

	squares[0][6].rowLocation = 1;
	squares[0][6].columnLocation = 7;
	squares[0][6].pieceType = "n";
	squares[0][6].pieceColor = 1;

	squares[7][1].rowLocation = 8;
	squares[7][1].columnLocation = 2;
	squares[7][1].pieceType = "n";
	squares[7][1].pieceColor = 0;

	squares[7][6].rowLocation = 8;
	squares[7][6].columnLocation = 7;
	squares[7][6].pieceType = "n";
	squares[7][6].pieceColor = 0;

	//initializing queens
	squares[0][3].rowLocation = 1;
	squares[0][3].columnLocation = 4;
	squares[0][3].pieceType = "q";
	squares[0][3].pieceColor = 1;

	squares[7][3].rowLocation = 8;
	squares[7][3].columnLocation = 4;
	squares[7][3].pieceType = "q";
	squares[7][3].pieceColor = 0;

	//initializing kings
	squares[0][4].rowLocation = 1;
	squares[0][4].columnLocation = 5;
	squares[0][4].pieceType = "k";
	squares[0][4].pieceColor = 1;

	squares[7][4].rowLocation = 8;
	squares[7][4].columnLocation = 5;
	squares[7][4].pieceType = "k";
	squares[7][4].pieceColor = 0;
}

void board::setBoard(){}
void board::clearBoard(){}

void board::printBoard(){
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			cout << squares[i][j].pieceColor << squares[i][j].pieceType << "   ";
		}
		cout << endl << endl;
	} 
}

void board::writeToFile(){}

void piece::move(){}
void piece::capture(){}
void piece::setLocation(){}
void piece::promote(){}


