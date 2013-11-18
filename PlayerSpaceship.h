#pragma once
#include "SpaceShip.h"
#include "time.h"


class EngineManager;

class PlayerSpaceShip : public SpaceShip
{
public:
	bool toucheAppuyeeUp;
	bool toucheAppuyeeDown;
	bool toucheAppuyeeLeft;
	bool toucheAppuyeeRight;
	
	//Constructeurs
	PlayerSpaceShip(EngineManager*);
	
	//Destructeur
	~PlayerSpaceShip(void);

	//Methodes

	void display();
	void compute();


};

