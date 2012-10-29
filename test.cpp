#include <stdio.h>
#include <SDL.h>
#include "graphics.h"
#include "SpaceShip.h"

/**
 * fonction rafraichissant la fenetre infiniment, jusqu'a reception d'un signal
 * d'interruption
 */
void affiche()
{
	int display = 0; /* pour indiquer la fin de l'affichage */
	SDL_Event event; /* pour stocker les evenements */
	bool toucheAppuyeeUp = false;
	bool toucheAppuyeeDown = false;
	bool toucheAppuyeeLeft = false;
	bool toucheAppuyeeRight = false;

	SpaceShip* spaceShip = new SpaceShip();
	
	/* pour indiquer si on doit quitter */
	display = 1;

	//simple color definitions
	Uint8 fond =  build_color(0x00, 0x00, 0x00);
	Uint8 blanc = build_color(250, 250, 250);
	Uint8 rouge = build_color(250, 0, 0);

	while(display)
	{
		/* s'il y a des evenements en attente, on les gere*/
		while (SDL_PollEvent(&event))
		{			
			/* si l'utilisateur a demande a fermer la fenetre, on quitte le programme*/
			if (event.type == SDL_QUIT)
				display=0;
			
			/* si l'utilisateur a appuye sur une touche...*/
			if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
			{
				/* on quitte si l'utilisateur a appuye sur la touche q (pour "quitter")*/
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
		
		if(toucheAppuyeeUp) {
			spaceShip->setPositionY(spaceShip->getPositionY() - 10);
		}
		if(toucheAppuyeeDown) {
			spaceShip->setPositionY(spaceShip->getPositionY() + 10);
		}
		if(toucheAppuyeeLeft) {
			spaceShip->setPositionX(spaceShip->getPositionX() - 10);
		}
		if(toucheAppuyeeRight) {
			spaceShip->setPositionX(spaceShip->getPositionX() + 10);
		}

		/* on verrouille l'ecran */
		lock();

		/* on remplit la fenetre avec la couleur cree au debut de la fonction */
		fill_screen(fond);

		/* on dessine un triangle*/
		spaceShip->display();

		//fill_circle(10, 20, 50, random());

		/* on deverouille et on rafraichit l'ecran */
        	unlock();

		/* on attend le temps necessaire pour atteindre le taux de rafraichissement souhaite */
		 sync();
	}
	
	printf("fin de l'affichage\n");
}

int main(int argc, char * argv[])
{
	printf("initialisation de la fenetre\n");
	init_graphics();

	printf("lancement de l'affichage\n");
	affiche();

	printf("on quitte\n");
	exit(0);
}