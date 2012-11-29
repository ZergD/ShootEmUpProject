#pragma once
#include <list>
#include "Star.h"

#include "Engine.h"

class ParticleEngine : public Engine
{
	std::list<Star*> StarList;
	EngineManager* engineManager;
public:
	ParticleEngine(void);
	ParticleEngine(EngineManager*);
	~ParticleEngine(void);

	void process();
};

