#include "ParticleEngine.h"


ParticleEngine::ParticleEngine(void)
{

}


ParticleEngine::~ParticleEngine(void)
{

}

ParticleEngine::ParticleEngine(EngineManager* engineManagerP) {
	engineManager = engineManagerP;
	launch();
}

void ParticleEngine::launch() {
	//int i, starNumber = 50;
	Star* star = new Star(engineManager, 200, 1, 20);
	StarList.push_front(star);
/*	for(i = 0; i < starNumber; i++) {
		Star* starX = new Star(engineManager);
		StarList.push_back(starX);
	}*/
}

