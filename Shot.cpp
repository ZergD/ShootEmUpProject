#include "Shot.h"
#include <iostream>
#include "EngineManager.h"

using namespace std;

Shot::Shot(int X, int Y) {
	positionX = X;
	positionY = Y;
}

Shot::Shot(void){
	positionX = engineManager->GetGraphicEngine()->getWidth() / 2;
	positionY = engineManager->GetGraphicEngine()->getHeight() / 2;
}

Shot::Shot(EngineManager* engineManagerP, int X, int Y) {
	longueur = -25;
	engineManager = engineManagerP;
	positionX = X;
	positionY = Y;
	engineManager->GetGraphicEngine()->addObject(this);
	engineManager->GetStateEngine()->addComputeObject(this);
}

Shot::~Shot(void){
	engineManager->GetStateEngine()->removeComputeObject(this);
	engineManager->GetGraphicEngine()->removeObject(this);
}

void Shot::move(int dx, int dy) {
	if((positionX + dx + 25) > engineManager->GetGraphicEngine()->getWidth() && (positionX + dx - 25) < 0) {
		positionX += dx;
	}
	if((positionY + dy) > engineManager->GetGraphicEngine()->getHeight() && (positionY + dy - 100) < 0) {
		positionY += dy;
	}
}

void Shot::display() {
	//Graphics::draw_line(positionX,positionY, positionX, positionY + longueur, Graphics::build_color(250, 250, 250));
	//Graphics::draw_line(positionX + 1,positionY, positionX + 1, positionY + longueur, Graphics::build_color(250, 250, 250));
	//Graphics::draw_line(positionX - 1,positionY, positionX - 1, positionY + longueur, Graphics::build_color(250, 250, 250));
}

void Shot::compute() {
	int vitesse = 15;

	this->setPositionY(-vitesse);
}


int Shot::getPositionX() {
	return positionX;
}

int Shot::getPositionY() {
	return positionY;
}

void Shot::setPositionX(int vitesse) {
	if((positionX + vitesse + 25) > engineManager->GetGraphicEngine()->getWidth() || (positionX + vitesse - 25) < 0) {
	
	}
	else {
		positionX += vitesse;
	}
} 

void Shot::setPositionY(int vitesse) {
	if(positionY < 0 || positionY > engineManager->GetGraphicEngine()->getHeight())  {
		delete(this);
	}
	else {
		positionY += vitesse;
	}
}


