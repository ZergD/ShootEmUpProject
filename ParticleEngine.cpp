#include "ParticleEngine.h"
#include "graphics.h"


ParticleEngine::ParticleEngine(void) {
    random = *new boost::random::mt19937(std::time(0));
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
    generator = *new boost::random::uniform_int_distribution<>(1, WIDTH);
    int positionX = generator(random);
    Star* star = new Star(engineManager, positionX, 1, 10);
    positionX = generator(random);
    Star* star2 = new Star(engineManager, positionX, 1, 10);
    positionX = generator(random);
    Star* star3 = new Star(engineManager, positionX, 1, 10);
    positionX = generator(random);
    Star* star4 = new Star(engineManager, positionX, 1, 10);
    /*for(i = 0; i < starNumber; i++) {
        new Star(engineManager);
    }*/
    
}

void ParticleEngine::process() {
}
