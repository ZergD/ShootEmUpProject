#pragma once
class SpaceShip
{
	int positionX, positionY;
public:
	//Constructeurs
	SpaceShip(void);
	SpaceShip(int X, int Y);
	
	//Destructeur
	~SpaceShip(void);

	//Methodes
	void move(int dx, int dy);
	void display();

	int getPositionX();
	int getPositionY();

	void setPositionX(int X);
	void setPositionY(int Y);
};

