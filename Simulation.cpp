//////////////////////////////////////////////////
//Simulation.cpp file
//Runs event-driven simulation based on given input
//////////////////////////////////////////////////////

#include "Simulation.h"
#include "ReqEvent.h"
#include "PlanePQ.h"

///////////////////////////////////////////////////////
//Constructor based on file name and numebr of runways
//If file is not found gives error and exits
/////////////////////////////////////////////////
Simulation::Simulation(int numRunways, const string& fileName)
    : ATCID(1), globalTime(0), numRunways(numRunways), totalTimeWaste(0) {
    runways = new Runway[numRunways];
    plpq = new PlanePQ(*this);
    inputFile.open(fileName);
    if (!inputFile.is_open()) {
        cout << "File not found" << endl;
        exit(1);
    }
}

////////////////////////////////
//Destructor, makes sure file is closed
////////////////////////////////////
Simulation::~Simulation() {
    delete[] runways;
    if (inputFile.is_open()) {
        inputFile.close(); 
    }
}

/////////////////////////////////////////
//starts simulation by reading first line
//Since it's start, creates ReqEvent, and pushes to EPQ since it's available at begining
///////////////////////////////////////
void Simulation::run() {
    // Read the first line and create the first ReqEvent
    string line = readNextLine();
    if (!line.empty()) {
        ReqEvent* reqEvent = new ReqEvent(line, *this);
        epq.push(reqEvent);
    }

    ///////////////////////////////////////////
    // deletes event that have been processed
    //////////////////////////////////////////
    while (!epq.empty()) {
        Event* event = (Event*)epq.pop();
        event->process(*this);
        delete event; 
    }

/////////////////////////////////////////////
// Print simulation summary
//////////////////////////////////////////////
    cout << "#######################" << endl;
    cout << "The simulation has ended." << endl;
    cout << "The number of runways was " << numRunways << "." << endl;
    cout << "The total amount of time waste was " <<  totalTimeWaste  << "minutes" << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
///Helper function that reads only one line
//Needed for ReqEvent class since it's the class that is supposed to read next line when processed
//And since simulation has access to file, and ReqEvent doesnt, this function is access to file reading
////////////////////////////////////////////////////////////////////////////////////////////////////////
string Simulation::readNextLine() {
    string line;
    if (getline(inputFile, line)) {
        return line;
    }
    return ""; 
}

/////////////////////////////////////////
/// Return atcID assigned to event/plane
////////////////////////////////////////
int Simulation::getATCID() {
    return ATCID;
}
///////////////////////////////////////////////////////////////////////
//Each event/plane is one atcID higher, atcID is global in simulation, 
//however it increments when event gets into ReqEvent, so its helper method
//////////////////////////////////////////////////////////////////////////////
void Simulation::incrementATCID() {
    ATCID++;
}

////////////////////////////////////
///Gives access to runway array
///////////////////////////////////
Runway* Simulation::getRunways() {
    return runways;
}

//////////////////////////////////
//Returns number of runways(total, not available or unavailable)
/////////////////////////////////
int Simulation::getNumRunways() const {
    return numRunways;
}

//////////////////////////////////////////////////
//Goes through runways array to find available one
//If all are unavailable returns -1
//////////////////////////////////////////////////
int Simulation::findAvailableRunway() const {
    for (int i = 0; i < numRunways; i++) {
        if (runways[i].getAvailable()) {
            return i; 
        }
    }
    return -1; 
}

/////////////////////////////////////////////////////////////
//Sets specific runway to either available or unavailable
/////////////////////////////////////////////////////////////
void Simulation::setRunwayAvailability(int runwayNumber, bool available) {
    if (runwayNumber >= 0 && runwayNumber < numRunways) {
        runways[runwayNumber].setAvailable(available);
    }
}

/////////////////////////////////////
//gives access to Event priority queue
////////////////////// //////////////
EventPriorityQueue& Simulation::getEPQ() {
    return epq;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//Gives access to plane priority queue( waiting queue of planes for when runways are unavailable)
/////////////////////////////////////////////////////////////////////////////////////////////////
PlanePQ& Simulation::getPLPQ() {
    return *plpq;
}

/////////////////////
//Returns current time
////////////////////// 
int Simulation::getCurrentTime() {
    return epq.getCurrentTime();
}

/////////////////////
//Updates wasted time by given time
////////////////////// 
void Simulation::addTimeWaste(int waste) {
    totalTimeWaste += waste;
    /////////////////////////
//
///////////////////////////
}
