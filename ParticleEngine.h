#pragma once
#include <list>
#include "Engine.h"
#include "Star.h"

#include "boost/random.hpp"
#include "boost/generator_iterator.hpp"

class ParticleEngine : public Engine {
    std::list<Star*> starList;
    EngineManager* engineManager;
    boost::random::mt19937 random;
    boost::random::uniform_int_distribution<> generatorX;
	boost::random::uniform_int_distribution<> generatorY;
	int amountOfStars;

public:
    ParticleEngine(void);
    ParticleEngine(EngineManager*);
    ~ParticleEngine(void);

    void launch();
    void process();
	void addStar(Star*);
	void removeStar(Star*);
};

