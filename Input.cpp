#include "Input.h"
#include "SDL.h"
#include <stdio.h>

Input::Input(void)
{
	toucheAppuyeeUp = false;
	toucheAppuyeeDown = false;
	toucheAppuyeeLeft = false;
	toucheAppuyeeRight = false;
}

Input::~Input(void)
{
}

void Input::keyboardInputManager() {

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

				default :
					printf("appui sur une autre touche\n");
			}
		}
	}
}
//Getters
bool Input::GetToucheAppuyeeUp() {
	return toucheAppuyeeUp;
}

bool Input::GetToucheAppuyeeDown() {
	return toucheAppuyeeDown;
}

bool Input::GetToucheAppuyeeLeft() {
	return toucheAppuyeeLeft;
}

bool Input::GetToucheAppuyeeRight() {
	return toucheAppuyeeRight;
}

int Input::GetDisplay() {
	return display;
}

//Setters
void Input::SetToucheAppuyeeUp(bool boolean) {
	toucheAppuyeeUp = boolean;
}

void Input::SetToucheAppuyeeDown(bool boolean) {
	toucheAppuyeeDown = boolean;
}

void Input::SetToucheAppuyeeLeft(bool boolean) {
	toucheAppuyeeLeft = boolean;
}

void Input::SetToucheAppuyeeRight(bool boolean) {
	toucheAppuyeeRight = boolean;
}

