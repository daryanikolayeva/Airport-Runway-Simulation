//////////////////////////////////////////
//Subclass of event
//Takes care of take off events
//.h file of TakeOffEvent.cpp
/////////////////////////////////////////
#pragma once
#include "Event.h"

class TakeOffEvent : public Event {
public:
    TakeOffEvent(int t, int id, string cs, int fn, string sz, string rt);
    void process(Simulation& s) override;
};