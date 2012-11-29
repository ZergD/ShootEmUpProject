#include "Star.h"
#include <iostream>
#include "graphics.h"
#include "EngineManager.h"

using namespace std;

Star::Star(int X, int Y) {
	positionX = X;
	positionY = Y;
	cout << "Star created.\n";
}

Star::Star(void){
	positionX = WIDTH / 2;
	positionY = HEIGHT / 2;
}

Star::Star(EngineManager* engineManagerP, int X, int Y, int size) {
	size = -25;
	engineManager = engineManagerP;
	positionX = X;
	positionY = Y;
	engineManager->GetGraphicEngine()->addObject(this);
	engineManager->GetStateEngine()->addComputeObject(this);
}

Star::~Star(void){
	engineManager->GetStateEngine()->removeComputeObject(this);
	engineManager->GetGraphicEngine()->removeObject(this);
}

void Star::move(int dx, int dy) {
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

void Star::display() {

}

void Star::compute() {
	int vitesse = 10;

	this->setPositionY(-vitesse);
}


int Star::getPositionX() {
	return positionX;
}

int Star::getPositionY() {
	return positionY;
}

void Star::setPositionX(int vitesse) {
	if((positionX + vitesse + 25) > WIDTH || (positionX + vitesse - 25) < 0) {
	
	}
	else {
		positionX += vitesse;
	}
} 

void Star::setPositionY(int vitesse) {
	if(positionY < 0 || positionY > HEIGHT)  {
		delete(this);
	}
	else {
		positionY += vitesse;
	}
}


