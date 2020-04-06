#ifndef INC_2150_EPARTARRIVAL_H
#define INC_2150_EPARTARRIVAL_H


#include "Event.h"
#include "Parts.h"


class EPartArrival : public Event{
private:
    Parts *part;
public:
    EPartArrival(Parts *p, Simulation *s);
    void processEvent();
};


#endif
