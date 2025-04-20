////////////////////////////////////////////
//.cpp file of TakeOffEvent
//Takes care of take off events
//////////////////////////////////////////
#include "TakeOffEvent.h"
#include "Simulation.h"
#include "CompleteEvent.h"
//////////////////////////
//Constructor based on parent event constructor
//////////////////////////
TakeOffEvent::TakeOffEvent(int t, int id, string cs, int fn, string sz, string rt)
    : Event(t, id, cs, fn, sz, rt) {}
    /// //////////////////////////////
    /// Checks if there is available runway
    //Marks it unavilable since we start take off now
    //If so calculates time needed to take off which 1 to prepare+ wakeTurbulence time
    //Schedules complete event for startTime+ time needed to complete event
    //Pushes that complete event onto Event priority queue
    /////////////////////////////////////////
    void TakeOffEvent::process(Simulation& s) {
        int runwayNumber = s.findAvailableRunway();
        if (runwayNumber != -1) {
            s.setRunwayAvailability(runwayNumber, false);
            int completionTime = 1 + getTurbulenceTime();
            int startTime = s.getCurrentTime();
            int totalTime = startTime + completionTime;
 int wastedTime=startTime-getTime();
            printBaseInfo();
        cout << " cleared for takeoff on runway " << runwayNumber+1 
             << ". (time req. for takeoff: " << completionTime+wastedTime<<")"<<endl;
            CompleteEvent* completeEvent = new CompleteEvent(totalTime, getatcID(), getCallSign(), getFlightNum(), getSize(), getRequestType(), runwayNumber);
            s.getEPQ().push(completeEvent);
        } 
    }
    
