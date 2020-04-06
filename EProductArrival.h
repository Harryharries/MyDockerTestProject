#ifndef INC_2150_EPRODUCTARRIVAL_H
#define INC_2150_EPRODUCTARRIVAL_H


#include "Event.h"
#include "PartiallyProduct.h"

class EProductArrival : public Event{
private:
    PartiallyProduct *product;
public:
    EProductArrival(PartiallyProduct *p, int t, Simulation *s);
    void processEvent();
};


#endif
