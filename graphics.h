#include <string.h>
#include <stdlib.h>
#include <SDL.h>

/******************************************************************************
 * gestion de l'affichage et implantation des primitives graphiques           *
 * reposant sur SDL.                                                          *
 *                                                                            *
 * Toutes les fonctions d'affichage effectuent un clipping complet,           *
 * i.e. les extremites de la fenetre sont gerees.                             *
 ******************************************************************************/

namespace Graphics {

	/**
	 * taille de la fenetre
	 */
	#define WIDTH  920
	#define HEIGHT 640

	/**
	 * taux de rafraichissement de la fenetre (images/sec.)
	 */
	#define FRAMERATE 100
	/*
	//simple color definitions
	#define fond =  build_color(0x00, 0x00, 0x00)
	#define blanc = build_color(250, 250, 250)
	#define rouge = build_color(250, 0, 0)
	*/

	/******************************************************************************/


	/* changez cette partie a vos risques et perils... */



	/***************************************
	 * fonctions de gestion de l'affichage *
	 ***************************************/

	/**
	 * initialisation de la fenetre sur laquelle on dessine
	 */
	void init_graphics();

	/**
	 * cree une couleur a partir de ses composantes RGB
	 */
	Uint8 build_color(int r, int g, int b);

	/**
	 * verouille la fenetre pour pouvoir modifier son contenu
	 */
	void lock();

	/**
	 * deverouille et rafraichit la fenetre
	 */
	void unlock();

	/**
	 * bloque l'execution le temps necessaire pour respecter le taux de
	 * rafraichissement souhaite.
	 */
	void sync();




	/***********************
	 * fonctions de dessin *
	 ***********************/

	/**
	 * remplit tout l'ecran d'une couleur
	 */
	void fill_screen(Uint8 color);

	/**
	 * allume un pixel de la couleur demandee
	 */
	void pixel(int x, int y, Uint8 color);

	/**
	 * trace une ligne
	 */
	void draw_line(int x1,int y1, int x2,int y2, Uint8 color);

	/**
	 * affiche un triangle remplis
	 */
	void fill_triangle(int x1, int y1, int x2, int y2, int x3, int y3, Uint8 color);

	/**
	 * trace un cercle
	 */
	void draw_circle(int x, int y, int rayon, Uint8 color);

	/**
	 * trace un cercle remplis
	 */
	void fill_circle(int x, int y, int radius, Uint8 color);

	void display_image(SDL_Surface* image, int x, int y);

}