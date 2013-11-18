#pragma once
#include "InputObject.h"
#include "DisplayObject.h"
#include "ComputeObject.h"
#include "SDL.h"

class EngineManager;

class Curseur : public InputObject, public DisplayObject, public ComputeObject
{
public:
    Curseur(EngineManager*);
    ~Curseur(void);

    void process(SDL_Event);
    virtual void compute();
    virtual void display();

    int getX();
    int getY();
    bool getPressSpaceBar();

protected:
    int positionX;
    int positionY;
    int pas; //le pas de deplacement du curseur en vertical
    EngineManager* engineManager;
    bool moveCursorLeft;
    bool moveCursorRight;
    bool moveCursorUp;
    bool moveCursorDown;
    bool pressEnter;
    bool pressSpaceBar;
    bool pressEscape;
    int ligneNum;
    SDL_Surface *image3;
    static int difficulty;
};

