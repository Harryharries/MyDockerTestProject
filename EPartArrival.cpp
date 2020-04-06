#include "EPartArrival.h"
#include "Simulation.h"
#include "EStartAssembly.h"
#include <iostream>

using namespace std;

EPartArrival::EPartArrival(Parts *p, Simulation *s) : Event(p->getPartTime(),s){
    this->part = p;
}

void EPartArrival::processEvent(){
    cout << "Event PartArrival happened" <<endl;
    int ts = sim->getSimulationTime();
    sim->setPAprocess(ts,part);
    if(!sim->isMainBusy()&& sim->mainStationEmpty()){
        Event *start = new EStartAssembly(true, ts, sim);
        sim->enEvent(start);
    }
}