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

void StateEngine::removeComputeObject(ComputeObject* computeObject) {
	computeObjectList.remove(computeObject);
}

void StateEngine::process() {
	list<ComputeObject*>::iterator it = computeObjectList.begin();
	while(it != computeObjectList.end()) {
		(*it++)->compute();
	}
}


