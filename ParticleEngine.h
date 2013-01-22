#pragma once
#include <list>
#include "Engine.h"
#include "Star.h"

#include "boost/random.hpp"
#include "boost/generator_iterator.hpp"

class ParticleEngine : public Engine {
    std::list<Star*> StarList;
    EngineManager* engineManager;
    boost::random::mt19937 random;
    boost::random::uniform_int_distribution<> generator;

public:
    ParticleEngine(void);
    ParticleEngine(EngineManager*);
    ~ParticleEngine(void);

    void launch();
    void process();
};

