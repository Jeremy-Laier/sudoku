#include <iostream>
#include <time.h>
#include <stdlib.h>

bool checkX(int wholeBoard[9][9], int row, int number) {
   for(int i=0; i<9; i++)
      if( number == wholeBoard[row][i])
         return false; //if false, the number is in the list 

   return true; //if true, the number is not in the list
}//end checkX function

bool checkY(int wholeBoard[9][9], int column, int number){

   for(int i=0; i<9; i++)
      if(number == wholeBoard[i][column])
         return false;// the number is in the row, function is false
   return true;// this number is not in the row.

}//end checkY function
using namespace std;
bool checkMini(int wholeBoard[9][9], int x, int y, int number){
	//goal of mini here, is to check if the number is inside the 3x3 box
	//There are 9 mini boxes inside 1 sudoku board
	//   012 345 678
	// 0 *** *** ***
	// 1  1   2   3
	// 2

	// 3 *** *** ***
	// 4  4   5   6
	// 5

	// 6 *** *** ***
	// 7  7   8   9
	// 8
	// example below.
	// sending in board[7][8] gives us, row 7 column, 8. Since row is 6<x<9, it is the bottom
	// since column is 6<x<9, it is right set.
	// this gives us box 9
	//this is the basic algorithm example.

   int rowNum, columnNum;
   int boxNum;

   if(x<=2 && y<=2)                          boxNum =1; //1 4 7
   else if(x<=2 && (y>2 && y<=5))            boxNum =4;
   else if(x<=2 && y>5)                      boxNum =7;
   else if((x>2 && x<=5) && y<=2)            boxNum =2; //2 5 8
   else if((x>2 && x<=5) && (y>2 && y<=5))   boxNum =5;
   else if((x>2 && x<=5) && y>5)             boxNum =8;
   else if( (x>5 && y<=2) )                  boxNum =3; //3 6 9
   else if(x>5 && (y>2 && y<=5))             boxNum =6;
   else                                      boxNum =9;
	//find what box, then set row + column number, then iterate over 2 for loops checking for num.



   //testing purposes
   switch(boxNum){
      case(1):
         rowNum =0;
         columnNum =0;
         cout <<"Box number " << boxNum <<" is based on x and y of " <<x << " & " <<y<<endl;
         break;
      case(2):
         rowNum =0;
         columnNum =3;
         cout <<"Box number " << boxNum <<" is based on x and y of " <<x << " & " <<y<<endl;
         break;
      case(3):
         rowNum =0;
         columnNum =6;
         cout <<"Box number " << boxNum <<" is based on x and y of " <<x << " & " <<y<<endl;
         break;
      case(4):
         rowNum =3;
         columnNum =0;
         cout <<"Box number " << boxNum <<" is based on x and y of " <<x << " & " <<y<<endl;
         break;
      case(5):
         rowNum =3;
         columnNum =3;
         cout <<"Box number " << boxNum <<" is based on x and y of " <<x << " & " <<y<<endl;
         break;
      case(6):
         rowNum =3;
         columnNum =6;
         cout <<"Box number " << boxNum <<" is based on x and y of " <<x << " & " <<y<<endl;
         break;
      case(7):
         rowNum =6;
         columnNum =0;
         cout <<"Box number " << boxNum <<" is based on x and y of " <<x << " & " <<y<<endl;
         break;
      case(8):
         rowNum =6;
         columnNum =3;
         cout <<"Box number " << boxNum <<" is based on x and y of " <<x << " & " <<y<<endl;
         break;
      case(9):
         rowNum =6;
         columnNum =6;
         cout <<"Box number " << boxNum <<" is based on x and y of " <<x << " & " <<y<<endl;
         break;
   }
//------------------------------ ^^^^will eventually be its own function^^^^^^^^-----------------

	//now that we have which box it is in, through the row, column, we can try to find the number;

   for(int i = rowNum; i<rowNum + 3; i++)
      for (int j = columnNum; j<columnNum +3; j++)
         if(number == wholeBoard[i][j])
            return false;
   return true;
}//end checkMini

int randomInt(){
	int random = rand() %9 + 1 ; //1 - 9
   return random;
}
void generateBoard(int board[][9]){

for(int i=0; i<9; i++)
	for(int j=0; j<9; j++)
		board[i][j] = j+1;
}//end generate board

void displayBoard(int board[][9]){

for(int i=0; i<9; i++){
	if(i %3==0 && i>0)
	cout<<endl;
	for(int j=0; j<9; j++){

	if(j%3==0 && j>0)
		cout<< " ";

	cout<< board[i][j];

	if(j==8)
		cout<<endl;

	}//end j
}//end i

}//end display board
using namespace std;

int main(){
   srand(time(NULL));
   int board[9][9];

   generateBoard(board);
   displayBoard(board);
   cout<< endl;
   int randX, randY, randNum;
   randX = randomInt() -1; //because the random number generator produces 1-9. the array is 0-8. 1-9 works too tho.
   randY = randomInt() -1;
   randNum = randomInt();

   if(!(checkMini(board, randX, randY, randNum)))
      cout<<randNum << " was found in x y of " << randX << " & " <<randY <<endl;
   else
      cout<<randNum << " was not found in x y of " << randX << " & " <<randY<<endl;

   return 0;
}//end main
