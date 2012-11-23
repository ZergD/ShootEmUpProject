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

void StateEngine::addComputeObject(ComputeObject* computeObject) {
	computeObjectList.push_front(computeObject);
}

void StateEngine::process() {
	
	for (list<ComputeObject*>::iterator it = computeObjectList.begin(); it != computeObjectList.end(); it++) {
			(*it)->compute();
	}
}


