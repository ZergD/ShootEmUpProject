#include "InputEngine.h"
#include "SDL.h"
#include <iostream>

using namespace std;

InputEngine::InputEngine(void)
{
	int display = 0;
	toucheAppuyeeUp = false;
	toucheAppuyeeDown = false;
	toucheAppuyeeLeft = false;
	toucheAppuyeeRight = false;
}

InputEngine::InputEngine(EngineManager* engineManagerP)
{
	int display = 0;
	toucheAppuyeeUp = false;
	toucheAppuyeeDown = false;
	toucheAppuyeeLeft = false;
	toucheAppuyeeRight = false;
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

int InputEngine::GetDisplay() {
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
			display=0;
		// si l'utilisateur a appuye sur une touche...
		if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
		{
			/* switch pour savoir quelle touche est appuyée */
			switch (event.key.keysym.sym)
			{
				case SDLK_q :
					display=0;
					break;

				case SDLK_UP :
					printf("appui sur la fleche du haut\n");
					toucheAppuyeeUp = event.type == SDL_KEYDOWN;
					break;
				case SDLK_DOWN :
					printf("appui sur la fleche du bas\n");
					toucheAppuyeeDown = event.type == SDL_KEYDOWN;
					break;
				case SDLK_LEFT :
					printf("appui sur la fleche de gauche\n");
					toucheAppuyeeLeft = event.type == SDL_KEYDOWN;
					break;
				case SDLK_RIGHT :
					printf("appui sur la fleche de droite\n");
					toucheAppuyeeRight = event.type == SDL_KEYDOWN;
					break;
				case SDLK_SPACE :
					printf("appui sur spaceBar\n");
					event.type == SDL_KEYDOWN;

				default :
					printf("appui sur une autre touche\n");
			}
		}
	}
}

