#include <iostream>
#include "EngineManager.h"

using namespace std;

int main(int argc, char * argv[]) {
	EngineManager* engineManager = new EngineManager();
	engineManager->start();	

	return 0;
}
