#include <iostream>
#include "SpaceShip.h"
#include "graphics.h"

using namespace std;

SpaceShip::SpaceShip(int X, int Y) {
	positionX = X;
	positionY = Y;
	cout << "SpaceShip created.\n";
}

SpaceShip::SpaceShip(void){
	positionX = WIDTH / 2;
	positionY = HEIGHT / 2;
}

SpaceShip::~SpaceShip(void){
}

void SpaceShip::move(int dx, int dy) {
	positionX += dx;
	positionX += dy;
}

void SpaceShip::display() {
	fill_triangle(positionX + 25 , positionY ,
			      positionX - 25 , positionY ,
				  positionX      , positionY - 100,
				  build_color(250, 250, 250));
}

int SpaceShip::getPositionX() {
	return positionX;
}

int SpaceShip::getPositionY() {
	return positionY;
}

void SpaceShip::setPositionX(int X) {
	positionX = X;
}

void SpaceShip::setPositionY(int Y) {
	positionY = Y;
}


