/////////////////////
//Simulation.h class
////////////////////// 

#pragma once
#include "Event.h"
#include "Runway.h"
#include "EventPriorityQueue.h"
class PlanePQ;
#include <fstream>
#include <string>
using namespace std;

class Simulation {
private:
    Runway* runways;
    int numRunways; // Number of runways
    EventPriorityQueue epq;//Event priority queue(for multiple stages of event life, request, land, takeoff, complete)
    PlanePQ* plpq;//Planes priority queue(planes that are waiting because runways are unavailable)
    int ATCID;//unique atcID assigned to every plane
    int globalTime;
    int totalTimeWaste; 
    ifstream inputFile;

public:
    Simulation(int , const string& );
    ~Simulation();
    void run();
    int getATCID();
    void incrementATCID();
    Runway* getRunways();
    int getNumRunways() const;
    int findAvailableRunway() const;
    void setRunwayAvailability(int , bool );
    EventPriorityQueue& getEPQ();
    PlanePQ& getPLPQ();
    int getCurrentTime();
    void addTimeWaste(int ); 
    string readNextLine();
};