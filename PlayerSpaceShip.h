#pragma once
#include "SpaceShip.h"
#include "time.h"


class EngineManager;

class PlayerSpaceShip : public SpaceShip
{
public:
	//Constructeurs
	PlayerSpaceShip(EngineManager*);
	
	//Destructeur
	~PlayerSpaceShip(void);

	//Methodes

	void display();
	void compute();


};

