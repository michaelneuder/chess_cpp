#include <iostream>
using namespace std;



int main(){
	const int dimension = 8;
	int myBoard[dimension][dimension];

	for(int i=0; i<dimension; i++){
		for(int j=0; j<dimension; j++){
			myBoard[i][j]=0;
		}
	} 
	for(int k=0; k<dimension; k++){
		for(int l=0; l<dimension; l++){
			cout << myBoard[k][l] << " ";
		}
		cout << endl;
	} 


} 