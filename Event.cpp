/////////////////////////////
//.cpp of event class
////////////////////////////
#include "Event.h"
//////////////////////////////////////////////////////////////////////
// Constructor creates event using parent class ListItem
////////////////////////////////////////////////////////////////////
Event::Event(int t, int id, string cs, int fn, string sz, string rt)
    : ListItem(t, id, cs, fn, sz, rt) {}
///////////////////////////////////////////////////
//Prints common information for events
/////////////////////////////////////////////////
void Event::printBaseInfo() const {
    cout << "TIME:" << time << "->" << callSign << flightNumber << "(" << atcID << ")" << size;
}
//////////////////////////////////////////////
// Calculates turbulence time based in size
///////////////////////////////////////////////
int Event::getTurbulenceTime() {
    if (getSize() == "small") return 0;
    if (getSize() == "large") return 1;
    if (getSize() == "heavy") return 2;
    if (getSize() == "super") return 3;
    return -1; // Invalid size
}
