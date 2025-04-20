/////////////////////////
//ReqEvent.cpp
//implementation file of request events class
///////////////////////////
#include "ReqEvent.h"
#include "Simulation.h"
#include "LandEvent.h"
#include "TakeOffEvent.h"
#include "PlanePQ.h"
#include <sstream>
/////////////////////////////////////
// Constructor for parsing input lines
//Takes input parameters from line that is passed as input
//Sets values to this parameters from input line
//Assigns atcID
//increases atcID(globally in simulation) for next plane created will have one higher
///////////////////////////////////////
ReqEvent::ReqEvent(const string& line, Simulation& sim) 
    : Event(0, 0, "", 0, "", "") { 
    stringstream sst(line); 
    string token;
    int time = 0;
    string callSign = "";
    string flightNum = "";
    string size = "";
    string requestType = "";
    sst >> token; 
    time = stoi(token);
    sst >> callSign; 
    sst >> flightNum;
    sst >> size; 
    sst >> requestType;
    setTime(time);
    setCallSign(callSign);
    setFlightNum(stoi(flightNum));
    setSize(size);
    setRequestType(requestType);
    setAtcID(sim.getATCID());
    sim.incrementATCID();
}
/////////////////////////////////////////////////////////////
// Constructor for creating ReqEvent directly from parameters
/////////////////////////////////////////////////////////////
ReqEvent::ReqEvent(int t, int id, string cs, int fn, string sz, string rt, Simulation& sim, bool isNew)
    : Event(t, id, cs, fn, sz, rt), isNew(isNew) {
    if(isNew){
        setAtcID(sim.getATCID());
        sim.incrementATCID();
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Processes event
//Checks if there're available runways
//If yes, depeding on type of event creates either landing or takeoff and pushes them on to Event priority queue(main queue for processing)
//If not, pushes events to PQPL which is planePq which stores planes that are waiting for available runway
//In the end takes new line from file read, and processes it
//Every time reqevent is going to be called, it will make next line from file to be read
//Since file is read in simulation, same as runways comtrol and others, we pass simulation as input to have access to all that functionality
////////////////////////////////////////////////////////////////////////////////////////////////
void ReqEvent::process(Simulation& s) {
    int runwayNumber = s.findAvailableRunway();
    if (runwayNumber == -1) {
        if (getRequestType() == "landing") {
            LandEvent* landEvent = new LandEvent(getTime(), getatcID(), getCallSign(), getFlightNum(), getSize(), getRequestType());
            s.getPLPQ().push(landEvent);
        } else if (getRequestType() == "takeoff") {
            TakeOffEvent* takeOffEvent = new TakeOffEvent(getTime(), getatcID(), getCallSign(), getFlightNum(), getSize(), getRequestType());
            s.getPLPQ().push(takeOffEvent); 
        }
    } else {
        if (getRequestType() == "landing") {
            printBaseInfo();
            cout << " " << "inbound for landing" << "." << endl;
            LandEvent* landEvent = new LandEvent(getTime(), getatcID(), getCallSign(), getFlightNum(), getSize(), getRequestType());
            s.getEPQ().push(landEvent); 
        } else if (getRequestType() == "takeoff") {
            printBaseInfo();
            cout << " " << "ready for takeoff" << "." << endl;
            TakeOffEvent* takeOffEvent = new TakeOffEvent(getTime(), getatcID(), getCallSign(), getFlightNum(), getSize(), getRequestType());
            s.getEPQ().push(takeOffEvent); 
        }
    }

    string nextLine = s.readNextLine();
    if (!nextLine.empty()) {
        ReqEvent* nextReqEvent = new ReqEvent(nextLine, s);
        s.getEPQ().push(nextReqEvent);
    }
}