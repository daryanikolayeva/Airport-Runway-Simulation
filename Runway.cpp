/////////////////////////
//.cpp of Runway class
///////////////////////////
#include "Runway.h"

/////////////////////////
//Constructor
//Originally runway is available
///////////////////////////
Runway::Runway() : isAvailable(true) {}

/////////////////////////
//Makes runway available
///////////////////////////
void Runway::setAvailable(bool available) {
    isAvailable = available;
}

/////////////////////////
//Returns if runway is available
///////////////////////////
bool Runway::getAvailable() const {
    return isAvailable;
}