////////////////////////////////////////////
//Plane class, extends ListItem
//has all the same parameters as event has
//Created to keep track of planes waiting when runways are not available
////////////////////////////////////////////
#include "Plane.h"

Plane::Plane(int t, int id, string cs, int fn, string sz, string rt)
    : ListItem(t, id, cs, fn, sz, rt), entryTime(-1) {} // -1 means not in the queue yet

/////////////////////////////////////////////
//Sets time when plane gets into waiting queue(PQPL)
////////////////////////////////////////////
void Plane::setEntryTime(int entryTime) {
    this->entryTime = entryTime;
}

/////////////////////////////////////////////
//Gets time when plane gets into waiting queue(PQPL)
////////////////////////////////////////////
int Plane::getEntryTime() const {
    return entryTime;
}