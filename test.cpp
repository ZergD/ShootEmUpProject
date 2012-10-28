#include <stdio.h>
#include <SDL.h>
#include "graphics.h"

/**
 * fonction rafraichissant la fenetre infiniment, jusqu'a reception d'un signal
 * d'interruption
 */
void affiche()
{
	int display; /* pour indiquer la fin de l'affichage */
	int dx = 0;
	int dy = 0;
	SDL_Event event; /* pour stocker les evenements */

	/* couleur noire pour le fond de la fenetre */
	Uint8 fond = build_color(0x00, 0x00, 0x00);
	Uint8 blanc = build_color(250, 250, 250);
	/* pour indiquer si on doit quitter */
	display = 1;
	while(display)
	{
		/* s'il y a des evenements en attente, on les gere*/
		while (SDL_PollEvent(&event))
		{			
			/* si l'utilisateur a demande a fermer la fenetre, on quitte le programme*/
			if (event.type == SDL_QUIT)
				display=0;
			
			/* si l'utilisateur a appuye sur une touche...*/
			if (event.type == SDL_KEYDOWN)
			{
				/* on quitte si l'utilisateur a appuye sur la touche q (pour "quitter")*/
				switch (event.key.keysym.sym)
				{
					case SDLK_q :
						display=0;
						break;

					case SDLK_UP :
						printf("appui sur la fleche du haut\n");
						dy += -10;
						break;
					case SDLK_DOWN :
						printf("appui sur la fleche du bas\n");
						dy += 10;
						break;
					case SDLK_LEFT :
						printf("appui sur la fleche de gauche\n");
						dx += -10;
						break;
					case SDLK_RIGHT :
						printf("appui sur la fleche de droite\n");
						dx += 10;
						break;

					default :
						printf("appui sur une autre touche\n");
				}
			}
		}		
		/* on verrouille l'ecran */
		lock();

		/* on remplit la fenetre avec la couleur cree au debut de la fonction */
		fill_screen(fond);

		/* on dessine un triangle*/
		fill_triangle(WIDTH/2 + dx     ,HEIGHT/2 + dy,
				      WIDTH/2 - 25 + dx,HEIGHT - 100 + dy,
					  WIDTH/2 + 25 + dx,HEIGHT - 100 + dy,
					  blanc);
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

/*
int main(int argc, char *argv[]) {
    int continuer = 1;
	SDL_Surface *ecran = NULL;
    SDL_Event event; // Cette variable sert à gerer les evenements

    SDL_Init(SDL_INIT_VIDEO);
	
    ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Gestion des evenements en SDL", NULL);


	while(continuer) {
		SDL_WaitEvent(&event);
		switch (event.type) {
			case SDL_QUIT : 
				continuer = 0;
				break;
			case SDL_KEYDOWN :
				switch(event.key.keysym.sym) {
					case SDLK_ESCAPE : continuer = 0;  // SDLK_UP == up arrow
						break;
				}
				break;
		}	
	}

    SDL_Quit();

    return EXIT_SUCCESS;
}
*/