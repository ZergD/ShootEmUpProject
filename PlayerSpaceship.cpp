#include <iostream>

#include "EngineManager.h"
#include "PlayerSpaceShip.h"
#include "graphics.h"
#include "Shot.h"

SDL_Surface *image = NULL;
                                                                  //le constructeur du SpaceShip s exec avant PlayerSpaceShip
PlayerSpaceShip::PlayerSpaceShip(EngineManager* engineManagerP) : SpaceShip(engineManagerP) {
/*	time(&lastShootTime);
	positionX = WIDTH / 2;
	positionY = HEIGHT / 2;*/
	if (image == NULL) {
		image = SDL_LoadBMP("Images/SpaceShip.bmp");
	}
/*  engineManager->GetGraphicEngine()->addObject(this);
	engineManager->GetStateEngine()->addComputeObject(this); */
}

PlayerSpaceShip::~PlayerSpaceShip(void){
}

void PlayerSpaceShip::display() {
	Graphics::display_image(image, positionX - 50, positionY - 45);
    std::cout << "playerSpaceShip has been created\n";
}

void PlayerSpaceShip::compute() {
	int vitesse = 10;

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
		new Shot(engineManager, positionX + 10, positionY - 45);
		new Shot(engineManager, positionX - 10, positionY - 45);
		new Shot(engineManager, positionX + 25, positionY - 45);
		new Shot(engineManager, positionX - 25, positionY - 45);
	}
}
