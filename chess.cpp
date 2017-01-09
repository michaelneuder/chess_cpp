//---------------
//author: Michael Neuder
//date: Jan 2017
//function: creates a chess game simulation and prints out final pgn file
//---------------

#include <iostream>
#include <string>
#include "chess.hpp"
using namespace std;

bool board::verifyAction(){
	cout << "this action will delete current board state. this action can not be taken back\nare you sure you want to continue? (y/n)" << endl;
    string answer;
    getline(cin, answer);
    while(answer != "y" and answer!= "n"){
    	cout << "invalid input, please type 'y' or 'n'" << endl;
    	getline(cin, answer);
    }
    if (answer=="n"){
        cout << "board not modified" << endl;
        return false;
    }
    else /* (answer=="y")*/{
        return true;
    }
}

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
	for(int j=0; j<8;j++){//intializing the empty squares
		for(int k=2; k<6;k++){
			squares[k][j].rowLocation = k+1;
			squares[k][j].columnLocation = j+1;
			squares[k][j].pieceType = "-";
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

void board::setBoard(){ 
	cout << "board is set starting at square A8-H8 followed by A7-H7 and so forth." << endl;
	cout << "if no piece occupies a specific square type 0 and return" << endl << endl;
	//setting the rows
	setRow(7);
	setRow(6);
	setRow(5);
	setRow(4);
	setRow(3);
	setRow(2);
	setRow(1);
	setRow(0);
}

void board::setSquare(int row, int column){
	//getting piece type
	string tempType;
	cout << "enter piece identifier (p,n,b,r,q,k): ";
	getline(cin, tempType);
	while (tempType != "p" and tempType != "b" and tempType != "n" and tempType != "r"
		and tempType != "q" and tempType != "k" and tempType != "0"){
		cout << "invalid input: please enter a valid piece identified (p,n,b,r,q, or k)" << endl;
		getline(cin, tempType);
	}
	if(tempType == "0"){
		squares[row][column].pieceType = "-";
		return;
	}
	else{
		squares[row][column].pieceType = tempType;

		//getting piece color
		string tempColor;
		cout << "enter the piece color (w/b): ";
		getline(cin, tempColor);
		while(tempColor != "w" and tempColor != "b"){
			cout << "invalid input: please enter a valid piece color (w/b)" << endl;
			getline(cin, tempColor);
		} 
		if(tempColor == "w"){
			squares[row][column].pieceColor = 0;
		}
		else{
			squares[row][column].pieceColor = 1;
		}

		//setting piece location
		squares[row][column].rowLocation = row;
		squares[row][column].columnLocation = column;
	}
}

void board::setRow(int rowVal){
	cout << "square a" << rowVal+1 << ": "<< endl;
	setSquare(rowVal,0);
	cout << "square b" << rowVal+1 << ": "<< endl;
	setSquare(rowVal,1);
	cout << "square c" << rowVal+1 << ": "<< endl;
	setSquare(rowVal,2);
	cout << "square d" << rowVal+1 << ": "<< endl;
	setSquare(rowVal,3);
	cout << "square e" << rowVal+1 << ": "<< endl;
	setSquare(rowVal,4);
	cout << "square f" << rowVal+1 << ": "<< endl;
	setSquare(rowVal,5);
	cout << "square g" << rowVal+1 << ": "<< endl;
	setSquare(rowVal,6);
	cout << "square h" << rowVal+1 << ": "<< endl;
	setSquare(rowVal,7);
}

void board::clearBoard(){
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			squares[i][j].pieceType = "-";
		}
	} 	
}

void board::printBoard(){
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			if(squares[i][j].pieceType == "-"){
				cout << "--" << "   ";
			}
			else if (squares[i][j].pieceColor == 0){
				cout << "w" << squares[i][j].pieceType << "   ";
			}
			else{
				cout << "b" << squares[i][j].pieceType << "   "; 
			}
		}
		cout << endl << endl;
	} 
}

void board::writeToFile(){}

void piece::move(int newRow, int newCol, string pieceType, string pieceColor){

}
void piece::capture(){}
void piece::setLocation(){}
void piece::promote(){}


