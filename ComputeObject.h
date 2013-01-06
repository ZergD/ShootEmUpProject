#pragma once

class ComputeObject {
public:

	virtual ~ComputeObject(void);
	virtual void compute() = 0;

};

inline ComputeObject::~ComputeObject() {};

