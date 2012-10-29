#pragma once
class SpaceShip
{
	int positionX, positionY;
public:
	SpaceShip(void);
	SpaceShip(int X, int Y);
	~SpaceShip(void);

	void move(int dx, int dy);
	void display();

	int getPositionX();
	int getPositionY();

	void setPositionX(int X);
	void setPositionY(int Y);
};

