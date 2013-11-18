#include "ShootEmUp.h"
#include <boost/thread/thread.hpp>


ShootEmUp::ShootEmUp(void)
{
	engineManager = new EngineManager(this);	
	stateManager = new StateManager(this);
}


ShootEmUp::~ShootEmUp(void)
{

}

void ShootEmUp::launch(){
	while(engineManager->GetInputEngine()->GetDisplay()){
		engineManager->start();
		stateManager->start();
		boost::this_thread::sleep(boost::posix_time::milliseconds(20));
	}
}

EngineManager* ShootEmUp::getEngineManager() {
    return engineManager;
}

StateManager* ShootEmUp::getStateManager() {
    return stateManager;
}

SDL_Event ShootEmUp::getSDL_Event(){
	return event;
}