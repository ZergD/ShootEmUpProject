#include "GraphicEngine.h"
#include "EngineManager.h"
#include "Image.h"

GraphicEngine::GraphicEngine(EngineManager* EngineManagerP) {
	engineManager = EngineManagerP;
    backgroundFirstIteration = true;
    width = 920; height = 640;
    SDL_Init(SDL_INIT_VIDEO);
	screen = SDL_SetVideoMode(width, height, 32, SDL_HWSURFACE);

    int flags = IMG_INIT_JPG|IMG_INIT_PNG;
    int initted = IMG_Init(flags);
    if((initted&flags) != flags){
        cout << "error failed to init required jpg and pnj support\n";
    }
    background = IMG_Load("Images/nebula_top3.png");
    if(!background){
        cout << "IMG_Load: " << IMG_GetError() << "\n";
    }
}

GraphicEngine::~GraphicEngine(void) {
    delete img;
    SDL_FreeSurface(background);
    SDL_FreeSurface(screen);
}

void GraphicEngine::displayImage(SDL_Surface* image, int x, int y) {
    SDL_Rect position;

    position.x = x;
    position.y = y;
    if (SDL_BlitSurface(image, NULL, screen, &position) == -1 ){
        cout<<"Couldnt do background blitting InsideDisplay " << endl;
    }
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
    if((initted&flags) != flags){
        cout << "error failed to init required jpg and pnj support\n";
    }
    background = IMG_Load("Images/Background.jpg");
    if(!background){
        cout << "IMG_Load: " << IMG_GetError() << "\n";
    }
    if (SDL_BlitSurface(background,NULL,screen,NULL) == -1 ){
        cout<<"Couldnt do background blittingInsideLoad " << endl;
    }
}

void GraphicEngine::process() {
    SDL_WM_SetCaption("ShootEmUp", NULL); // titre de notre fenetre
    
    // on remplit la fenetre avec couleur noir
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));

    if(backgroundFirstIteration){ // on affiche le fond juste une fois
        img = new Image(engineManager, background);
        backgroundFirstIteration = false;
    }

	for (list<DisplayObject*>::iterator it = displayObjectList.begin(); it != displayObjectList.end(); it++) {
			(*it)->display();
	}

    SDL_Flip(screen);
}

int GraphicEngine::getHeight(){
	return height;
}

int GraphicEngine::getWidth(){
	return width;
}