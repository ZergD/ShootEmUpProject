#include <stdio.h>
#include <SDL.h>
#include "graphics.h"

/**
 * fonction rafraichissant la fenetre infiniment, jusqu'a reception d'un signal
 * d'interruption
 */
void affiche()
{
	/* pour indiquer la fin de l'affichage */
	int display;

	/* pour stocker les evenements */
	SDL_Event event;

	/* couleur noire pour le fond de la fenetre */
	Uint8 fond = build_color(0x00, 0x00, 0x00);

	/* pour indiquer si on doit quitter */
	display = 1;
	while(display)
	{
		/*
		 * s'il y a des evenements en attente, on les gere
		 */
		while (SDL_PollEvent(&event))
		{
			/*
			 * si l'utilisateur a demande a fermer la fenetre, on
			 * quitte le programme
			 */ 
			if (event.type == SDL_QUIT)
				display=0;
			
			/*
			 * si l'utilisateur a appuye sur une touche...
			 */
			if (event.type == SDL_KEYDOWN)
			{
				/**
				 * on quitte si l'utilisateur a appuye sur la
				 * touche q (pour "quitter")
				 */
				switch (event.key.keysym.sym)
				{
					case SDLK_q :
						display=0;
						break;

					case SDLK_UP :
						printf("appui sur la fleche du haut\n");
						break;

					default :
						printf("appui sur une autre touche\n");
				
					/**
					 * voir les autres codes de caracteres sur la page :
					 * http://sdldoc.csn.ul.ie/sdlkey.php
					 */
				}
			}
			/**
			 * voir les autres types d'evenements
			 */
		}
		
		/* on verrouille l'ecran */
		lock();


		/*
		 * on remplit la fenetre avec la couleur cree au debut
		 * de la fonction
		 */
		fill_screen(fond);

		/*
		 * on dessine un triangle de couleur aleatoire
		 */
		fill_triangle(257,177,
		              384,172,
		              278,198,
		              build_color(255,0,0));
		
		//fill_circle(10, 20, 50, random());


		/* on deverouille et on rafraichit l'ecran */
        	unlock();


		/* on attend le temps necessaire pour atteindre le taux de
		 * rafraichissement souhaite
		 */
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
