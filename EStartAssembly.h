#pragma once
#include "Event.h"
#include <iostream>
using namespace std;

class EStartAssembly : public Event{
private:
    int eTime;
    int ma;
public:
    EStartAssembly(int m, int t, Simulation *s);
    void processEvent();
    void printS(int time, int m);
};