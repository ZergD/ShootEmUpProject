#include "ShootEmUp.h"
#include <boost/thread/thread.hpp>


ShootEmUp::ShootEmUp(void)
{
	engineManager = new EngineManager(this);	
}


ShootEmUp::~ShootEmUp(void)
{

}

void ShootEmUp::launch(){
	while(engineManager->GetInputEngine()->GetDisplay()){
		engineManager->start();
		boost::this_thread::sleep(boost::posix_time::milliseconds(20));
	}
}