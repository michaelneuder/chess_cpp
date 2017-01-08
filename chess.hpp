#ifndef CHESS_H
#define CHESS_H

struct pieceData{
	int rowLocation;
	int columnLocation;
	string pieceType;
};

class board{
	public:
		const int dimension = 8;
		pieceData squares[dimension][dimension];
		void defaultBoard();
		void setBoard();
		void clearBoard();
		void printBoard();
		void writeToFile();
};

class piece{
	public:
		pieceData myPiece;
		void move();
		void capture();
		void setLocation();
		void promote();
};



















#endif // CHESS_H
