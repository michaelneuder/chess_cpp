//---------------
//author: Michael Neuder
//date: Jan 2017
//function: creates a chess game simulation and prints out final pgn file
//---------------

#include <iostream>
#include <string>
#include <fstream>
#include "chess.hpp"
using namespace std;

board::board(){//constructor initializes the board to starting position
	defaultBoardNoVerification();
	cout << "board is set to starting position" << endl;
}

void board::initializeSquareData(){
	//dark square diagonals
	//initializing main diagonal pointers
	mainDiagonal[0]= &squares[0][0];
	mainDiagonal[1]= &squares[1][1];
	mainDiagonal[2]= &squares[2][2];
	mainDiagonal[3]= &squares[3][3];
	mainDiagonal[4]= &squares[4][4];
	mainDiagonal[5]= &squares[5][5];
	mainDiagonal[6]= &squares[6][6];
	mainDiagonal[7]= &squares[7][7];

	//initializing c1 diagonal
	c1Diagonal[0] = &squares[0][2];
	c1Diagonal[1] = &squares[1][3];
	c1Diagonal[2] = &squares[2][4];
	c1Diagonal[3] = &squares[3][5];
	c1Diagonal[4] = &squares[4][6];
	c1Diagonal[5] = &squares[5][7];

	//initializing e1 diagonal
	e1Diagonal[0] = &squares[0][4];
	e1Diagonal[1] = &squares[1][5];
	e1Diagonal[2] = &squares[2][6];
	e1Diagonal[3] = &squares[3][7];

	//initializing g1 diagonal
	g1Diagonal[0] = &squares[0][6];
	g1Diagonal[1] = &squares[1][7];

	//initializing a3 diagonal
	a3Diagonal[0] = &squares[2][0];
	a3Diagonal[1] = &squares[3][1];
	a3Diagonal[2] = &squares[4][2];
	a3Diagonal[3] = &squares[5][3];
	a3Diagonal[4] = &squares[6][4];
	a3Diagonal[5] = &squares[7][5];

	//initializing a5 diagonal
	a5Diagonal[0] = &squares[4][0];
	a5Diagonal[1] = &squares[5][1];
	a5Diagonal[2] = &squares[6][2];
	a5Diagonal[3] = &squares[7][3];

	//initalizing a3 diagonal
	a7Diagonal[0] = &squares[6][0];
	a7Diagonal[0] = &squares[7][1];

	//light square diagonals
	//intializing b1 diagonal
	b1Diagonal[0] = &squares[0][1];
	b1Diagonal[1] = &squares[1][2];
	b1Diagonal[2] = &squares[2][3];
	b1Diagonal[3] = &squares[3][4];
	b1Diagonal[4] = &squares[4][5];
	b1Diagonal[5] = &squares[5][6];
	b1Diagonal[6] = &squares[6][7];

	//initializing d1 diagonal
	d1Diagonal[0] = &squares[0][3];
	d1Diagonal[1] = &squares[1][4];
	d1Diagonal[2] = &squares[2][5];
	d1Diagonal[3] = &squares[3][6];
	d1Diagonal[4] = &squares[4][7];

	//intitializing f1 diagonal
	e1Diagonal[0] = &squares[0][5];
	e1Diagonal[1] = &squares[1][6];
	e1Diagonal[2] = &squares[2][7];

	//initializing h1 diagonal
	h1Diagonal[0] = &squares[0][7];

	//initializing a2 diagonal
	a2Diagonal[0] = &squares[1][0];
	a2Diagonal[1] = &squares[2][1];
	a2Diagonal[2] = &squares[3][2];
	a2Diagonal[3] = &squares[4][3];
	a2Diagonal[4] = &squares[5][4];
	a2Diagonal[5] = &squares[6][5];
	a2Diagonal[6] = &squares[7][6];

	//initializing a4 diagonal
	a4Diagonal[0] = &squares[3][0];
	a4Diagonal[1] = &squares[4][1];
	a4Diagonal[2] = &squares[5][2];
	a4Diagonal[3] = &squares[6][3];
	a4Diagonal[4] = &squares[7][4];

	//initializing a6 diagonal
	a6Diagonal[0] = &squares[5][0];
	a6Diagonal[1] = &squares[6][1];
	a6Diagonal[2] = &squares[7][2];

	//initializing a8 diagonal
	a8Diagonal[0] = &squares[7][0];

	//initializing column and row data
	for(int i=0;i<8;i++){
		aColumn[i] = &squares[i][0];
		bColumn[i] = &squares[i][1];
		cColumn[i] = &squares[i][2];
		dColumn[i] = &squares[i][3];
		eColumn[i] = &squares[i][4];
		fColumn[i] = &squares[i][5];
		gColumn[i] = &squares[i][6];
		hColumn[i] = &squares[i][7];

		aRow[i] = &squares[0][i];
		bRow[i] = &squares[1][i];
		cRow[i] = &squares[2][i];
		dRow[i] = &squares[3][i];
		eRow[i] = &squares[4][i];
		fRow[i] = &squares[5][i];
		gRow[i] = &squares[6][i];
		hRow[i] = &squares[7][i];
	}
}

