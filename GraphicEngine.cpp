#include "GraphicEngine.h"
#include "EngineManager.h"

GraphicEngine::GraphicEngine(void)
{

}

GraphicEngine::GraphicEngine(EngineManager* EngineManagerP) {
	engineManager = EngineManagerP;
}


GraphicEngine::~GraphicEngine(void)
{
}

void GraphicEngine::process() {	
		
		// on verrouille l'ecran /
		lock();

		// on remplit la fenetre avec la couleur cree au debut de la fonction
		fill_screen(build_color(0, 0, 0));

		// on dessine un triangle
		engineManager->GetStateEngine()->GetSpaceShip()->display();

		// on deverouille et on rafraichit l'ecran
        unlock();

		//on attend le temps necessaire pour atteindre le taux de rafraichissement souhaite
		 sync();
}
