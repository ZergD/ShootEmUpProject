#include <iostream>
#include "SpaceShip.h"
#include "graphics.h"
#include "EngineManager.h"
#include "Shot.h"

SDL_Surface *image = NULL;

SpaceShip::SpaceShip(EngineManager* engineManagerP, int X, int Y) : engineManager(engineManagerP) {
	positionX = X;
	positionY = Y;
	cout << "SpaceShip created.\n";
}

SpaceShip::SpaceShip(EngineManager* engineManagerP) : engineManager(engineManagerP) {
	time(&start);
	positionX = WIDTH / 2;
	positionY = HEIGHT / 2;
	if (image == NULL) {
		image = SDL_LoadBMP("Images/SpaceShip.bmp");
	}
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
	display_image(image, positionX - 50, positionY - 45);
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
	if(engineManager->GetInputEngine()->GetToucheAppuyeeSpaceBar() && youCanShoot()) {
		new Shot(engineManager, positionX, positionY - 50);
	}
}


bool SpaceShip::youCanShoot() {
	time_t end = NULL;
	time(&end);
	double timeDifference = difftime(end, start);
	cout << "timeDifference = " << timeDifference << " s" << endl;
	if (timeDifference >= 1.00) {
		time(&start);
		return true;
	}
	return false;
}

int SpaceShip::getPositionX() {
	return positionX;
}

int SpaceShip::getPositionY() {
	return positionY;
}

void SpaceShip::setPositionX(int vitesse) {
	if((positionX + vitesse + 50) > WIDTH || (positionX + vitesse - 50) < 0) {
	
	}
	else {
		positionX += vitesse;
	}
} 

void SpaceShip::setPositionY(int vitesse) {
	if((positionY + vitesse + 45 > HEIGHT) || ((positionY + vitesse - 45) < 0)) {
	
	}
	else {
		positionY += vitesse;
	}
}


