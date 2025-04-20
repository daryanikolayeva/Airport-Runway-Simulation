////////////////////////////
//Generic Priority Queue
//Parent class to EventPQ and PlanePQ
/////////////////////////////
#pragma once
#include "ListItem.h"  
using namespace std;

class GenericPriorityQueue {
protected:
    struct Node {
        ListItem* item;
        Node* next;
        Node(ListItem* i) : item(i), next(nullptr) {}
    };

    Node* head; 
    int currentTime;

public:
    GenericPriorityQueue();
    virtual ~GenericPriorityQueue();
    virtual void push(ListItem* item) = 0;
    virtual ListItem* pop();
    bool empty() const;
    virtual int getCurrentTime()=0;
    void print() const;
};

