// ---------------
// Chess Driver
// author: Michael Neuder
// date: Jan 2017
// ---------------

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "chess.hpp"
using namespace std;

void displayMenu(){
	cout << "======Main Menu======" << endl;
	cout << "1. make a move" << endl;
	cout << "2. default board setup" << endl;
	cout << "3. custom board setup" << endl;
	cout << "4. print current board state" << endl;
	cout << "5. create pgn file" << endl;
	cout << "6. Quit" << endl;
}

void userInput(board myBoard){
	bool quit = false;
    string input;
    int inputVal;

    // loop until the user quits
    while (!quit)
    {
        displayMenu();

        getline(cin, input);
		inputVal = stoi(input);

        switch (inputVal)
        {
            case 1:
            	{
                    string x1,x2,y1,y2;
                    getline(cin, x1);
                    getline(cin, y1);
                    getline(cin, x2);
                    getline(cin, y2);
                    int ix1,ix2,iy1,iy2;
                    ix1 = stoi(x1);
                    ix2 = stoi(x2);
                    iy1 = stoi(y1);
                    iy2 = stoi(y2);
            		myBoard.move(ix1,iy1,ix2,iy2);
            		break;
            	}

            case 2:	
            	{
                    if (myBoard.verifyAction() == true){    
            		  myBoard.defaultBoard();
            		  cout << "default board set" << endl;
                    }
                    break;
            	}

            case 3:
            	{
            		if(myBoard.verifyAction()==true){
                        myBoard.setBoard();
                    }
                    break;
           		}

            case 4:
            	{
            		myBoard.printBoard();
                    break;
            	}

            case 5:
            	{
            		myBoard.writeToFile();
            		break;
            	}
                
            case 6:
            	{
                	quit = true;
					cout << "Goodbye!" << endl;//end it
                	break;
            	}
            default: 	// invalid input
            	{
                	cout << "Invalid Input" << endl;
                	break;
            	}
        }
    }
}


int main(){
	board myBoard;
	userInput(myBoard);

	return 0;
}







