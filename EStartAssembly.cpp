#include "EStartAssembly.h"

#include "Simulation.h"
#include "EEndAssembly.h"
#include <iostream>

using namespace std;

EStartAssembly::EStartAssembly(int m, int t, Simulation *s) : Event(t, s){
    this->ma = m;
    if(this->ma){
        eTime = sim->getMTime();
    }else{
        eTime = sim->getFTime();
    }
}

void EStartAssembly::printS(int time, int m){
    if(m){
            cout << "time: " << time << " in Main Station\n" << endl;
    }else{
            cout << "time: " << time << " in Finishing Station\n" << endl;
    }
}

void EStartAssembly::processEvent() {
    cout << "Event StartAssembly happened" <<endl;
    int ts = sim->getSimulationTime();
    int n = ts + eTime;
    printS(ts, this->ma);
    sim->setSATime(ma);
    sim->enEvent(new EEndAssembly(this->ma, n, sim));
}