///////////////////////////////////////
//.cpp of GenericPriorityQueue
/////////////////////////////////////
#include "GenericPriorityQueue.h"
#include <iostream>
using namespace std;
////////////////////////////////////////
//null constructor
/////////////////////////////////////////
GenericPriorityQueue::GenericPriorityQueue() : head(nullptr), currentTime(0) {}

////////////////////////////////////
//Destructor. Pops Nodes one by one
//////////////////////////////////////////////
GenericPriorityQueue::~GenericPriorityQueue() {
    while (!empty()) {
        delete pop();
    }
}
/////////////////////////////
/// Pops top items
///////////////////////////////////////
ListItem* GenericPriorityQueue::pop() {
    if (empty()) return nullptr;

    Node* temp = head;
    currentTime = head->item->getTime();
    ListItem* item = head->item;
    head = head->next;
    delete temp;
    return item;
}
/////////////////////////////
///Returns if queue is empty
//////////////////////////////
bool GenericPriorityQueue::empty() const {
    return head == nullptr;
}
///////////////////////////////////
//Prints contents of pq
///////////////////////////////////
void GenericPriorityQueue::print() const {
    if (empty()) {
        cout << "The priority queue is empty." << endl;
        return;
    }
    Node* current = head;
    while (current) {
        current->item->printInfo();
        cout << endl;
        current = current->next;
    }
}
