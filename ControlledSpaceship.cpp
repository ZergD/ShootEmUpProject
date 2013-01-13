#include "Proto\Common\Object.pb.h"

#include "ControlledSpaceship.h"
#include "EngineManager.h"

ControlledSpaceShip::ControlledSpaceShip(EngineManager* engineManagerP, ObjectProto objectProto) : SpaceShip(engineManagerP, objectProto) {
	
}

ControlledSpaceShip::~ControlledSpaceShip(void){
}

void ControlledSpaceShip::control() {

}
