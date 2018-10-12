#include "Player.h"

class Board 
{
public:

	//adds a new player to the board
	//void Insert(Player, vector<int x, int y>);

	//functions with sample parameters
	void Insert(int playerID, int x_coord, int y_coord);
		
	void Remove(int playerID, int x_coord, int y_coord);

	void Find(int playerID, int x_coord, int y_coord);

	//void MoveTo(Player, vector<int x, int y>);
	void MoveTo(int playerID, int newX_coord, int newY_coord);

	//prints the player by ID from least to greatest
	void PrintByID(int playerID, int x_coord, int y_coord);

private:




};