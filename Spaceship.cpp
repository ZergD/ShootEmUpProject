#include <iostream>
#include "SpaceShip.h"
#include "graphics.h"
#include "EngineManager.h"


using namespace std;

SpaceShip::SpaceShip(int X, int Y) {
	positionX = X;
	positionY = Y;
	cout << "SpaceShip created.\n";
}

SpaceShip::SpaceShip(void){
	positionX = WIDTH / 2;
	positionY = HEIGHT / 2;
}

SpaceShip::SpaceShip(EngineManager* engineManagerP) {
	engineManager = engineManagerP;
	positionX = WIDTH / 2;
	positionY = HEIGHT / 2;
	engineManager->GetGraphicEngine()->addObject(this);
}

SpaceShip::~SpaceShip(void){
}

void SpaceShip::move(int dx, int dy) {
	if((positionX + dx + 25) < WIDTH || (positionX + dx - 25) > 0) {
		positionX;
	}
	else if((positionY + dy) < HEIGHT || (positionY + dy - 100) > 0) {
		positionY;
	}
	else {
		positionX += dx;
		positionX += dy;
	}
}

void SpaceShip::displaySingularShip () {
	fill_triangle(positionX + 25 , positionY ,
			      positionX - 25 , positionY ,
				  positionX      , positionY - 100,
				  build_color(250, 250, 250));
}

void SpaceShip::display() {
	fill_triangle(positionX + 25 , positionY ,
			      positionX - 25 , positionY ,
				  positionX      , positionY - 100,
				  build_color(250, 250, 250));
}


int SpaceShip::getPositionX() {
	return positionX;
}

int SpaceShip::getPositionY() {
	return positionY;
}

void SpaceShip::setPositionX(int X) {
	if((X + 25) > WIDTH || (X - 25) < 0) {
		positionX;
	}
	else {
		positionX = X;
	}
} 

void SpaceShip::setPositionY(int Y) {
	if(Y > HEIGHT || (Y - 100) < 0) {
		positionY;
	}
	else {
		positionY = Y;
	}
}


