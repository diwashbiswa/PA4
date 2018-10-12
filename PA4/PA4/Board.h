#include "Player.h"

class Board 
{
public:

	//adds a new player to the board
	void Insert(int ID, int x, int y);
	
		

	
	
	
	// map<int player id, Player(id, x, y)>

/*	//functions with sample parameters
	void Insert(int playerID, int x_coord, int y_coord);
		
	void Remove(int playerID, int x_coord, int y_coord);

	void Find(int playerID, int x_coord, int y_coord);

	//void MoveTo(Player, vector<int x, int y>);
	void MoveTo(int playerID, int newX_coord, int newY_coord);

	//prints the player by ID from least to greatest
	void PrintByID(int playerID, int x_coord, int y_coord);
*/

private:
	map<int, Player> player;  //int stores playerID, Player is a player class-- constructor
	map<vector<int, int>, int> position; //stores the position of each player, vector stores x,y coordinates, int stores ID

	//map<string, int> postion; //we can perhaps use convert x,y coordinates to string("2, 3"), since map only allows key and value
};