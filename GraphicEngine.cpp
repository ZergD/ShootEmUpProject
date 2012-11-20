#include "GraphicEngine.h"
#include "EngineManager.h"

using namespace std;

GraphicEngine::GraphicEngine(void)
{

}

GraphicEngine::GraphicEngine(EngineManager* EngineManagerP) {
	engineManager = EngineManagerP;
	addSpaceShip();
}


GraphicEngine::~GraphicEngine(void)
{
}

void GraphicEngine::addSpaceShip(){
	displayObjectList.push_front(engineManager->GetStateEngine()->GetSpaceShip());
}

void GraphicEngine::process() {	
		
	// on verrouille l'ecran /
	lock();

	// on remplit la fenetre avec la couleur cree au debut de la fonction
	fill_screen(build_color(0, 0, 0));

	// on dessine un triangle
	//engineManager->GetStateEngine()->GetSpaceShip()->displaySingularShip();
		
	for (list<DisplayObject*>::iterator it = displayObjectList.begin(); it != displayObjectList.end(); it++) {
			(*it)->display();
	}	
	//engineManager->GetGraphicEngine()->addSpaceship();

	// on deverouille et on rafraichit l'ecran
    unlock();

	//on attend le temps necessaire pour atteindre le taux de rafraichissement souhaite
		sync();
}
