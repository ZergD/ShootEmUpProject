#pragma once
#include "EngineManager.h"

class ShootEmUp
{
public:
	ShootEmUp(void);
	~ShootEmUp(void);

	void launch();

private:
	EngineManager* engineManager;
};

