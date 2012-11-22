#include "StateEngine.h"
#include "EngineManager.h"

StateEngine::StateEngine(void)
{

}

StateEngine::StateEngine(EngineManager* engineManagerP)
{
	engineManager = engineManagerP;
}


StateEngine::~StateEngine(void)
{
	
}

void StateEngine::process() {
	int vitesse = 5;

	if(engineManager->GetInputEngine()->GetToucheAppuyeeUp()) {
		engineManager->GetSpaceShip()->setPositionY(engineManager->GetSpaceShip()->getPositionY() - vitesse);
		//spaceShip->setPositionY(spaceShip->getPositionY() - vitesse);
	}
	if(engineManager->GetInputEngine()->GetToucheAppuyeeDown()) {
		engineManager->GetSpaceShip()->setPositionY(engineManager->GetSpaceShip()->getPositionY() + vitesse);
		//spaceShip->setPositionY(spaceShip->getPositionY() + vitesse);
	}
	if(engineManager->GetInputEngine()->GetToucheAppuyeeLeft()) {
		engineManager->GetSpaceShip()->setPositionX(engineManager->GetSpaceShip()->getPositionX() - vitesse);
		//spaceShip->setPositionX(spaceShip->getPositionX() - vitesse);
	}
	if(engineManager->GetInputEngine()->GetToucheAppuyeeRight()) {
		engineManager->GetSpaceShip()->setPositionX(engineManager->GetSpaceShip()->getPositionX() + vitesse);
		//spaceShip->setPositionX(spaceShip->getPositionX() + vitesse);
	}
}


