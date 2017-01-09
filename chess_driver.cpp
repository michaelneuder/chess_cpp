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
            		//make a move
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







