/////////////////////////////////////
//.h file of Event
//Event is parent class to different events
// And is subclass to ListItem
///////////////////////////////////
#pragma once
#include "ListItem.h"
class Simulation;

class Event : public ListItem {
public:
    Event(int t, int id, string cs, int fn, string sz, string rt);
    virtual ~Event() = default;
    virtual void process(Simulation& s) = 0;
    void printBaseInfo() const;
    int getTurbulenceTime();
};
