#pragma once
class Engine
{
public:
	virtual ~ Engine(void);
	virtual void process() = 0;
	
};
	inline Engine::~Engine() {};

 