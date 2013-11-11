#pragma once
class State
{
public:
    virtual ~State();
    virtual void start() = 0;
    virtual void stop() = 0;
};
inline State::~State() {};

