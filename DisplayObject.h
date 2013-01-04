#pragma once

class DisplayObject {

public:

	virtual ~DisplayObject(void);
	virtual void display() = 0;
	
};

inline DisplayObject::~DisplayObject() {};
