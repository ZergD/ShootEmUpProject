#include <SDL.h>
#include "graphics.h"

namespace Graphics {

	/**
	 * fenetre sur laquelle on dessine
	 */
	SDL_Surface * screen;

	/* decalage pour les calculs en virgule fixe */
	#define DECAL 16

	/* masque pour premier chiffre decimal */
	#define MASK 0x8000

	#define SWAP(a, b)\
	{\
		a = a^b;\
		b = b^a;\
		a = a^b;\
	}


	Uint8 build_color(int r, int g, int b)
	{
		return SDL_MapRGB(screen->format, r, g, b);
	}

	void lock()
	{
		if (SDL_MUSTLOCK(screen))
		{
			if (SDL_LockSurface(screen) < 0)
			{
				fprintf(stderr, "Impossible de verrouiller l'ecran : %s\n", SDL_GetError());
				exit(1);
			}
		}

	}

	void unlock()
	{
	        if (SDL_MUSTLOCK(screen))
		{
			SDL_UnlockSurface(screen);
		}

		SDL_UpdateRect(screen, 0, 0, WIDTH, HEIGHT);
	}

	void pixel(int x, int y, Uint8 color)
	{
		if (x < 0 || x >= WIDTH)
			return;
			
		if (y < 0 || y >= HEIGHT)
			return;
			
		
		*((Uint8 *)screen->pixels + y * WIDTH + x) = color;
	}

	void hline(int xdeb, int xfin, int y, Uint8 color)
	{
	/* cette fonction est une fonction interne, vous ne devriez pas avoir
	 * a l'utiliser (c'est la raison pour laquelle elle n'est pas declaree dans
	 * le fichier header).
	 */

		/* Clipping vertical */
		if (y < 0 || y > HEIGHT)
			return;

		/* Clipping horizontal gauche */
		if (xdeb < 0)
			xdeb = 0;
		else if (xdeb >= WIDTH)
			xdeb = WIDTH-1;

		/* Clipping horizontal droit */
		if (xfin < 0)
			xfin = 0;
		else if (xfin >= WIDTH)
			xfin = WIDTH-1;

		/* on remplit la zone de mémoire contigue correspondant a la ligne */
		memset((void *) ((size_t) (screen->pixels) + (y * WIDTH) + xdeb), color, (xfin - xdeb));
	}

	void fill_screen(Uint8 color)
	{
		memset(screen->pixels, color, WIDTH*HEIGHT);
	}

	void draw_line(int x1,int y1, int x2,int y2, Uint8 color)
	{
		int x, y;
		int Dx, Dy;
		int yincr;
		int erreur;
		int i;

		/**
		 * si c'est possible, on utilise la version optimisee pour les lignes
		 * horizontales
		 */
		if (y1 == y2)
		{
			if (x1 < x2)
				hline(x1, x2, y1, color);
			else
				hline(x2, x1, y1, color);
			
			return;
		}

		if (x2<x1)
		{
			SWAP(x1, x2);
			SWAP(y1, y2);
		}
		
		if(y1<y2)
			yincr = 1;
		else
			yincr = -1;

		/* pour Dx on n'utilise pas de valeur absolue car x2>x1 */
		Dx = x2-x1;
		Dy = abs(y2-y1);
		
		/* Trace de ligne */
		x = x1;
		y = y1;
		
		if(Dx>Dy)
		{
			erreur = Dx/2;
			for(i=0;i<Dx;i++)
			{
				x++;
				erreur += Dy;
				if(erreur>Dx)
				{
					erreur -= Dx;
					y += yincr;
				}
				
				/* clipping sur la fin*/
				if (x>=WIDTH || y>=HEIGHT)
					break;
				
				/* clipping sur le debut de l'ecran.
				 * on ne sort pas de la fonction car il faut continuer
				 * jusqu'au debut de l'ecran pour commencer l'affichage
				 */
				if (x>=0 && y>=0)
					pixel(x, y, color);
			}
		}
		else
		{
			erreur = Dy/2;
			for(i=0; i<Dy; i++)
			{
				y += yincr;
				erreur += Dx;
				if(erreur>Dy)
				{
					erreur -= Dy;
					x++;
				}
				
				/* clipping sur la fin*/
				if (x>=WIDTH || y>=HEIGHT)
					break;
				
				/* clipping sur le haut de l'ecran.
				 * on ne sort pas de la fonction car il faut continuer
				 * jusqu'au debut de l'ecran pour commencer l'affichage
				 */
				if (x>=0 && y>=0)
					pixel(x, y, color);
			}
		}
	}

