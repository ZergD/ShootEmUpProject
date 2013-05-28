#include "SpaceShip.h"
#include "graphics.h"
#include "EngineManager.h"

SpaceShip::SpaceShip(EngineManager* engineManagerP) {
    engineManager = engineManagerP;
    time(&lastShootTime);
	positionX = WIDTH / 2;
	positionY = HEIGHT / 2;
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
    if((positionX + vitesse + 50) < WIDTH && (positionX + vitesse - 50) > 0) {
		positionX += vitesse;
	}
}

void SpaceShip::setPositionY(int vitesse) {
    if((positionY + vitesse + 45 < HEIGHT) && ((positionY + vitesse - 45) > 0)) {
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