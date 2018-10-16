#include "Board.h"

//constructor
Board::Board(int size)
{

}

/*
Takes player ID along with desired (x, y) position as an input. 
Conditions for a successful insert:
	1. a player with the same ID should not alreay exist on the board; AND
	2. the specified insertion position on board should be currently unoccupied
	3. Ensure the total number of players with this insertion (i.e., n) should not exceed m)
If successful insert --> update n and return true
Else --> display an appropriate error message and return false without changing anything
*/
bool Board::Insert(int ID, int x, int y)
{
	//player.insert(id, Player(id, x, y)); //general format for inserting

	//conditions 1 and 2 //still need condition 3 //NEED TO UPDATE N upon successful insertion -> might need separate functions to update N
	if (Board::Search(ID) == true)
	{
		if (Board::PositionOccupied(x, y) == true)
		{
			this->player.insert(pair<int, Player>(ID, Player(ID, x, y)));
			return true;
		}
	}
	else
	{
		cout << "Failed to insert" << endl;
		return false;
	}

}

//searches and returns boolean depending on if the player with this ID already exist on the board or not
bool Board::Search(int ID)
{
	if (this->player.find(ID) == this->player.end()) {
		//not found - doesn't exist on the map
		return true;
	}
	else //ID already exist on the map
	{
		cout << "ID exist on the map!" << endl;
		return false; 
	}
	
}

//returns boolean value depending on if the desired insertion position is occupied or not
bool Board::PositionOccupied(int x, int y)
{
	if (this->position.find(<x, y>) == this->position.end()) { //.find() functions finds the key, not value
		//not found - doesn't exist on the map
		return true;
	}
	else //exist on the map
	{
		cout << "Desired insertion position is occupied!" << endl;
		return false; 
	}
	
}

/*
Removes a player from a board. Takes player ID to be removed as a parameter. Returns true upon successful
removal and false otherwise (i.e., player not found). The value of N should also be updated. Note that upon
successful removal, the corresponding cell on the board should be availabe for newer insertion.
*/
bool Board::Remove(int ID) //NEED TO UPDATE N
{
	if (Board::Search(ID) == false) //player exist on the board
	{
		this->player.erase(ID);
		cout << "Successful removal of player " << ID << endl;
		return true;
	}
	else
	{
		cout << "Player not found on the board! Removal failed!" << endl;
		return false;
	}
}

bool Board::Find(int ID)
{
	if (Board::Search(ID) == false) //ID found on the map
	{
		return true;
	}
	return false;
}

/*
Takes player ID and a destination (x2, y2) cell position as an input. The method should first locate
the player, and move the player from its current position, say (x1, y1) to a new position (x2, y2) only if:
	1. (x2, y2) is within bounds, AND
	2. the movement from (x1, y1) to (x2, y2) is always along the same row or same column or same diagonal in
	   any direction (i.e., top-left == right-bottom or top-right -- left-bottom).
*/
void Board::MoveTo(int ID, int x2, int y2)
{

}

/*
Prints all the player IDs along with their (x, y) positions, in the increasing order of their IDs. Shouldn't 
display unoccupied positions.
*/
void Board::PrintByID()
{

}

