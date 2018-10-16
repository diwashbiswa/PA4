/**********************************************************************************************************
Programmers: Diwash Biswa, Drew McLaurin
Programming Assignment: PA4 Board Game
Date Started: 10/12/18
Date Due: 10/17/18
Comments: 
***********************************************************************************************************/

#include "Board.h"

int main() {

	// This code is not a complete test code (won't even compile) and it may be syntactically inconsistent with your class definitions. 
	// So modify before use as appropriate. But the idea of testing should be clear. You are free to shuffle around the order of operations in order to devise more test cases of your own.


	Board B(10);	// specifies that the game board size is 1000000 x 1000000 

						// the following is a sequence of calls to Board class methods assuming
						// 	the input example (m=10,n=8) given in the programming assignment.
	cout << "Insert 1" << endl;
	B.Insert(1, 3, 2);	// assumed syntax: Insert(ID, x, y)
	cout << "Insert 2" << endl;
	B.Insert(2, 4, 3);
	cout << "Insert 3" << endl;
	B.Insert(3, 4, 6);
	cout << "Insert 4" << endl;
	B.Insert(4, 5, 7);
	cout << "Insert 5" << endl;
	B.Insert(5, 6, 3);
	cout << "Insert 6" << endl;
	B.Insert(6, 8, 2);
	cout << "Insert 7" << endl;
	B.Insert(7, 9, 3);
	cout << "Insert 8" << endl;
	B.Insert(8, 9, 8);

	cout << "Insert 9" << endl;
	B.Insert(3, 7, 6);	// should fail because player 3 is already there

	cout << "Insert 10" << endl;
	B.Insert(10, 9, 8);	// should fail because 9,8 is occupied already
	
	cout << "Move 0" << endl;
	B.MoveTo(6, 9, 3); //move w/o problem

	cout << endl << "Move 1" << endl;
	B.MoveTo(4, 9, 3);	//assumed syntax: MoveTo(ID,x,y) // removes 7 in the process
	B.PrintByID();

	cout << "Move 2. Removes 8" << endl;
	B.MoveTo(4, 9, 8);	// removes 8
	B.PrintByID();

	cout << "Move 3. Should fail!" << endl;
	B.MoveTo(4, 6, 3); // should fail because move to 6,3 is from 4's current position is not valid
	B.PrintByID();

	cout << "Move 4" << endl;
	B.MoveTo(2, 3, 3);
	B.PrintByID();

	cout << "Move 5" << endl;
	B.MoveTo(4, 3, 2);	// removes 1
	B.PrintByID();

	cout << "Move 6" << endl;
	B.MoveTo(4, 8, 2);	// removes 6
	B.PrintByID();

	cout << "Move 7" << endl;
	B.MoveTo(5, 3, 3);	// removes 2
	B.PrintByID();

	cout << "Move 8" << endl;
	B.MoveTo(4, 4, 6);	// removes 3
	B.PrintByID();

	cout << "Move 9" << endl;
	B.MoveTo(5, 4, 3);
	B.PrintByID();

	cout << "Move 10" << endl;
	B.MoveTo(4, 4, 3);	// removes 5
	B.PrintByID();

	// the code should print only one player at this stage which is player 4 @ (4,3)

}
