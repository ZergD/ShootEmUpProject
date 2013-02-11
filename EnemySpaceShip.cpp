#include <iostream>
#include "EngineManager.h"
#include "EnemySpaceShip.h"
#include "graphics.h"
#include "Shot.h"
                                                                  //le constructeur du SpaceShip s exec avant EnemySpaceShip
EnemySpaceShip::EnemySpaceShip(EngineManager* engineManagerP) : SpaceShip(engineManagerP) {
    
    positionX = WIDTH / 2 + 100;
	positionY = HEIGHT / 2;
}

EnemySpaceShip::~EnemySpaceShip(void){
}

void EnemySpaceShip::display() {
	//Graphics::display_image(image, positionX - 50, positionY - 45);
    std::cout << "enemySpaceShip has been created\n";
    Graphics::fill_circle(positionX, positionY, 20, Graphics::build_color(204,0,0));
}

void EnemySpaceShip::compute() {
	int vitesse = 2;
    
  /*this->setPositionX(vitesse);
    this->setPositionY(vitesse);*/

    if((positionX - engineManager->GetPlayerSpaceShip()->getPositionX()) > 0) 
        this->setPositionX(-vitesse);
    else 
        this->setPositionX(vitesse);
    if((positionY - engineManager->GetPlayerSpaceShip()->getPositionY()) > 0)
        this->setPositionY(-vitesse);
    else
        this->setPositionY(vitesse);
}
