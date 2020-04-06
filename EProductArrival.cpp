#include "EProductArrival.h"
#include "Simulation.h"
#include "EStartAssembly.h"
#include <iostream>

EProductArrival::EProductArrival(PartiallyProduct *p, int t, Simulation *s):Event(t,s){
    this->product = p;
}

void EProductArrival::processEvent() {
    cout << "Event ProductArrival happened" <<endl;
    int ts = sim->getSimulationTime();
    cout << "time: " << ts << "\n"<< endl;
    sim->enProd(this->product);
    if(!sim->isFinishingBusy() && sim->finishingStationEmpty())
    {
        Event *news = new EStartAssembly(0, ts, sim);
        sim->enEvent(news);
    }
}
