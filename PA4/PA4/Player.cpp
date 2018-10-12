#include "Player.h"

//instantiate new Player
Player::Player(int newID, int newX, int newY)
{
	// player id = id
	// location x = x
	// location y = y
	this->ID = newID;
	this->coordinates[0] = newX;
	this->coordinates[1] = newY;
	
}

//not sure if I need setters/getters but since I made the vector coordinates & ID private, I thought we might need it
void Player::setCoordinates(vector<int, int> coord)
{
	coordinates = coord;
}

void Player::setID(int id)
{
	this->ID = id;
}

int Player::getID()
{
	return this->ID;
}

vector<int, int> Player::getCoordinates()
{
	return this->coordinates;
}
