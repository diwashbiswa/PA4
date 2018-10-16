#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
struct coordinates
{
	int x, y;
};
*/

class Player
{
public:
	Player(int newID, int newX, int newY); //instantiate new player
	//map<int, coordinates> player;

	//setters/getters for coordinates
	void setCoordinates(vector<int, int>);
	vector<int> getCoordinates();

	void setID(int);
	int getID();

private:
	vector<int> coordinates; //contains x, y coordinates
	int ID;
};