	void fill_triangle(int x1, int y1, int x2, int y2, int x3, int y3, Uint8 color)
	{
		/* l'initialisation de delta_g sert a virer un warning a la con */
		int delta_g=0, delta_d;
		int x_d, x_g;
		int g_tmp, d_tmp;
		int y;
		int boolean = false;
			
		/**
		 *permutations pour avoir y1 < y2 < y3
		 */
		if (y1>y2)
		{
			SWAP(x1, x2);
			SWAP(y1, y2);
		}
		if (y1>y3)
		{
			SWAP(x1, x3);
			SWAP(y1, y3);
		}
		if (y2>y3)
		{
			SWAP(x2, x3);
			SWAP(y2, y3);
		}
		
		if (y1 == y3)
			return;

		delta_d = ((x3-x1)<<DECAL)/(y3-y1);
		/**
		 * partie superieure du triangle
		 */
		if (y2!=y1)
		{
			delta_g = ((x2-x1)<<DECAL)/(y2-y1);
			x_d = x_g = x1<<DECAL;
			
			
			/* pour avoir x_deb < x_fin */
			boolean = (delta_g > delta_d);
			if (boolean)
				SWAP(delta_g, delta_d);
			
			/**
			 * on decale de 0.5 vers l'exterieur pour reduire les erreurs
			 * d'arrondis
			 */
			x_d += (1<<(DECAL-2));
			x_g -= (1<<(DECAL-2));
			
			for (y=y1; y<y2; y++)
			{
				/* clipping vertical sur la fin de l'ecran */
				if (y>HEIGHT)
					return;
				
				g_tmp = x_g>>DECAL;
				d_tmp = x_d>>DECAL;
				
				/* precision au demi-pixel (la vache !) */
				if(x_g & MASK)
					g_tmp++;
				if(x_d & MASK)
					d_tmp++;
				

				hline(g_tmp, d_tmp, y, color);
				
				x_g += delta_g;
				x_d += delta_d;
			}
		}
		else
		{
			x_g=x2<<DECAL;
			x_d=x1<<DECAL;
		}

		/**
		 * partie inferieure du triangle
		 */
		if (y3!=y2)
		{
			/* cas ou on avait inverse les x dans la partie superieure */
			if (boolean)
				delta_d = ((x3-x2)<<DECAL)/(y3-y2);
			else
				delta_g = ((x3-x2)<<DECAL)/(y3-y2);
			
			/* pour avoir x_deb < x_fin */
			if (delta_g < delta_d)
			{
				SWAP(delta_g, delta_d);
				SWAP(x_g, x_d);
			}
			
			for (y=y2; y<y3; y++)
			{
				/* clipping vertical*/
				if (y>HEIGHT)
					return;
					
				g_tmp = x_g>>DECAL;
				d_tmp = x_d>>DECAL;
				
				/* precision au demi-pixel (la vache !) */
				
				if(x_g & MASK)
					g_tmp++;
				if(x_d & MASK)
					d_tmp++;
					

				hline(g_tmp, d_tmp, y, color);
				
				x_g += delta_g;
				x_d += delta_d;
			}
		}
	}

	void draw_circle(int x, int y, int radius, Uint8 color)
	{
		int d, xoffset, yoffset;

		d = 3 - (radius<<1);
		xoffset = 0;
		yoffset = radius;

		while (yoffset > xoffset)
		{
			pixel(x + xoffset, y + yoffset, color);
			pixel(x + yoffset, y + xoffset, color);
			pixel(x - xoffset, y + yoffset, color);
			pixel(x - yoffset, y + xoffset, color);
			pixel(x + xoffset, y - yoffset, color);
			pixel(x + yoffset, y - xoffset, color);
			pixel(x - xoffset, y - yoffset, color);
			pixel(x - yoffset, y - xoffset, color);

			if (d < 0)
			{
				d = d + (xoffset<<2) + 6;
			}
			else
			{
				d = d + ((xoffset - yoffset)<<2) + 10;
				yoffset--;
			}
			xoffset++;
		}
	}

	void fill_circle(int x, int y, int radius, Uint8 color)
	{
		int d, xoffset, yoffset;

		d = 3 - (radius<<1);
		xoffset = 0;
		yoffset = radius;

		while (yoffset > xoffset)
		{
			hline(x - xoffset, x + xoffset, y + yoffset, color);
			hline(x - yoffset, x + yoffset, y + xoffset, color);
			hline(x - xoffset, x + xoffset, y - yoffset, color);
			hline(x - yoffset, x + yoffset, y - xoffset, color);

			if (d < 0)
			{
				d = d + (xoffset<<2) + 6;
			}
			else
			{
				d = d + ((xoffset - yoffset)<<2) + 10;
				yoffset--;
			}
			xoffset++;
		}
	}

	void init_graphics()
	{
		screen = SDL_SetVideoMode(WIDTH, HEIGHT, 8, SDL_SWSURFACE);
		if ( screen == NULL )
		{
			fprintf(stderr, "Impossible de passer en %dx%d en 8 bpp: %s\n", WIDTH, HEIGHT, SDL_GetError());
			exit(1);
		}
		
	}

	void sync()
	{
		static Uint32 next_time = 0;
		Uint32 now = SDL_GetTicks();
		
		if( now < next_time )
			SDL_Delay( next_time-now );

		next_time += 1000 / FRAMERATE;
	}

	void display_image(SDL_Surface* image, int x, int y) {
		SDL_Rect position;

	    position.x = x;
	    position.y = y;
		SDL_BlitSurface(image, NULL, screen, &position);
		SDL_Flip(screen);
	}

}