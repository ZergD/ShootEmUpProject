#include <iostream>
#include "EngineManager.h"
#include "EnemySpaceShip.h"
#include "Shot.h"

#include <boost/math/special_functions/sign.hpp>
                                                                  //le constructeur du SpaceShip s exec avant EnemySpaceShip
EnemySpaceShip::EnemySpaceShip(EngineManager* engineManagerP) : SpaceShip(engineManagerP) {
	positionX = engineManager->GetGraphicEngine()->getWidth() / 2 + 100;
	positionY = engineManager->GetGraphicEngine()->getHeight() / 2;
    if (image == NULL) {

	    image = IMG_Load("Images/SpaceShip_Red.png");
    }
}

EnemySpaceShip::~EnemySpaceShip(void){
}

void EnemySpaceShip::compute() {
	int vitesse = 2;

	int signX = boost::math::sign(positionX - engineManager->GetPlayerSpaceShip()->getPositionX());
	int signY = boost::math::sign(positionY - engineManager->GetPlayerSpaceShip()->getPositionY());

	this->setPositionX(-(signX * vitesse));
	this->setPositionY(-(signY * vitesse));
}

//l enemie est définit vis à vis du playerSpaceShip
bool EnemySpaceShip::isLeft() {
    return ((positionX - engineManager->GetPlayerSpaceShip()->getPositionX()) > 0);
}

bool EnemySpaceShip::isRight() {
    return ((positionX - engineManager->GetPlayerSpaceShip()->getPositionX()) < 0);
}

bool EnemySpaceShip::isBelow() {
    return ((positionY - engineManager->GetPlayerSpaceShip()->getPositionY()) < 0);
}

bool EnemySpaceShip::isAbove() {
    return ((positionY - engineManager->GetPlayerSpaceShip()->getPositionY()) > 0);
}

bool EnemySpaceShip::sameXAxis() {
    return (positionX == engineManager->GetPlayerSpaceShip()->getPositionX());
}

bool EnemySpaceShip::sameYAxis() {
    return (positionY == engineManager->GetPlayerSpaceShip()->getPositionY());
}

void EnemySpaceShip::display() {
	//Graphics::display_image(image, positionX - 50, positionY - 45);
    //std::cout << "enemySpaceShip has been displayed\n";
    engineManager->GetGraphicEngine()->displayImage(image, positionX - 50, positionY - 45);
}
