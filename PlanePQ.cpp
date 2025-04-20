/////////////////////////
//PlanePQ.cpp
//Implementation file of queue where we store planes that are waiting for available runway
///////////////////////////
#include "PlanePQ.h"
#include "Plane.h"
#include <iostream>
using namespace std;
/////////////////////////////////
//Constructor, takes in simulation to access its methods and infromation
///////////////////////////////////
PlanePQ::PlanePQ(Simulation& sim) : simulation(sim) {}
/////////////////////////
//Push method
///Pushes item into priority queue
//Creates plane object from item passed in
//Sorts queue absed on first time, then landing over taking off, then atcID
///////////////////////////
void PlanePQ::push(ListItem* item) {
    Plane* plane = new Plane(item->getTime(),item->getatcID(), item->getCallSign(),item->getFlightNum(), item->getSize(), item->getRequestType());
    if (!plane){
        cout << "Error: Pushed item is not a Plane!" << endl;
        return;
    } 
    plane->setEntryTime(getCurrentTime());

    Node* newNode = new Node(plane);

    if (!head || plane->getTime() < head->item->getTime() ||
        (plane->getTime() == head->item->getTime() && plane->getRequestType() == "landing" && head->item->getRequestType() != "landing") ||
        (plane->getTime() == head->item->getTime() && plane->getRequestType() == head->item->getRequestType() && plane->getatcID() < head->item->getatcID())) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        while (current->next && 
               (current->next->item->getTime() < plane->getTime() ||
                (current->next->item->getTime() == plane->getTime() && current->next->item->getRequestType() == "landing" && plane->getRequestType() != "landing") ||
                (current->next->item->getTime() == plane->getTime() && current->next->item->getRequestType() == plane->getRequestType() && current->next->item->getatcID() < plane->getatcID()))) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    
}
/////////////////////////
//Returns simulation
///////////////////////////
Simulation& PlanePQ:: getSimulation(){
    return simulation;
}
/////////////////////////
//Pops item of the list
//Before popping, we update current time
//Since our pq is sorted by time, head item has current time
//Updates wasted time by time of leaving queue minus time when it got into queue
//Updates total waste time of simulation
//Deletes event
///////////////////////////
ListItem* PlanePQ::pop() {
    if (!head) return nullptr;
    currentTime = head->item->getTime();

    Node* temp = head;
    ListItem* item = head->item;
    head = head->next;
    
    Plane* plane = dynamic_cast<Plane*>(item);
    if (!plane) {
        cout << "Error: Popped item is not a Plane" << endl;
    } else if (plane->getEntryTime() != -1) {
        int waitingTime = getCurrentTime() - plane->getEntryTime();
        simulation.addTimeWaste(waitingTime);
    }

    delete temp;
    return item;
}
/////////////////////////
//Returns current time
///////////////////////////
int PlanePQ::getCurrentTime() {
    if(head!=nullptr){
        return head->item->getTime();
    }
  else{
    return currentTime;
  }
}
