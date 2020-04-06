#include "Event.h"

Event::Event(int theTime, Simulation *theSim) :eventTime(theTime), sim (theSim) {}
Event::~Event() {}
int Event::getTime(){ return eventTime; }

int Event::compareTo(OrderedItem *other){
    Event *t = dynamic_cast<Event *>(other);
    return (this->eventTime - t->eventTime); // you must implement this.
}// compareTo