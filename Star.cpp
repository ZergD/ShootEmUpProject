#include <iostream>

#include "Star.h"
#include "EngineManager.h"
#include "time.h"

Star::Star(int X, int Y) {
	positionX = X;
	positionY = Y;
	//std::cout << "Star created.\n";
}

Star::Star(void){
	positionX = engineManager->GetGraphicEngine()->getWidth() / 2;
	positionY = engineManager->GetGraphicEngine()->getHeight() / 2;
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
	random = *new boost::random::mt19937(time(0));
	generatorSize1 = *new boost::random::uniform_int_distribution<>(0, 11);
	generatorSize2 = *new boost::random::uniform_int_distribution<>(0, 5);

	size = X % 12;
	lifespan = X % 50;
	//std::cout << "my lifespan is: " << lifespan << "\n";
	//we use the star s positionX (that was generated randomly) % 12 to decide the starType
	if(size < 5) {
		starType = 0;
	}
	else {
		starType = 1;
	}

	positionX = X;
	positionY = Y;
	engineManager->GetGraphicEngine()->addObject(this);
	engineManager->GetStateEngine()->addComputeObject(this);
	engineManager->GetParticleEngine()->addStar(this);
}

Star::~Star(void){

	engineManager->GetStateEngine()->removeComputeObject(this);
	engineManager->GetParticleEngine()->removeStar(this);
	engineManager->GetGraphicEngine()->removeObject(this);
}

void Star::move(int dx, int dy) {
	if((positionX + dx + 25) < engineManager->GetGraphicEngine()->getWidth() || (positionX + dx - 25) > 0) {
		positionX;
	}
	else if((positionY + dy) < engineManager->GetGraphicEngine()->getHeight() || (positionY + dy - 100) > 0) {
		positionY;
	}
	else {
		positionX += dx;
		positionY += dy;
	}
}

void Star::display() {
	//PositionY, positionX = milieu de l etoile
	//Graphics::draw_line(positionX - size, positionY, positionX + size, positionY, Graphics::build_color(250,250,250)); //ligne horizontale
	//Graphics::draw_line(positionX, positionY - size, positionX, positionY + size, Graphics::build_color(250,250,250)); //ligne verticale
}

void Star::compute() {
	int vitesse;

	//twinkling
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

	lifespan--;
	liveOrDie();
}


int Star::getPositionX() {
	return positionX;
}

int Star::getPositionY() {
	return positionY;
}

void Star::setPositionX(int vitesse) {
	if((positionX + vitesse + 25) > engineManager->GetGraphicEngine()->getWidth() || (positionX + vitesse - 25) < 0) {

	}
	else {
		positionX += vitesse;
	}
}

void Star::setPositionY(int vitesse) {
	if(positionY > engineManager->GetGraphicEngine()->getHeight())  {
		//delete(this);
	}
	else {
		positionY += vitesse;
	}
}

void Star::liveOrDie() {
	if(positionY > engineManager->GetGraphicEngine()->getHeight() || lifespan <= 0) {
		delete(this);
	}
}