bool board::checkSquareEmpty(int row, int col){
	if(squares[row][col].pieceType == "-"){
		return true;
	}
	return false;
}

bool board::verifyAction(){//allows the user to verify a change that is permanent
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

void board::defaultBoard(){//starting position
	if (verifyAction() == true){
		for(int i=0; i<8; i++){//initializing pawns
			//squares[1][i].rowLocation = 2;
			//squares[1][i].columnLocation = i+1;
			squares[1][i].pieceType = "p";
			squares[1][i].pieceColor = 1;

			//squares[6][i].rowLocation = 7;
			//squares[6][i].columnLocation = i+1;
			squares[6][i].pieceType = "p";
			squares[6][i].pieceColor = 0;
		}
		for(int j=0; j<8;j++){//intializing the empty squares
			for(int k=2; k<6;k++){
				//squares[k][j].rowLocation = k+1;
				//squares[k][j].columnLocation = j+1;
				squares[k][j].pieceType = "-";
			}
		}
		//initializing rooks
		//squares[0][0].rowLocation = 1;
		//squares[0][0].columnLocation = 1;
		squares[0][0].pieceType = "r";
		squares[0][0].pieceColor = 1;

		//squares[0][7].rowLocation = 1;
		//squares[0][7].columnLocation = 8;
		squares[0][7].pieceType = "r";
		squares[0][7].pieceColor = 1;

		//squares[7][0].rowLocation = 8;
		//squares[7][0].columnLocation = 1;
		squares[7][0].pieceType = "r";
		squares[7][0].pieceColor = 0;

		//squares[7][7].rowLocation = 8;
		//squares[7][7].columnLocation = 8;
		squares[7][7].pieceType = "r";
		squares[7][7].pieceColor = 0;

		//initializing bishops
		//squares[0][2].rowLocation = 1;
		//squares[0][2].columnLocation = 3;
		squares[0][2].pieceType = "b";
		squares[0][2].pieceColor = 1;

		//squares[0][5].rowLocation = 1;
		//squares[0][5].columnLocation = 6;
		squares[0][5].pieceType = "b";
		squares[0][5].pieceColor = 1;

		//squares[7][2].rowLocation = 8;
		//squares[7][2].columnLocation = 3;
		squares[7][2].pieceType = "b";
		squares[7][2].pieceColor = 0;

		//squares[7][5].rowLocation = 8;
		//squares[7][5].columnLocation = 6;
		squares[7][5].pieceType = "b";
		squares[7][5].pieceColor = 0;

		//initializing knights
		//squares[0][1].rowLocation = 1;
		//squares[0][1].columnLocation = 2;
		squares[0][1].pieceType = "n";
		squares[0][1].pieceColor = 1;

		//squares[0][6].rowLocation = 1;
		//squares[0][6].columnLocation = 7;
		squares[0][6].pieceType = "n";
		squares[0][6].pieceColor = 1;

		//squares[7][1].rowLocation = 8;
		//squares[7][1].columnLocation = 2;
		squares[7][1].pieceType = "n";
		squares[7][1].pieceColor = 0;

		//squares[7][6].rowLocation = 8;
		//squares[7][6].columnLocation = 7;
		squares[7][6].pieceType = "n";
		squares[7][6].pieceColor = 0;

		//initializing queens
		//squares[0][3].rowLocation = 1;
		//squares[0][3].columnLocation = 4;
		squares[0][3].pieceType = "q";
		squares[0][3].pieceColor = 1;

		//squares[7][3].rowLocation = 8;
		//squares[7][3].columnLocation = 4;
		squares[7][3].pieceType = "q";
		squares[7][3].pieceColor = 0;

		//initializing kings
		//squares[0][4].rowLocation = 1;
		//squares[0][4].columnLocation = 5;
		squares[0][4].pieceType = "k";
		squares[0][4].pieceColor = 1;

		//squares[7][4].rowLocation = 8;
		//squares[7][4].columnLocation = 5;
		squares[7][4].pieceType = "k";
		squares[7][4].pieceColor = 0;
	}
}

void board::defaultBoardNoVerification(){//called from constructor
	for(int i=0; i<8; i++){//initializing pawns
		//squares[1][i].rowLocation = 2;
		//squares[1][i].columnLocation = i+1;
		squares[1][i].pieceType = "p";
		squares[1][i].pieceColor = 1;

		//squares[6][i].rowLocation = 7;
		//squares[6][i].columnLocation = i+1;
		squares[6][i].pieceType = "p";
		squares[6][i].pieceColor = 0;
	}
	for(int j=0; j<8;j++){//intializing the empty squares
		for(int k=2; k<6;k++){
			//squares[k][j].rowLocation = k+1;
			//squares[k][j].columnLocation = j+1;
			squares[k][j].pieceType = "-";
		}
	}
	//initializing rooks
	//squares[0][0].rowLocation = 1;
	//squares[0][0].columnLocation = 1;
	squares[0][0].pieceType = "r";
	squares[0][0].pieceColor = 1;

	//squares[0][7].rowLocation = 1;
	//squares[0][7].columnLocation = 8;
	squares[0][7].pieceType = "r";
	squares[0][7].pieceColor = 1;

	//squares[7][0].rowLocation = 8;
	//squares[7][0].columnLocation = 1;
	squares[7][0].pieceType = "r";
	squares[7][0].pieceColor = 0;

	//squares[7][7].rowLocation = 8;
	//squares[7][7].columnLocation = 8;
	squares[7][7].pieceType = "r";
	squares[7][7].pieceColor = 0;

	//initializing bishops
	//squares[0][2].rowLocation = 1;
	//squares[0][2].columnLocation = 3;
	squares[0][2].pieceType = "b";
	squares[0][2].pieceColor = 1;

	//squares[0][5].rowLocation = 1;
	//squares[0][5].columnLocation = 6;
	squares[0][5].pieceType = "b";
	squares[0][5].pieceColor = 1;

	//squares[7][2].rowLocation = 8;
	//squares[7][2].columnLocation = 3;
	squares[7][2].pieceType = "b";
	squares[7][2].pieceColor = 0;

	//squares[7][5].rowLocation = 8;
	//squares[7][5].columnLocation = 6;
	squares[7][5].pieceType = "b";
	squares[7][5].pieceColor = 0;

	//initializing knights
	//squares[0][1].rowLocation = 1;
	//squares[0][1].columnLocation = 2;
	squares[0][1].pieceType = "n";
	squares[0][1].pieceColor = 1;

	//squares[0][6].rowLocation = 1;
	//squares[0][6].columnLocation = 7;
	squares[0][6].pieceType = "n";
	squares[0][6].pieceColor = 1;

	//squares[7][1].rowLocation = 8;
	//squares[7][1].columnLocation = 2;
	squares[7][1].pieceType = "n";
	squares[7][1].pieceColor = 0;

	//squares[7][6].rowLocation = 8;
	//squares[7][6].columnLocation = 7;
	squares[7][6].pieceType = "n";
	squares[7][6].pieceColor = 0;

	//initializing queens
	//squares[0][3].rowLocation = 1;
	//squares[0][3].columnLocation = 4;
	squares[0][3].pieceType = "q";
	squares[0][3].pieceColor = 1;

	//squares[7][3].rowLocation = 8;
	//squares[7][3].columnLocation = 4;
	squares[7][3].pieceType = "q";
	squares[7][3].pieceColor = 0;

	//initializing kings
	//squares[0][4].rowLocation = 1;
	//squares[0][4].columnLocation = 5;
	squares[0][4].pieceType = "k";
	squares[0][4].pieceColor = 1;

	//squares[7][4].rowLocation = 8;
	//squares[7][4].columnLocation = 5;
	squares[7][4].pieceType = "k";
	squares[7][4].pieceColor = 0;
}

void board::setBoard(){ 
	if(verifyAction() == true){
		cout << "board is set starting at square A8-H8 followed by A7-H7 and so forth." << endl;
		cout << "you have to fill in the entire board to continue" << endl;
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
}

void board::setRow(int rowVal){//could be looped but i want the letters outputed when asking for squares so this is easier
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
		//squares[row][column].rowLocation = row;
		//squares[row][column].columnLocation = column;
	}
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

void board::writeToFile(string gameRecord){
	ofstream myFile;
	myFile.open("untitled.txt");
	myFile << gameRecord;//likely need to do some string parsing in here with sstream
	myFile.close();
}

void board::move(int oldRow, int oldCol, int newRow, int newCol){//*add some capture case
	string tempPieceType;
	bool makeMove = false;
	tempPieceType = squares[oldRow][oldCol].pieceType;
	if(tempPieceType == "p"){
		if (checkMoveP(oldRow, oldCol, newRow, newCol)){
			makeMove = true;
		}
	}else if (tempPieceType == "n"){
		if (checkMoveN(oldRow, oldCol, newRow, newCol)){
			makeMove = true;
		}
	}else if (tempPieceType == "b"){
		if (checkMoveB(oldRow, oldCol, newRow, newCol)){
			makeMove = true;
		}
	}else if (tempPieceType == "r"){
		if (checkMoveR(oldRow, oldCol, newRow, newCol)){
			makeMove = true;
		}
	}else if (tempPieceType == "q"){
		if (checkMoveQ(oldRow, oldCol, newRow, newCol)){
			makeMove = true;
		}
	}else if (tempPieceType == "k"){
		if (checkMoveK(oldRow, oldCol, newRow, newCol)){
			makeMove = true;
		}
	}else {//no piece type found
		cout << "error, no piece type found for the square you requested a move for" << endl;
	}

	
	if(makeMove and tempPieceType == "p"){
		if(newRow == 7 or newRow == 0){
			promote(newCol);
			squares[oldRow][oldCol].pieceType = "-";
		}
	}else if(makeMove){
		pieceData tempPiece = squares[oldRow][oldCol];
		squares[newRow][newCol] = tempPiece;
		squares[oldRow][oldCol].pieceType = "-";
		if(newCol == 0){
			gameRecord =  gameRecord + squares[newRow][newCol].pieceType + "a" + to_string(newRow+1) + " "; 
		}else if(newCol == 1){
			gameRecord =  gameRecord + squares[newRow][newCol].pieceType + "b" + to_string(newRow+1) + " "; 
		}else if(newCol == 2){
			gameRecord =  gameRecord + squares[newRow][newCol].pieceType + "c" + to_string(newRow+1) + " "; 
		}else if(newCol == 3){
			gameRecord =  gameRecord + squares[newRow][newCol].pieceType + "d" + to_string(newRow+1) + " "; 
		}else if(newCol == 4){
			gameRecord =  gameRecord + squares[newRow][newCol].pieceType + "e" + to_string(newRow+1) + " "; 
		}else if(newCol == 5){
			gameRecord =  gameRecord + squares[newRow][newCol].pieceType + "f" + to_string(newRow+1) + " "; 
		}else if(newCol == 6){
			gameRecord =  gameRecord + squares[newRow][newCol].pieceType + "g" + to_string(newRow+1) + " "; 
		}else if(newCol == 7){
			gameRecord =  gameRecord + squares[newRow][newCol].pieceType + "h" + to_string(newRow+1) + " "; 
		}
	}
	else{
		cout << "error: reached end of move function" << endl;
	}
}

void board::promote(int promoteColumn){
	//only called from a pawn movement
	//change the notation of the promoted piece
	cout << "enter the new piece type identifier (q,r,b, or n)" << endl;
	string promotedPiece;
	getline(cin, promotedPiece);
	squares[7][promoteColumn].pieceType = promotedPiece;
	if(promoteColumn == 0){
		gameRecord =  gameRecord + squares[7][promoteColumn].pieceType + "a" + to_string(8) + " "; 
	}else if(promoteColumn == 1){
		gameRecord =  gameRecord + squares[7][promoteColumn].pieceType + "b" + to_string(8) + " "; 
	}else if(promoteColumn == 2){
		gameRecord =  gameRecord + squares[7][promoteColumn].pieceType + "c" + to_string(8) + " "; 
	}else if(promoteColumn == 3){
		gameRecord =  gameRecord + squares[7][promoteColumn].pieceType + "d" + to_string(8) + " "; 
	}else if(promoteColumn == 4){
		gameRecord =  gameRecord + squares[7][promoteColumn].pieceType + "e" + to_string(8) + " "; 
	}else if(promoteColumn == 5){
		gameRecord =  gameRecord + squares[7][promoteColumn].pieceType + "f" + to_string(8) + " "; 
	}else if(promoteColumn == 6){
		gameRecord =  gameRecord + squares[7][promoteColumn].pieceType + "g" + to_string(8) + " "; 
	}else if(promoteColumn == 7){
		gameRecord =  gameRecord + squares[7][promoteColumn].pieceType + "h" + to_string(8) + " "; 
	} 
}

bool board::checkMoveP(int oldRow, int oldCol, int newRow, int newCol){
	if(checkSquareEmpty(newRow, newCol)){
		if(oldCol != newCol){
			cout << "pawn moves must be in the same column unless capturing" << endl;
			return false;
		}
		return true;
	}else{
		if (checkCaptureP(oldRow, oldCol, newRow, newCol)){
			return true;
		}else{
			return false;
		}
	}
}

bool board::checkMoveN(int oldRow, int oldCol, int newRow, int newCol){
	if(checkSquareEmpty(newRow, newCol)){
		if((newCol == oldCol + 2) and (newRow == oldRow + 1 or newRow == oldRow - 1)){
			return true;
		}else if((newCol == oldCol + 1) and (newRow == oldRow + 2 or newRow == oldRow - 2)){
			return true;
		}else if((newCol == oldCol - 1) and (newRow == oldRow + 2 or newRow == oldRow - 2)){
			return true;
		}else if((newCol == oldCol - 2) and (newRow == oldRow + 1 or newRow == oldRow - 1)){
			return true;
		}else{
			cout << "this is a non legal move for the knight. please enter a valid square." << endl;
			return false;
		}
	}
	else{
		if(checkCaptureN(oldRow, oldCol, newRow, newCol)){
			capture(oldRow, oldCol, newRow, newCol);
			return true;
		}
		return false;
	}
}

bool board::checkCaptureN(int oldRow, int oldCol, int newRow, int newCol){
	if(squares[oldRow][oldCol].pieceColor == squares[newRow][newCol].pieceColor){
		cout << "you can't capture pieces of the same color" << endl;
	}else if{
		if((newCol == oldCol + 2) and (newRow == oldRow + 1 or newRow == oldRow - 1)){
			return true;
		}else if((newCol == oldCol + 1) and (newRow == oldRow + 2 or newRow == oldRow - 2)){
			return true;
		}else if((newCol == oldCol - 1) and (newRow == oldRow + 2 or newRow == oldRow - 2)){
			return true;
		}else if((newCol == oldCol - 2) and (newRow == oldRow + 1 or newRow == oldRow - 1)){
			return true;
		}else{
			cout << "this is a non legal move for the knight. please enter a valid square." << endl;
			return false;
		}
	}
}

int board::identifyDiagonals(int row, int col){
	for (int i=0;i<8;i++){
		if(squares[row][column] == mainDiagonal[i]) 
			return 0;
	}
	pieceData *c1Diagonal[6];
	pieceData *e1Diagonal[4];
	pieceData *g1Diagonal[2];
	pieceData *a3Diagonal[6];
	pieceData *a5Diagonal[4];
	pieceData *a7Diagonal[2];

	//white square diagonals
	pieceData *b1Diagonal[7];
	pieceData *d1Diagonal[5];
	pieceData *f1Diagonal[3];
	pieceData *h1Diagonal[1];
	pieceData *a2Diagonal[7];
	pieceData *a4Diagonal[5];
	pieceData *a6Diagonal[3];
	pieceData *a8Diagonal[1];
}

bool board::checkMoveB(int oldRow, int oldCol, int newRow, int newCol){
		


	return true;
}

bool board::checkMoveR(int oldRow, int oldCol, int newRow, int newCol){return true;}

void board::capture(int oldRow, int oldCol, int newRow, int newCol){
	if(squares[newRow][newCol].pieceType == "-"){
		cout << "this is not a capture, please call the move function" << endl;
	}else if(squares[newRow][newCol].pieceColor == squares[oldRow][oldCol].pieceColor){
		cout << "this piece is the same color! you cant capture it" << endl;
	}else{
		cout << "piece captured!" << endl;
		squares[newRow][newCol].pieceType = squares[oldRow][oldCol].pieceType;
		squares[newRow][newCol].pieceColor = squares[oldRow][oldCol].pieceColor;
		squares[oldRow][oldCol].pieceType = "-";
	}
}

bool board::checkMoveQ(int oldRow, int oldCol, int newRow, int newCol){return true;}
bool board::checkMoveK(int oldRow, int oldCol, int newRow, int newCol){return true;}

bool board::checkCaptureP(int oldRow, int oldCol, int newRow, int newCol){return true;}
bool board::checkCaptureB(int oldRow, int oldCol, int newRow, int newCol){return true;}
bool board::checkCaptureR(int oldRow, int oldCol, int newRow, int newCol){return true;}
bool board::checkCaptureQ(int oldRow, int oldCol, int newRow, int newCol){return true;}
bool board::checkCaptureK(int oldRow, int oldCol, int newRow, int newCol){return true;}













