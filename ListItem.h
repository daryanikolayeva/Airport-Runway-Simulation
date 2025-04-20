/////////////////////////
//Parent class of event and plane
//ListItem.h
///////////////////////////
#pragma once
#include <string>
#include <iostream>
using namespace std;

class ListItem {
protected:
    int time;
    int atcID;
    string callSign;
    int flightNumber;
    string size;
    string requestType;
    int wasteTime;

public:
    ListItem(int t, int id, string cs, int fn, string sz, string rt);
    virtual ~ListItem() = default;
    int getTime() const;
    int getatcID() const;
    string getCallSign() const;
    int getFlightNum() const;
    string getSize() const;
    string getRequestType() const;
    int getWastedTime() const;
    void setTime(int t);
    void setAtcID(int id);
    void setCallSign(const string& cs);
    void setFlightNum(int fn);
    void setSize(const string& sz);
    void setRequestType(const string& rt);
    virtual void printInfo() const;
};
