#include "Shot.h"
#include <iostream>
#include "graphics.h"
#include "EngineManager.h"


using namespace std;

Shot::Shot(int X, int Y) {
	positionX = X;
	positionY = Y;
	cout << "Shot created.\n";
}

Shot::Shot(void){
	positionX = WIDTH / 2;
	positionY = HEIGHT / 2;
}

Shot::Shot(EngineManager* engineManagerP, int X, int Y) {
	engineManager = engineManagerP;
	positionX = X;
	positionY = Y;
	engineManager->GetGraphicEngine()->addObject(this);
	engineManager->GetStateEngine()->addComputeObject(this);
}

Shot::~Shot(void){
}

void Shot::move(int dx, int dy) {
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

void Shot::display() {
	draw_line(positionX,positionY, positionX, positionY + 10, build_color(250, 250, 250));
}

void Shot::compute() {
	int vitesse = 3;

	this->setPositionY(-vitesse);
}


int Shot::getPositionX() {
	return positionX;
}

int Shot::getPositionY() {
	return positionY;
}

void Shot::setPositionX(int vitesse) {
	if((positionX + vitesse + 25) > WIDTH || (positionX + vitesse - 25) < 0) {
	
	}
	else {
		positionX += vitesse;
	}
} 

void Shot::setPositionY(int vitesse) {
	if((positionY + vitesse > HEIGHT) || ((positionY - 100 + vitesse) < 0)) {
		
	}
	else {
		positionY += vitesse;
	}
}


