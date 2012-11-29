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
	int i, starNumber = 50;
	Star* star = new Star(engineManager);
	Star* star2 = new Star(engineManager);
	Star* star3 = new Star(engineManager);
	Star* star4 = new Star(engineManager);
	/*for(i = 0; i < starNumber; i++) {
		new Star(engineManager);
	}*/
}

void ParticleEngine::process() {
}

