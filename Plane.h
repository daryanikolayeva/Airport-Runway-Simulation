//////////////////////////////////
//.h file for Plane Class
//ListItem-parent class
/////////////////////////////////
#pragma once
#include "ListItem.h"

class Plane : public ListItem {
    public:
        Plane(int t, int id, string cs, int fn, string sz, string rt);
        void setEntryTime(int entryTime); 
        int getEntryTime() const; 
    
    private:
        int entryTime;
    };