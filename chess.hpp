#ifndef CHESS_H
#define CHESS_H

struct pieceData{
	int rowLocation;
	int columnLocation;
	std::string pieceType;
};

class board{
	public:
		pieceData squares[8][8];
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
