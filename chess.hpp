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
		int squares[dimension][dimension];
		void defaultBoard();
		void setBoard();
		void clearBoard();
		void printBoard();
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
