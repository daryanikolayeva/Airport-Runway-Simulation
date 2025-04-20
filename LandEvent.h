/////////////////////////
//LandEvent.h
//Class that is subclass of Event
//Made to process events that are landing
///////////////////////////
#pragma once
#include "Event.h"

class LandEvent : public Event {
public:
    LandEvent(int t, int id, string cs, int fn, string sz, string rt);
    void process(Simulation& s) override;
};