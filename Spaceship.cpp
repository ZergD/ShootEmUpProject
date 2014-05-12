#include "SpaceShip.h"
#include "EngineManager.h"

SpaceShip::SpaceShip(EngineManager* engineManagerP) {
    engineManager = engineManagerP;
    time(&lastShootTime);
	positionX = (engineManager->GetGraphicEngine()->getWidth() / 2) - 200;
	positionY = engineManager->GetGraphicEngine()->getHeight() / 2;
	
	image = NULL;
    engineManager->GetGraphicEngine()->addObject(this);
	engineManager->GetStateEngine()->addComputeObject(this);
}

SpaceShip::~SpaceShip(void) {
    engineManager->GetGraphicEngine()->removeObject(this);
    engineManager->GetStateEngine()->removeComputeObject(this);
    SDL_FreeSurface(image);
}

bool SpaceShip::youCanShoot() {
	time_t currentShootTime = NULL;
	time(&currentShootTime);
	double timeDifference = difftime(currentShootTime, lastShootTime);
	if (timeDifference >= 1.00) {
		time(&lastShootTime);
		return true;
	}
	return false;
}

void SpaceShip::setPositionX(int vitesse) {
    if((positionX + vitesse + 40) < engineManager->GetGraphicEngine()->getWidth() && (positionX + vitesse - 40) > 0) {
		positionX += vitesse;
	}
}

void SpaceShip::setPositionY(int vitesse) {
    if((positionY + vitesse + 35 < engineManager->GetGraphicEngine()->getHeight()) && ((positionY + vitesse - 35) > 0)) {
		positionY += vitesse;
	}
}

int SpaceShip::getPositionX() {
    return positionX;
}

int SpaceShip::getPositionY() {
    return positionY;
}
//inline SpaceShip::~SpaceShip() {};