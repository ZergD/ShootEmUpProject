#include <iostream>
#include <boost/lexical_cast.hpp>

#include "Proto/Common/Object.pb.h"

#include "Spaceship.h"
#include "graphics.h"
#include "EngineManager.h"
#include "Shot.h"


SDL_Surface *image = NULL;

SpaceShip::SpaceShip(EngineManager* engineManagerP, ObjectProto proto) : engineManager(engineManagerP) {
	// TODO : parse all system objects ?
	ObjectProto_SystemObjectProto geometrySystemObjectProto = proto.systemobjects().Get(0);
	PropertyProto propertyProto = geometrySystemObjectProto.properties().Get(0);
	time(&lastShootTime);
	positionX = boost::lexical_cast<int> (propertyProto.value().Get(0));
	positionY = boost::lexical_cast<int> (propertyProto.value().Get(1));
	if (image == NULL) {
		image = SDL_LoadBMP("Images/SpaceShip.bmp");
	}
	engineManager->GetGraphicEngine()->addObject(this);
	engineManager->GetStateEngine()->addComputeObject(this);
}

SpaceShip::~SpaceShip(void) {
}

void SpaceShip::move(int dx, int dy) {
	if((positionX + dx + 25) > WIDTH && (positionX + dx - 25) < 0) {
		positionX += dx;
	}
	if((positionY + dy) > HEIGHT && (positionY + dy - 100) < 0) {
		positionY += dy;
	}
}

void SpaceShip::displaySingularShip () {
	Graphics::fill_triangle(positionX + 25 , positionY ,
			      positionX - 25 , positionY ,
				  positionX      , positionY - 100,
				  Graphics::build_color(250, 250, 250));
}

void SpaceShip::display() {
	Graphics::display_image(image, positionX - 50, positionY - 45);
}

void SpaceShip::compute() {
	this->setPositionX(engineManager->GetInputEngine()->getMovementX() * VITESSE);
	this->setPositionY(engineManager->GetInputEngine()->getMovementY() * VITESSE);

	if(engineManager->GetInputEngine()->isShoot() && youCanShoot()) {
		new Shot(engineManager, positionX + 10, positionY - 45);
		new Shot(engineManager, positionX - 10, positionY - 45);
		new Shot(engineManager, positionX + 25, positionY - 45);
		new Shot(engineManager, positionX - 25, positionY - 45);
	}
}

bool SpaceShip::youCanShoot() {
	time_t currentShootTime = 0;
	time(&currentShootTime);
	double timeDifference = difftime(currentShootTime, lastShootTime);
	if (timeDifference >= 1.00) {
		time(&lastShootTime);
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
	if((positionX + vitesse + 50) < WIDTH && (positionX + vitesse - 50) > 0) {
		positionX += vitesse;
	}
} 

void SpaceShip::setPositionY(int vitesse) {
	if((positionY + vitesse + 45 < HEIGHT) && ((positionY + vitesse - 45) > 0)) {
		positionY += vitesse;
	}
}


