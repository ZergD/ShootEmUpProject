#include "InputEngine.h"
#include "SDL.h"
#include <iostream>

InputEngine::InputEngine(EngineManager* engineManagerP) {
	engineManager = engineManagerP;
	display = true;
	movementX = 0;
	movementY = 0;
	shoot = false;
	logAsPlayer = 0;
}

InputEngine::~InputEngine(void) {
}

void InputEngine::process() {
	//s'il y a des evenements en attente, on les gere
	while (SDL_PollEvent(&event))
	{
		// si l'utilisateur demande a fermer la fenetre, on quitte le programme
		if (event.type == SDL_QUIT) {
			display = false;
			continue;			
		}

		// si l'utilisateur a appuye sur une touche...
		if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
			/* switch pour savoir quelle touche est appuyée */
			switch (event.key.keysym.sym) {
				case SDLK_ESCAPE :
					display = false;
					break;

				case SDLK_F1 :
					if (logAsPlayer == 0) {
						logAsPlayer = 1;
					}
					break;
				case SDLK_F2 :
					if (logAsPlayer == 0) {
						logAsPlayer = 2;
					}
					break;

				case SDLK_UP :
					movementY = event.type == SDL_KEYDOWN ? -1 : 0;
					break;
				case SDLK_DOWN :
					movementY = event.type == SDL_KEYDOWN ? 1 : 0;
					break;
				case SDLK_LEFT :
					movementX = event.type == SDL_KEYDOWN ? -1 : 0;
					break;
				case SDLK_RIGHT :
					movementX = event.type == SDL_KEYDOWN ? 1 : 0;
					break;
				case SDLK_SPACE :
					shoot = event.type == SDL_KEYDOWN;

				default :
					printf("Unhandled key %s\n", SDL_GetKeyName(event.key.keysym.sym));
			}
		}
	}
}

//Getters
bool InputEngine::isDisplay() {
	return display;
}

int InputEngine::getMovementX() {
	return movementX;
}

int InputEngine::getMovementY() {
	return movementY;
}

bool InputEngine::isShoot() {
	return shoot;
}

int InputEngine::getLogAsPlayer() {
	return logAsPlayer;
}

void InputEngine::resetLogAsPlayer() {
	logAsPlayer = -1;
}

