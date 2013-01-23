#include "ParticleEngine.h"
#include "graphics.h"

using namespace std;

ParticleEngine::ParticleEngine(void) {
    
}


ParticleEngine::~ParticleEngine(void)
{

}

ParticleEngine::ParticleEngine(EngineManager* engineManagerP) {
    random = *new boost::random::mt19937(std::time(0));
	engineManager = engineManagerP;

	amountOfStars = 50;
	generatorX = *new boost::random::uniform_int_distribution<>(1, WIDTH);
	generatorY = *new boost::random::uniform_int_distribution<>(1, HEIGHT);
}

void ParticleEngine::process() {
	int positionX, positionY; 

	while(starList.size() < amountOfStars) {
		positionX = generatorX(random);
		positionY = generatorY(random);
		cout << "la positionX est: " << positionX << " et la positionY est: " << positionY << endl;
		new Star(engineManager, positionX, positionY, 10);
	}
}

void ParticleEngine::addStar(Star* star) {
	starList.push_front(star);
}

void ParticleEngine::removeStar(Star* star) {
	starList.remove(star);
}
