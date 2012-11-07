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

	if(engineManager->GetInputEngine()->GetToucheAppuyeeUp()) {
		spaceShip->setPositionY(spaceShip->getPositionY() - 5);
	}
	if(engineManager->GetInputEngine()->GetToucheAppuyeeDown()) {
		spaceShip->setPositionY(spaceShip->getPositionY() + 5);
	}
	if(engineManager->GetInputEngine()->GetToucheAppuyeeLeft()) {
		spaceShip->setPositionX(spaceShip->getPositionX() - 5);
	}
	if(engineManager->GetInputEngine()->GetToucheAppuyeeRight()) {
		spaceShip->setPositionX(spaceShip->getPositionX() + 5);
	}
}

SpaceShip* StateEngine::GetSpaceShip() {
	return spaceShip;
}

