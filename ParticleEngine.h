#pragma once
#include <list>
#include "Engine.h"
#include "Star.h"

#include "boost/random.hpp"
#include "boost/generator_iterator.hpp"

class ParticleEngine : public Engine {
	std::list<Star*> StarList;
	EngineManager* engineManager;
	        // produces randomness out of thin air, see pseudo-random number generators                                 
public:
	ParticleEngine(void);
	ParticleEngine(EngineManager*);
	~ParticleEngine(void);

	void launch();
	void process();
};

