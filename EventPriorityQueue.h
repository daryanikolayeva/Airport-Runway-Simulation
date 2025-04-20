////////////////////////////
// EventPriorityQueue.h
////Priority queue of events
////////////////////////////
#pragma once
#include "GenericPriorityQueue.h"
#include "Event.h"

class EventPriorityQueue : public GenericPriorityQueue {
public:
    EventPriorityQueue() : GenericPriorityQueue() {}
    ~EventPriorityQueue() {}
    void push(ListItem* item) override;
    int getCurrentTime() override;
};
