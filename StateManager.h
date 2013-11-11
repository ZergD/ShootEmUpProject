#pragma once
#include "State.h"
#include <map>

class ShootEmUp;

class StateManager{

public:
	StateManager(void);
	StateManager(ShootEmUp*);
	~StateManager(void);

	enum StateType{NONE, GENERAL_MENU, GAME_MODE0};
	
	StateType currentType;
	StateType nextType;

	void start();
	void setNxtMenu(StateType);
	ShootEmUp* getShootEmUp();

protected:
	ShootEmUp* shootEmUp;
	std::map<StateType, State*> states;
};

