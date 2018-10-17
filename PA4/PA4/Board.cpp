#include "Board.h"

//constructor
Board::Board(int newM)
{
	this->n = 0;
	this->m = newM;
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

	//conditions
	if (n == m)
	{
		cout << "The map board is full!" << endl;
	}

	if (Board::Search(ID) == true)
	{
		if (Board::PositionOccupied(x, y) == true)
		{
			this->map_board.insert(pair<int, vector<int>>(ID,Board::makeVector(x, y)));
			n += 1;
			return true;
		}
		else
		{
			cout << "Failed to insert" << endl;
			return false;
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
	if (this->map_board.find(ID) == this->map_board.end()) {
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
	map <int, vector<int>>::iterator it;

	for (it = map_board.begin(); it != map_board.end(); it++)
	{
		if (it->second == Board::makeVector(x, y)) //coordinates are occupied
		{
			cout << "Desired insertion position is occupied!" << endl;
			return false;
		}
	}
	return true;
}

vector<int> Board::makeVector(int x, int y)
{
	vector<int> coordinates;

	coordinates.push_back(x);
	coordinates.push_back(y);

	return coordinates;
}

/*
Removes a player from a board. Takes player ID to be removed as a parameter. Returns true upon successful
removal and false otherwise (i.e., player not found). The value of N should also be updated. Note that upon
successful removal, the corresponding cell on the board should be availabe for newer insertion.
*/
bool Board::Remove(int ID)
{
	if (Board::Search(ID) == false) //player exist on the board
	{
		this->map_board.erase(ID);
		cout << "Successful removal of player " << ID << endl;
		this->n -= 1;
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
	map <int, vector<int>>::iterator it;
	vector <int> coordinates;
	int x1, y1, ID2, newID;

	//gets the original position/value of the key-ID
	for (it = map_board.begin(); it != map_board.end(); it++)
	{
		if (it->first == ID)
		{
			coordinates = it->second;
			x1 = coordinates.at(0); //saves variable locally
			y1 = coordinates.at(1);
			break;
		}
	}	
	
	//duplicates ID
	ID2 = ID;

	//Check
	if ((x2 < this->m) && (y2 < this->m)) //checks to see if x2 and y2 is within the bounds
	{
		if ((x1 == x2 || y1 == y2)) //checks up/down and left/right
		{
			//Removes original player
			Remove(ID);

				//gets the original key/ID
				for (it = map_board.begin(); it != map_board.end(); it++)
				{
					if (it->second == makeVector(x2, y2))
					{
						newID = it->first;
						Remove(newID); //removes the player from the new desired position
						break;
					}
				}
			Insert(ID2, x2, y2); //inserts player into that position
			cout << "Move successful" << endl;
		}		
		else if (abs((y2 - y1)) == abs((x2 - x1))) //checks diagonal
		{
			//Removes original player
			Remove(ID);

				for (it = map_board.begin(); it != map_board.end(); it++)
				{
					if (it->second == makeVector(x2, y2))
					{
						newID = it->first;
						Remove(newID); //removes the player from the new desired position
						break;
					}
				}
			Insert(ID2, x2, y2); //inserts player into that position//same as moving them
			cout << "Move successful" << endl;
		}		
		else
		{
			cout << "New desired position is not in the same row or column or in diagonal position! Failed to move!" << endl;
		}
	}
}


/*
Prints all the player IDs along with their (x, y) positions, in the increasing order of their IDs. Shouldn't 
display unoccupied positions.
*/
void Board::PrintByID()
{
	pair<int, vector<int>> highest = *map_board.rbegin();
	map <int, vector<int>>::iterator it = map_board.begin();

	do {
		cout << "ID: " << it->first << "; Position" << "(" << it->second.at(0) << "," << it->second.at(1) << ")" << endl;
	} while (map_board.value_comp()(*it++, highest));
	
}

//setters/getters
int Board::getM()
{
	return this->m;
}

int Board::getN()
{
	return this->n;
}
void Board::setN(int newN)
{
	this->n = newN;
}

