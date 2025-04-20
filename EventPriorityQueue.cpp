////////////////////////////////
// EventPriorityQueue.cpp
////////////////////////////////
#include "EventPriorityQueue.h"
#include "Event.h"
////////////////////////////
/// pushes new ListItem item into eventPQ
//based on time, requestType, atcid
//We prioritize landing over take off, lower time, lower atcid if time is same
//////////////////////////////////
void EventPriorityQueue::push(ListItem* item) {
    Event* event = dynamic_cast<Event*>(item);  
    if (!event) return;
    Node* newNode = new Node(item);

    if (!head || event->getTime() < head->item->getTime() ||
        (event->getTime() == head->item->getTime() && event->getRequestType() == "landing" && head->item->getRequestType() != "landing") ||
        (event->getTime() == head->item->getTime() && event->getRequestType() == head->item->getRequestType() && event->getatcID() < head->item->getatcID())) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        while (current->next && 
               (current->next->item->getTime() < event->getTime() ||
                (current->next->item->getTime() == event->getTime() && current->next->item->getRequestType() == "landing" && event->getRequestType() != "landing") ||
                (current->next->item->getTime() == event->getTime() && current->next->item->getRequestType() == event->getRequestType() && current->next->item->getatcID() < event->getatcID()))) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    // cout << "///////////////////////////////" << endl;
    // cout << "Queue now: Event Priority" << endl;
    // print();
    // cout << "/////////////////////////////////////////" << endl;
}
/// ///////////////////////////////
///Returns current time
//We return time of event that is head of queue, since PQ is sorted by time
/////////////////////////////////////////////
int EventPriorityQueue::getCurrentTime(){
    if(head!=nullptr){
        return head->item->getTime();
    }
  else{
    return currentTime;
  }
}
