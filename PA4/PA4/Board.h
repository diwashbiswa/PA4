#include "Player.h"

class Board 
{
public:

	//constructor
	Board(int newM);

	//adds a new player to the board
	bool Insert(int ID, int x, int y);
	
	//searches and returns boolean depending on if the player with this ID already exist on the board or not
	bool Search(int ID);

	//returns boolean value depending on if the desired insertion position is occupied or not
	bool PositionOccupied(int x, int y);

	//removes a player from the board
	bool Remove(int ID);

	//finds if player exist on the board or not
	bool Find(int ID); //pretty much the same as Search() function

	//moves player from current position to a new position
	void MoveTo(int ID, int x, int y);

	//prints out all player IDs with their positions
	void PrintByID();
	
/*	//functions with sample parameters
	void Insert(int playerID, int x_coord, int y_coord);
		
	void Remove(int playerID, int x_coord, int y_coord);

	void Find(int playerID, int x_coord, int y_coord);

	//void MoveTo(Player, vector<int x, int y>);
	void MoveTo(int playerID, int newX_coord, int newY_coord);

	//prints the player by ID from least to greatest
	void PrintByID(int playerID, int x_coord, int y_coord);
*/
	int getM();

	int getN();
	void setN(int newN);

	

private:
	map<int, Player> player;  //int stores playerID, Player is a player class-- constructor
	map<vector<int>, int> position; //stores the position of each player, vector stores x,y coordinates, int stores ID

	int m;
	int n;
	//map<string, int> postion; //we can perhaps use convert x,y coordinates to string("2, 3"), since map only allows key and value
};