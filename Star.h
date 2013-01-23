#pragma once
#include "DisplayObject.h"
#include "ComputeObject.h"

#include "boost/random.hpp"
#include "boost/generator_iterator.hpp"

class EngineManager;

class Star : public DisplayObject, public ComputeObject
{
	int positionX, positionY, size; //size = rayon de letoile
	EngineManager* engineManager;
	boost::random::mt19937 random;
    boost::random::uniform_int_distribution<> generatorSize1;
	boost::random::uniform_int_distribution<> generatorSize2;
	int starType;
public:
	//Constructeurs
	Star(void);
	Star(EngineManager*);
	Star(int X, int Y);
	Star(EngineManager*, int, int);
	
	//Destructeur
	~Star(void);

	//Methodes
	void move(int dx, int dy);
	void display();
	void compute();

	int getPositionX();
	int getPositionY();

	void setPositionX(int X);
	void setPositionY(int Y);
};