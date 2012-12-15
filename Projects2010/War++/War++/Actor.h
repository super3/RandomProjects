//Include Statements
#include "stdafx.h"

class Actor {
	private:
		int x;
			// X Grid Location from the Bottom-Left of the playing field. 
		int y;
			// Y Grid Location from the Bottom-Left of the playing field. 
		short int team;
			// A number that indicates a unique team.
	public:
		int getX();
		int getY();
		short int getTeam();
};