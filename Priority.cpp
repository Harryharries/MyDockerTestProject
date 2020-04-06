#include "Priority.h"
#include "Node.h"
#include "Event.h"

Priority::Priority() :front(nullptr), back(nullptr), size(0) {}
int Priority::getSize(){ return size; }
bool Priority::isEmpty(){ return size == 0; }


// add item to front of queue.
void Priority::enqueue(ListItem *item) {
    if (front == nullptr) {
        front = new Node(item, nullptr);
    } else {
        Node *currN = front;
        Node *prevN = nullptr;
        Event *currI = dynamic_cast<Event *> (currN->getItem());

        Node *newN = new Node(item, nullptr);
        Event *newI = dynamic_cast<Event *> (item);
        while (currN != nullptr && currI->compareTo(newI) < 0) {
            prevN = currN;
            currN = currN->getNext();
            if (currN)
                currI = dynamic_cast<Event *> (currN->getItem());
        }
        if (!prevN)
            newN->setNext(front);
        else
            newN->setNext(currN);

        if (prevN == nullptr) {
            front = newN;
        } else {
            prevN->setNext(newN);
        }
    }
    size++;
}

// remove front item from Queue.
ListItem *Priority::dequeue(){
    ListItem *theItem = nullptr;
    Node *theNode = front;
    if(front != nullptr){
        theItem = front->getItem();
        // special case: removing last item
        if(front == back){
            front = back = nullptr;
        } else {
            front = front->getNext();
        }
        size--;
        delete(theNode);
    }
    return theItem;
}// dequeue


// look at first item in queue without removing.
ListItem *Priority::getFront(){
    ListItem *theItem = nullptr;
    if(front != nullptr){
        theItem = front->getItem();
    }
    return theItem;
}// getFront


// destructor
Priority::~Priority() {}