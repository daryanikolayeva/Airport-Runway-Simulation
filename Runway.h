/////////////////////////
//Runway.h
//Class for tracking availability of runway
///////////////////////////
#pragma once
class Runway {
public:
    bool isAvailable;

    Runway();
    void setAvailable(bool );
    bool getAvailable() const;
};