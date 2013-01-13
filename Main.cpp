#include <iostream>
#include "EngineManager.h"

int main(int argc, char * argv[]) {
	EngineManager* engineManager = new EngineManager();
	engineManager->start();	

	return 0;
}
