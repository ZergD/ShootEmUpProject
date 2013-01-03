#include "InputEngine.h"
#include "SDL.h"
#include <iostream>

using namespace std;

InputEngine::InputEngine(void)
{
	display = true;
	toucheAppuyeeUp = false;
	toucheAppuyeeDown = false;
	toucheAppuyeeLeft = false;
	toucheAppuyeeRight = false;
	toucheAppuyeeSpaceBar = false;
}

InputEngine::InputEngine(EngineManager* engineManagerP)
{
	display = true;
	toucheAppuyeeUp = false;
	toucheAppuyeeDown = false;
	toucheAppuyeeLeft = false;
	toucheAppuyeeRight = false;
	toucheAppuyeeSpaceBar = false;
	engineManager = engineManagerP;
}

InputEngine::~InputEngine(void)
{
}

//Getters
bool InputEngine::GetToucheAppuyeeUp() {
	return toucheAppuyeeUp;
}

bool InputEngine::GetToucheAppuyeeDown() {
	return toucheAppuyeeDown;
}

bool InputEngine::GetToucheAppuyeeLeft() {
	return toucheAppuyeeLeft;
}

bool InputEngine::GetToucheAppuyeeRight() {
	return toucheAppuyeeRight;
}

bool InputEngine::GetToucheAppuyeeSpaceBar() {
	return toucheAppuyeeSpaceBar;
}

bool InputEngine::GetDisplay() {
	return display;
}

//Setters
void InputEngine::SetToucheAppuyeeUp(bool boolean) {
	toucheAppuyeeUp = boolean;
}

void InputEngine::SetToucheAppuyeeDown(bool boolean) {
	toucheAppuyeeDown = boolean;
}

void InputEngine::SetToucheAppuyeeLeft(bool boolean) {
	toucheAppuyeeLeft = boolean;
}

void InputEngine::SetToucheAppuyeeRight(bool boolean) {
	toucheAppuyeeRight = boolean;
}

void InputEngine::process() {
	//s'il y a des evenements en attente, on les gere
	while (SDL_PollEvent(&event))
	{
		// si l'utilisateur demande a fermer la fenetre, on quitte le programme
		if (event.type == SDL_QUIT)
			display = false;
		// si l'utilisateur a appuye sur une touche...
		if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
		{
			/* switch pour savoir quelle touche est appuyée */
			switch (event.key.keysym.sym)
			{
				case SDLK_q :
					display = false;
					break;

				case SDLK_UP :
					toucheAppuyeeUp = event.type == SDL_KEYDOWN;
					break;
				case SDLK_DOWN :
					toucheAppuyeeDown = event.type == SDL_KEYDOWN;
					break;
				case SDLK_LEFT :
					toucheAppuyeeLeft = event.type == SDL_KEYDOWN;
					break;
				case SDLK_RIGHT :
					toucheAppuyeeRight = event.type == SDL_KEYDOWN;
					break;
				case SDLK_SPACE :
					toucheAppuyeeSpaceBar = event.type == SDL_KEYDOWN;
				default :
					printf("Unhandled key\n");
			}
		}
	}
}

