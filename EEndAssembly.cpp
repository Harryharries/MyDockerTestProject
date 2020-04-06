#include "EEndAssembly.h"
#include "Simulation.h"
#include "PartiallyProduct.h"
#include <iostream>

using namespace std;
EEndAssembly::EEndAssembly(int m, int theTime, Simulation *s): Event(theTime, s){
    this->main = m;
}

int EEndAssembly::getTimeSpend(PartiallyProduct* p) {
    int i;
    i = p->getP0();
    if(i > p->getP1())
        i = p->getP1();
    if(sim->getP(2) > i)
        i = sim->getP(2);
    return sim->getSimulationTime() - i;;
}

void EEndAssembly::printS(int time, int mA){
    if(mA){
        cout << "time: " << time << " StartAssemblyEvent: Main Station\n" << endl;
    }else{
        cout <<"time: " << time << " StartAssemblyEvent: Finishing Station" << endl;
    }
}

void EEndAssembly::processEvent() {
    cout << "Event EndAssembly happened" <<endl;
    int ts;
    int currentTime = sim->getSimulationTime();
    printS(currentTime,this->main);
    if(this->main){
        sim->setSProcess(currentTime);
    }else{
        ts = getTimeSpend(sim->getTarget());
        sim->setfTime(ts);
    }
}