//////////////////////////
// PlanePQ.h
//Priority queue for planes that are waiting for available runway
///////////////////////
#pragma once
#include "GenericPriorityQueue.h"
#include "Plane.h"
#include "Simulation.h"

class PlanePQ : public GenericPriorityQueue {
    public:
        PlanePQ(Simulation& );
        void push(ListItem* ) override;
        ListItem* pop() override; 
        int getCurrentTime() override;
        Simulation& getSimulation();
        private:
        Simulation& simulation;
    };
