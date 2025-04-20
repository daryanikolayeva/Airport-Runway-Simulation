//////////////////////////////////
//.cpp of CompleteEvent class
//Takes care of completion of event
///////////////////////////////
#pragma once
#include "Event.h"
#include "PlanePQ.h"

class CompleteEvent : public Event {
public:
    int runwayNumber;

    CompleteEvent(int t, int id, string cs, int fn, string sz, string rt, int rn);
    void process(Simulation& s) override;
};