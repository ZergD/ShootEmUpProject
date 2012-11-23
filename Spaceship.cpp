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
	engineManager->GetStateEngine()->addComputeObject(this);
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
		positionY += dy;
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

void SpaceShip::compute() {
	int vitesse = 5;

	if(engineManager->GetInputEngine()->GetToucheAppuyeeUp()) {
		this->setPositionY(-vitesse);
	}
	if(engineManager->GetInputEngine()->GetToucheAppuyeeDown()) {
		this->setPositionY(vitesse);
	}
	if(engineManager->GetInputEngine()->GetToucheAppuyeeLeft()) {
		this->setPositionX(-vitesse);
	}
	if(engineManager->GetInputEngine()->GetToucheAppuyeeRight()) {
		this->setPositionX(vitesse);
	}
}


int SpaceShip::getPositionX() {
	return positionX;
}

int SpaceShip::getPositionY() {
	return positionY;
}

void SpaceShip::setPositionX(int vitesse) {
	if((positionX + vitesse + 25) > WIDTH || (positionX + vitesse - 25) < 0) {
	
	}
	else {
		positionX += vitesse;
	}
} 

void SpaceShip::setPositionY(int vitesse) {
	if((positionY + vitesse > HEIGHT) || ((positionY - 100 + vitesse) < 0)) {
		
	}
	else {
		positionY += vitesse;
	}
}


