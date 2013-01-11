#pragma once

class ControlObject {

public:

	virtual ~ControlObject(void);
	virtual void control() = 0;
	
};

inline ControlObject::~ControlObject() {};
