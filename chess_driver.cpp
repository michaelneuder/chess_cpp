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
	cout << "7. make a capture" << endl;
	cout << "2. default board setup" << endl;
	cout << "3. custom board setup" << endl;
	cout << "4. print current board state" << endl;
	cout << "5. create pgn file" << endl;
	cout << "6. quit" << endl;
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
                    cout << "enter the old row" << endl;
                    getline(cin, x1);
                    cout << "enter the old column" << endl;
                    getline(cin, y1);
                    cout << "enter the new row" << endl;
                    getline(cin, x2);
                    cout << "enter the new column" << endl;
                    getline(cin, y2);

                    int ix1,ix2,iy1,iy2;//string to int conversion
                    ix1 = stoi(x1)-1;//subtract one to account for zeroth index 
                    ix2 = stoi(x2)-1;
                    iy1 = stoi(y1)-1;
                    iy2 = stoi(y2)-1;
            		myBoard.move(ix1,iy1,ix2,iy2);
            		break;
            	}

            case 2:	
            	{
                    //if (myBoard.verifyAction() == true){ ill call verify action within default board   
            		myBoard.defaultBoard();
            		cout << "default board set" << endl;
                    //}
                    break;
            	}

            case 3:
            	{
            		//if(myBoard.verifyAction()==true){//ill call verify action within setboard
                    myBoard.setBoard();
                    //}
                    break;
           		}

            case 4:
            	{
            		myBoard.printBoard();
                    break;
            	}

            case 5:
            	{
            		myBoard.writeToFile(myBoard.gameRecord);
            		break;
            	}
                
            case 6:
            	{
                	quit = true;
					cout << "Goodbye!" << endl;//end it
                	break;
            	}

            case 7: 
            	{
            		//myBoard.capture();
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







