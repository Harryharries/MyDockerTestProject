#include "Simulation.h"
#include "Queue.h"
#include "Priority.h"
#include "Parts.h"
#include "Event.h"
#include "EPartArrival.h"
#include "EEndAssembly.h"
#include "Simulation.h"
#include "PartiallyProduct.h"
#include "EProductArrival.h"
#include "EStartAssembly.h"

#include <iostream>

using namespace std;

Simulation::Simulation(){
    simulationTime = 0;
    mainAssemblyTime = 0;
    mainBusy = false;
    finishingBusy = false;
    productQueue = new Queue();
    eventList = new Priority();
    finishingAssemblyTime = 0;
    partNumber = 3;
    finalCost = 0;
    generatePartQ();
}

void Simulation::setMainStatus(bool sdd){ mainBusy = sdd;}
void Simulation::setTimeCounter(int time) { finalCost = finalCost + time; }
void Simulation::setFinishingStatus(bool r){finishingBusy = r;}

void Simulation::setfinalNum(){
    cout << "Product finish!!!\n" << endl;
    finalNum = finalNum +1;
}

void Simulation::setSimulationTime(int time){simulationTime = time;}

bool Simulation::isMainBusy(){return mainBusy;}

bool Simulation::isFinishingBusy(){return finishingBusy;}

void Simulation::enProd(ListItem *a) {productQueue->enqueue(a);}

void Simulation::enPart(Parts *pa) {partQueues[pa->getPartNumber()]->enqueue(pa);}

void Simulation::enEvent(Event *e) {eventList->enqueue(e);}

bool Simulation::mainStationEmpty() {return (!partQueues[0]->isEmpty())&&(!partQueues[1]->isEmpty());}
bool Simulation::finishingStationEmpty(){return (!partQueues[2]->isEmpty()) && (!productQueue->isEmpty());}
int Simulation::getP(int number){return dynamic_cast<Parts *>(partQueues[number]->getFront())->getPartTime();}

int Simulation::getMTime() {return mainAssemblyTime;}

int Simulation::getFTime() {return finishingAssemblyTime;}

int Simulation::getSimulationTime(){return simulationTime;}

void Simulation::generatePartQ(){
    partQueues = new Queue*[partNumber];
    for(int i = 0; i <= partNumber; i++)
        partQueues[i] = new Queue();
}

void Simulation::dequeuePLis(int num1, int num2) {
    partQueues[num1]->dequeue();
    partQueues[num2]->dequeue();
}

void Simulation::dequeuePrLis() {
    partQueues[2]->dequeue();
    productQueue->dequeue();
}

void Simulation::setfTime(int ts) {
    setFinishingStatus(false);
    setfinalNum();
    dequeuePrLis();
    setTimeCounter(ts);
}

void Simulation::setSATime(bool a){
    if(a){
        setMainStatus(true);
    }else{
        setFinishingStatus(true);
    }
}

void Simulation::setPAprocess(int ts, Parts* a){
    cout << "time: " << a->getPartTime() << " in P" << a->getPartNumber() << "\n"<< endl;
    getNextArrival();
    enPart(a);
}

void Simulation::setSProcess(int ts) {
    setMainStatus(false);
    PartiallyProduct* p = new PartiallyProduct(ts, getP(0), getP(1));
    Event *pArrival = new EProductArrival(p, ts, this);
    dequeuePLis(0,1);
    enEvent(pArrival);
    if(mainStationEmpty())
    {
        Event *news = new EStartAssembly(true, ts, this);
        enEvent(news);
    }
}

PartiallyProduct* Simulation::getTarget(){return dynamic_cast<PartiallyProduct*>(productQueue->getFront());}

void Simulation::getNextArrival(){
    int aTime;
    int pNum;
    ifile >> aTime >> pNum;
    if(pNum < partNumber) {
        Parts *tempPart = new Parts(pNum, aTime, 1);
        Event *partA = new EPartArrival(tempPart, this);
        enEvent(partA);
    }
}

void Simulation::runSimulation(char *fileName) {
    int mt,ft;
    ifile.open(fileName);
    if(ifile.is_open()){
        ifile >> mt >> ft;
        cout << "main time: " << mt << "     finish time" << ft << endl;
        mainAssemblyTime = mt;
        finishingAssemblyTime = ft;
        getNextArrival();
        while(!eventList->isEmpty())
        {
            Event* cd = dynamic_cast<Event*>(eventList->dequeue());
            setSimulationTime(cd->getTime() );
            cd->processEvent();
        }
    }
    ifile.close();
    stat();
}


void Simulation::stat() {
    cout << "___________________________________________________________" <<endl;
    int aveCost = finalCost / finalNum;
    cout << "everything complete!! " << finalNum << " items have been completely assembled\n" << endl;
    cout << "average time to completely build a product: " << aveCost << endl << endl;
    for(int i = 0; i<partNumber; i++){
        cout << "part left - " << " p" << i << ": " << partQueues[i]->getSize() << endl;
    }
    cout << "product left - Partially product: " << productQueue->getSize() << endl;
}