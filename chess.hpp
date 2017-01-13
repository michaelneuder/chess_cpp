#ifndef CHESS_H
#define CHESS_H

struct pieceData{
	//int rowLocation; dont really need these as this data is encapsulated in the board instance
	//int columnLocation;
	std::string pieceType;
	int pieceColor; //0=white, 1=black, 2=no piece
	int pieceID;
};

class board{
	public:
		board();//instantiates class and calls defaultBoardNoVerification
		pieceData squares[8][8];
		std::string gameRecord;
		
		//user options
		void move(int oldRow, int oldCol, int newRow, int newCol);
		void defaultBoard();
		void setBoard();
		void clearBoard();
		void printBoard();
		void writeToFile(std::string gameRecord);
		
		//void setSquare(int row, int column);
		//void setRow(int rowVal);
		//void promote(int promoteColumn);
	
	private:
		void defaultBoardNoVerification();
		bool verifyAction();
		void setSquare(int row, int column);
		void setRow(int rowVal);
		bool checkMoveP();
		void promote(int promoteColumn);
		bool checkMoveN();
		bool checkMoveB();
		bool checkMoveR();
		bool checkMoveQ();
		bool checkMoveK();

};

/* dont really need a piece class when my board class has a each square encapsulating piecedata
class piece{
	public:
		pieceData myPiece;
		void move(int oldRow, int oldCol, int newRow, int newCol);
		void capture();
		void setLocation();
		//void promote(int promoteColumn);
};
*/

#endif // CHESS_H
