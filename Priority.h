#pragma once
#include "OrderedItem.h"
class Node;

class Priority : public ListItem{
private:
    Node *front; // front of queue.
    Node *back; // back of queue
    int size; // size of queue.
public:
    Priority();
    int getSize(); // how many elements are in queue?
    bool isEmpty(); // is queue empty?
    void enqueue(ListItem *item); // add item to queue.
    ListItem *getFront(); // look at first item in queue.
    ListItem *dequeue(); // remove first item from queue.
    ~Priority();
}; // class PriorityQueue