#include <stdio.h>
#include <SDL.h>
#include "graphics.h"
#include "SpaceShip.h"
#include "Input.h"

/**
 * fonction rafraichissant la fenetre infiniment, jusqu'a reception d'un signal
 * d'interruption
 */
void affiche()
{
	Input* input = new Input();

	SpaceShip* spaceShip = new SpaceShip();

	//simple color definitions
	Uint8 fond =  build_color(0x00, 0x00, 0x00);
	Uint8 blanc = build_color(250, 250, 250);
	Uint8 rouge = build_color(250, 0, 0);

	while(input->GetDisplay()) {
			input->keyboardInputManager();

		if(input->GetToucheAppuyeeUp()) {
			spaceShip->setPositionY(spaceShip->getPositionY() - 5);
		}
		if(input->GetToucheAppuyeeDown()) {
			spaceShip->setPositionY(spaceShip->getPositionY() + 5);
		}
		if(input->GetToucheAppuyeeLeft()) {
			spaceShip->setPositionX(spaceShip->getPositionX() - 5);
		}
		if(input->GetToucheAppuyeeRight()) {
			spaceShip->setPositionX(spaceShip->getPositionX() + 5);
		}

		/* on verrouille l'ecran */
		lock();

		/* on remplit la fenetre avec la couleur cree au debut de la fonction */
		fill_screen(fond);

		/* on dessine un triangle*/
		spaceShip->display();

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
