#pragma once
#include <list>
#include "Star.h"

class ParticleEngine
{
	std::list<Star*> StarList;
	EngineManager* engineManager;
public:
	ParticleEngine(void);
	ParticleEngine(EngineManager*);
	~ParticleEngine(void);
	void launch();
};

