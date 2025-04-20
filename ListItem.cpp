///////////////////////////
//ListeItem.cpp
//////////////////////////
#include "ListItem.h"
//////////////////////////
// Constructor
//////////////////////////
ListItem::ListItem(int t, int id, string cs, int fn, string sz, string rt)
    : time(t), atcID(id), callSign(cs), flightNumber(fn), size(sz), requestType(rt), wasteTime(0) {}

///////////////////
// Getter methods
//////////////////////
int ListItem::getTime() const { return time; }
int ListItem::getatcID() const { return atcID; }
string ListItem::getCallSign() const { return callSign; }
int ListItem::getFlightNum() const { return flightNumber; }
string ListItem::getSize() const { return size; }
string ListItem::getRequestType() const { return requestType; }
int ListItem::getWastedTime() const { return wasteTime; }

////////////////
// Setters
////////////////////////
void ListItem::setTime(int t) { time = t; }
void ListItem::setAtcID(int id) { atcID = id; }
void ListItem::setCallSign(const string& cs) { callSign = cs; }
void ListItem::setFlightNum(int fn) { flightNumber = fn; }
void ListItem::setSize(const string& sz) { size = sz; }
void ListItem::setRequestType(const string& rt) { requestType = rt; }

//////////////////////////
// Prints item details
//////////////////////////
void ListItem::printInfo() const {
    cout << "ATC ID: " << atcID
         << ", CallSign: " << callSign
         << ", FlightNum: " << flightNumber
         << ", Size: " << size
         << ", Request Type: " << requestType
         << ", Time: " << time << endl;
}
