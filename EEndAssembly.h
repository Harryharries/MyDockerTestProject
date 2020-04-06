#ifndef INC_2150_EENDASSEMBLY_H
#define INC_2150_EENDASSEMBLY_H

#include "PartiallyProduct.h"
#include "Event.h"

class EEndAssembly : public Event{
private:
    bool main;
public:
    EEndAssembly(int m, int theTime, Simulation *s);
    void processEvent();
    int getTimeSpend(PartiallyProduct* p);
    void printS(int time, int mA);
};


#endif //INC_2150_EENDASSEMBLY_H
