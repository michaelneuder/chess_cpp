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
		void capture(int oldRow, int oldCol, int newRow, int newCol);
		void defaultBoard();
		void setBoard();
		void clearBoard();
		void printBoard();
		void writeToFile(std::string gameRecord);
		
		//void setSquare(int row, int column);
		//void setRow(int rowVal);
		//void promote(int promoteColumn);
	
	private:
		//dark square diagonals
		pieceData mainDiagonalB[8];
		pieceData c1Diagonal[6];
		pieceData e1Diagonal[4];
		pieceData g1Diagonal[2];
		pieceData a3Diagonal[6];
		pieceData a5Diagonal[4];
		pieceData a7Diagonal[2];

		//white square diagonals
		pieceData b1Diagonal[7];
		pieceData d1Diagonal[5];
		pieceData f1Diagonal[3];
		pieceData h1Diagonal[1];
		pieceData a2Diagonal[7];
		pieceData a4Diagonal[5];
		pieceData a6Diagonal[3];
		pieceData a8Diagonal[1];

		//column data
		pieceData aColumn[8];
		pieceData bColumn[8];
		pieceData cColumn[8];
		pieceData dColumn[8];
		pieceData eColumn[8];
		pieceData fColumn[8];
		pieceData gColumn[8];
		pieceData hColumn[8];

		//row data
		pieceData 1row[8];
		pieceData 2row[8];
		pieceData 3row[8];
		pieceData 4row[8];
		pieceData 5row[8];
		pieceData 6row[8];
		pieceData 7row[8];
		pieceData 8row[8];

		void defaultBoardNoVerification();
		bool verifyAction();
		bool checkSquareEmpty(int row, int col);
		void setSquare(int row, int column);
		void setRow(int rowVal);
		void promote(int promoteColumn);
		
		bool checkMoveP(int oldRow, int oldCol, int newRow, int newCol);
		bool checkMoveN(int oldRow, int oldCol, int newRow, int newCol);
		bool checkMoveB();
		bool checkMoveR();
		bool checkMoveQ();
		bool checkMoveK();

		bool checkCaptureP();
		bool checkCaptureN();
		bool checkCaptureB();
		bool checkCaptureR();
		bool checkCaptureQ();
		bool checkCaptureK();

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
