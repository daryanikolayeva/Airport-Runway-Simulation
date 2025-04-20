
#include <iostream>
#include "Simulation.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Please input file name and number of runways" << endl;
        return 0;
    }

    string filename = argv[1];
    int numRunways = stoi(argv[2]);

    cout << "The filename is: " << filename << endl;
    cout << "The number of runways is: " << numRunways << endl;
    
     /////////////////////////////////////////////////////////////////////////////
    // Create the simulation with the specified number of runways and input file
    //////////////////////////////////////////////////////////////////////////////
    Simulation sim(numRunways, filename);

    /////////////////////////////////////////////////
    // Runs the simulation
    /////////////////////////////////////////////////
    sim.run();

    return 0;
}