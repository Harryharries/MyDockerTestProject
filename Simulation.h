#pragma once
#include <fstream>
#include "Parts.h"
#include "PartiallyProduct.h"

using namespace std;

class Priority; // Priority Queue
class Queue; // Queue class - provided to you
class Event; // Event - given to you.

class Simulation {
private:
    int partNumber;
    int finalNum;
    int finalCost;
    ifstream ifile; // input file to read.
    int simulationTime; // what is the current time of the simulation?
    Priority *eventList; // priority queue of Events.
    Queue* productQueue; // queue of partially assembled products (for finishing station).
    Queue** partQueues; // *array* of queues of parts for the stations.
    int  mainAssemblyTime; //  how long does the main station take?
    int  finishingAssemblyTime; //  how long does the main station take?
    bool mainBusy; // is the main station busy?
    bool finishingBusy; // is the finishing station busy?


public:
    Simulation();
    // you need methods to manipulate product and part queues.
    // [add them here.]

    void generatePartQ();
    void setfTime(int ts);
    void setSProcess(int ts);
    PartiallyProduct* getTarget();
    void setPAprocess(int ts, Parts* a);
    void setSATime(bool);
    void dequeuePLis(int num1,int num2);
    void dequeuePrLis();
    void enProd(ListItem *a);
    void setTimeCounter(int time);
    void enPart(Parts *pa);
    void setfinalNum();
    int getMTime();
    int getFTime();
    int getP(int number);
    int getSimulationTime();
    void setSimulationTime(int time);
    void stat();

    // main method for driving the simulation
    void runSimulation(char *fileName);

    // add an event to event queue.
    void enEvent (Event *e);

    // read next arrival from file and add it to the event queue.
    void getNextArrival();

    // getters and setters for station statuses.
    bool isMainBusy();
    bool mainStationEmpty();
    bool finishingStationEmpty();
    bool isFinishingBusy();
    void setMainStatus(bool);
    void setFinishingStatus(bool);
};// class Simulation