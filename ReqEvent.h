/////////////////////////
//ReqEvent.h
//Subclass of event
//Class for new reqeuested events
///////////////////////////
#pragma once
#include "Event.h"

class ReqEvent : public Event {
public:
    ReqEvent(const string& , Simulation& );
    ReqEvent(int , int, string, int , string, string, Simulation&, bool);
    void process(Simulation& ) override;
    bool isNewEvent();
    private:
    bool isNew;
};