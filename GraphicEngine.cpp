#include "graphics.h"
#include "GraphicEngine.h"
#include "EngineManager.h"

GraphicEngine::GraphicEngine(EngineManager* EngineManagerP) {
	engineManager = EngineManagerP;
	
	Graphics::init_graphics();
	backgroundColor = Graphics::build_color(0, 0, 0);
}

GraphicEngine::~GraphicEngine(void) {

}

void GraphicEngine::addObject(DisplayObject* displayObject) {
	displayObjectList.push_front(displayObject);
}

void GraphicEngine::removeObject(DisplayObject* displayObject) {
	displayObjectList.remove(displayObject);
}

void GraphicEngine::process() {
	// on verrouille l'ecran /
	Graphics::lock();

	// on remplit la fenetre avec la couleur cree au debut de la fonction
	Graphics::fill_screen(backgroundColor);
		
	for (list<DisplayObject*>::iterator it = displayObjectList.begin(); it != displayObjectList.end(); it++) {
			(*it)->display();
	}

	// on deverouille et on rafraichit l'ecran
    Graphics::unlock();

	//on attend le temps necessaire pour atteindre le taux de rafraichissement souhaite
	Graphics::sync();
}
