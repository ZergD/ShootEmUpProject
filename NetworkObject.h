#pragma once

#include <string>

class NetworkObject {

public:

	virtual ~NetworkObject(void);
	virtual void display() = 0;

	virtual std::string getId() = 0;
	
};

inline NetworkObject::~NetworkObject() {};
