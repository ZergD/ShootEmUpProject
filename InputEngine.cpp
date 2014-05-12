#include "InputEngine.h"
#include <iostream>
#include "EngineManager.h"
#include "ShootEmUp.h"

//class ShootEmUp;

InputEngine::InputEngine(void)
{
	display = true;
	toucheAppuyeeSpaceBar = false;
}

InputEngine::InputEngine(EngineManager* engineManagerP)
{
	display = true;

	toucheAppuyeeSpaceBar = false;
	engineManager = engineManagerP;
	
}

InputEngine::~InputEngine(void)
{
}

bool InputEngine::GetToucheAppuyeeSpaceBar() {
	return toucheAppuyeeSpaceBar;
}

bool InputEngine::GetDisplay() {
	return display;
}

void InputEngine::setDisplay(bool displayArg){
	display = displayArg;
}

SDL_Event InputEngine::getSDL_Event(){
	return engineManager->getShootEmUp()->getSDL_Event();
}

void InputEngine::process() {
	SDL_Event event = engineManager->getShootEmUp()->getSDL_Event();
	//s'il y a des evenements en attente, on les gere
	while (SDL_PollEvent(&event))
	{
		// si l'utilisateur demande a fermer la fenetre, on quitte le programme
		if (event.type == SDL_QUIT)
			display = false;
		// si l'utilisateur a appuye sur une touche...
		//if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) { //|| event2.type == SDL_KEYUP
            for (list<InputObject*>::iterator it = inputObjectList.begin(); it != inputObjectList.end(); it++) {
		        (*it)->process(event);// CEST LE PROCESS de l interface InputObject
	        }
		//}
	}
}

void InputEngine::addInputObject(InputObject* inputObject){
	inputObjectList.push_front(inputObject);
}

void InputEngine::removeInputObject(InputObject* inputObject){
	inputObjectList.remove(inputObject);
}