//////////////////////////////////
//.cpp of CompleteEvent class
///////////////////////////////
#include "CompleteEvent.h"
#include "Simulation.h"
#include "ReqEvent.h"
#include "PlanePQ.h"
////////////////////////////////////////////////
//Constructor based on parent event constructor
/////////////////////////////////////////////////
CompleteEvent::CompleteEvent(int t, int id, string cs, int fn, string sz, string rt, int rn)
    : Event(t, id, cs, fn, sz, rt), runwayNumber(rn) {}
/////////////////////////////////////
///When complete event happes, it means event happened and wake turbulence clearead, so we mark runway as available now
//We check if there are any planes waiting for runway(getPQPL().empty)
//Since PQPL consist of planes, not event, we create new Request event from plane that we pop from that queue, place it to EPQ
//If there're, we process them
//If notwe then check event PQ, and procccess events from there
////////////////////////////////////////////
void CompleteEvent::process(Simulation& s) {
    s.setRunwayAvailability(runwayNumber, true);
    printBaseInfo();
    cout << " has cleared the runway " << runwayNumber+1 << "." << endl;
    if (!s.getPLPQ().empty()) {
        ListItem* item = s.getPLPQ().pop();
        Plane* nextPlane = dynamic_cast<Plane*>(item);
        if (nextPlane) {
            ReqEvent* newReqEvent = new ReqEvent(s.getEPQ().getCurrentTime(),nextPlane->getatcID(),nextPlane->getCallSign(), nextPlane->getFlightNum(), nextPlane->getSize(),nextPlane->getRequestType(),s, false);                         

           s.getEPQ().push(newReqEvent);
        } 
        delete item;
    }
    if (!s.getEPQ().empty()) {
        ListItem* item = s.getEPQ().pop();
        Event* nextEvent = dynamic_cast<Event*>(item);
        if (nextEvent) {
            nextEvent->process(s);
        } 
        delete item;
    }
}
