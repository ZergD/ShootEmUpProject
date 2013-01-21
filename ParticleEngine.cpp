#include "ParticleEngine.h"
#include "graphics.h"


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
	boost::random::mt19937 rng(std::time(0)); 
	boost::random::uniform_int_distribution<> generator(1, WIDTH);
	int positionX = generator(rng);
	Star* star = new Star(engineManager, positionX, 1, 10);
	positionX = generator(rng);
	Star* star2 = new Star(engineManager, positionX, 1, 10);
	positionX = generator(rng);
	Star* star3 = new Star(engineManager, positionX, 1, 10);
	positionX = generator(rng);
	Star* star4 = new Star(engineManager, positionX, 1, 10);
	/*for(i = 0; i < starNumber; i++) {
		new Star(engineManager);
	}*/
	
}

void ParticleEngine::process() {
}
