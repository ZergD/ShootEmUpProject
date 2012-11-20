#include "StateEngine.h"
#include "EngineManager.h"

StateEngine::StateEngine(void)
{

}

StateEngine::StateEngine(EngineManager* engineManagerP)
{
	engineManager = engineManagerP;
	spaceShip = new SpaceShip();
}


StateEngine::~StateEngine(void)
{
	
}

void StateEngine::process() {
	int vitesse = 5;

	if(engineManager->GetInputEngine()->GetToucheAppuyeeUp()) {
		spaceShip->setPositionY(spaceShip->getPositionY() - vitesse);
	}
	if(engineManager->GetInputEngine()->GetToucheAppuyeeDown()) {
		spaceShip->setPositionY(spaceShip->getPositionY() + vitesse);
	}
	if(engineManager->GetInputEngine()->GetToucheAppuyeeLeft()) {
		spaceShip->setPositionX(spaceShip->getPositionX() - vitesse);
	}
	if(engineManager->GetInputEngine()->GetToucheAppuyeeRight()) {
		spaceShip->setPositionX(spaceShip->getPositionX() + vitesse);
	}
}

SpaceShip* StateEngine::GetSpaceShip() {
	return spaceShip;
}

