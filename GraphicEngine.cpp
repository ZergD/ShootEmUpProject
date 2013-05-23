#include "GraphicEngine.h"
#include "EngineManager.h"

GraphicEngine::GraphicEngine(EngineManager* EngineManagerP) {
	engineManager = EngineManagerP;
	
    width = 800; height = 600;
    background = NULL;
    SDL_Init(SDL_INIT_VIDEO);
	screen = SDL_SetVideoMode(width, height, 32, SDL_HWSURFACE);

}

GraphicEngine::~GraphicEngine(void) {
    SDL_FreeSurface(background);
    SDL_FreeSurface(screen);
}

void GraphicEngine::displayImage(SDL_Surface* image, int x, int y) {
    SDL_Rect position;

    position.x = x;
    position.y = y;
    SDL_BlitSurface(image, NULL, screen, &position);
}

void GraphicEngine::addObject(DisplayObject* displayObject) {
	displayObjectList.push_front(displayObject);
}

void GraphicEngine::removeObject(DisplayObject* displayObject) {
	displayObjectList.remove(displayObject);
}

void GraphicEngine::loadBackground(){
    int flags = IMG_INIT_JPG|IMG_INIT_PNG;
    int initted = IMG_Init(flags);
    if(initted&flags != flags){
        cout << "error failed to init required jpg and pnj support\n";
    }
    background = IMG_Load("Images/Background.jpg");
    if(!background){
        cout << "IMG_Load: " << IMG_GetError() << "\n";
    }
    if (SDL_BlitSurface(background,NULL,screen,NULL) == -1 ){
        cout<<"Couldnt do background blitting " << endl;
    }
}

void GraphicEngine::process() {
	// on verrouille l'ecran /
	//Graphics::lock();

    SDL_WM_SetCaption("ShootEmUp", NULL); // titre de notre fenetre
    
    // on remplit la fenetre avec une couleur
    //SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
    //this->displayImage("Images/")
    this->loadBackground();
    

	for (list<DisplayObject*>::iterator it = displayObjectList.begin(); it != displayObjectList.end(); it++) {
			(*it)->display();
	}

    SDL_Flip(screen);

	// on deverouille et on rafraichit l'ecran
    //Graphics::unlock();

	//on attend le temps necessaire pour atteindre le taux de rafraichissement souhaite
	//Graphics::sync();
}
