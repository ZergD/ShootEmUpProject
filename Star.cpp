#include <iostream>

#include "Star.h"
#include "graphics.h"
#include "EngineManager.h"

using namespace std;

Star::Star(int X, int Y) {
	positionX = X;
	positionY = Y;
	cout << "Star created.\n";
}

Star::Star(void){
	positionX = WIDTH / 2;
	positionY = HEIGHT / 2;
}

Star::Star(EngineManager* engineManagerP) {	
	engineManager = engineManagerP;
	//positionY = -(rand() % HEIGHT + 1);
	positionY = 1;
	size = 10;
	engineManager->GetGraphicEngine()->addObject(this);
	engineManager->GetStateEngine()->addComputeObject(this);
}

Star::Star(EngineManager* engineManagerP, int X, int Y) {
	engineManager = engineManagerP;
	random = *new boost::random::mt19937(std::time(0));
	generatorSize1 = *new boost::random::uniform_int_distribution<>(0, 11);
	generatorSize2 = *new boost::random::uniform_int_distribution<>(0, 5);
	
    starType = generatorSize1(random); 
	//size = starType;
	if(starType < 5) {
		starType = 0;
		size = starType;
	}
	else {
		starType = 1;
		size = generatorSize2(random);
	}

	positionX = X;
	positionY = Y;
	engineManager->GetGraphicEngine()->addObject(this);
	engineManager->GetStateEngine()->addComputeObject(this);
	engineManager->GetParticleEngine()->addStar(this);
}

Star::~Star(void){
	engineManager->GetParticleEngine()->removeStar(this);
	engineManager->GetStateEngine()->removeComputeObject(this);
	engineManager->GetGraphicEngine()->removeObject(this);
}

void Star::move(int dx, int dy) {
	if((positionX + dx + 25) < WIDTH || (positionX + dx - 25) > 0) {
		positionX;
	}
	else if((positionY + dy) < HEIGHT || (positionY + dy - 100) > 0) {
		positionY;
	}
	else {
		positionX += dx;
		positionY += dy;
	}
}

void Star::display() {
	//Position Y, positionX = milieu de l etoile
	Graphics::draw_line(positionX - size, positionY, positionX + size, positionY, Graphics::build_color(250,250,250)); //ligne horizontale
	Graphics::draw_line(positionX, positionY - size, positionX, positionY + size, Graphics::build_color(250,250,250)); //ligne verticale
}

void Star::compute() {
	int vitesse;

	//flickering
	if(starType == 0) { //cas ou l etoile est grande
		size = generatorSize1(random);
		vitesse = 2;
		this->setPositionY(vitesse);
	} 
	else { //cas ou l etoile est petite
		size = generatorSize2(random);
		vitesse = 1;
		this->setPositionY(vitesse);
	}
}


int Star::getPositionX() {
	return positionX;
}

int Star::getPositionY() {
	return positionY;
}

void Star::setPositionX(int vitesse) {
	if((positionX + vitesse + 25) > WIDTH || (positionX + vitesse - 25) < 0) {
	
	}
	else {
		positionX += vitesse;
	}
} 

void Star::setPositionY(int vitesse) {
	if(positionY > HEIGHT)  {
		delete(this);
	}
	else {
		positionY += vitesse;
	}
}


