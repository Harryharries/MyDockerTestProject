#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Priority.h"
#include "Parts.h"
#include "EPartArrival.h"
#include "Simulation.h"

TEST_CASE( "enqueue Test","[Priority Queue]" ) {
    Priority* testPriorityQueue = new Priority();
    REQUIRE(testPriorityQueue->isEmpty());
    REQUIRE(testPriorityQueue->getFront() == nullptr);
    REQUIRE(testPriorityQueue->getSize() == 0);
    Simulation* sim = new Simulation();
    Parts* p = new Parts(0,0,1);
    EPartArrival* err = new EPartArrival(p,sim);
    testPriorityQueue->enqueue(err);

    REQUIRE(!testPriorityQueue->isEmpty());
    REQUIRE(testPriorityQueue->getSize() == 1);
    REQUIRE(testPriorityQueue->getFront() == err);
}

TEST_CASE( "multiple enqueue Test","[Priority Queue]" ) {
    Priority* testPriorityQueue = new Priority();
    REQUIRE(testPriorityQueue->isEmpty());
    REQUIRE(testPriorityQueue->getFront() == nullptr);
    REQUIRE(testPriorityQueue->getSize() == 0);
    EPartArrival* err1 = new EPartArrival(new Parts(0,0,1),new Simulation());
    testPriorityQueue->enqueue(err1);
    REQUIRE(!testPriorityQueue->isEmpty());
    REQUIRE(testPriorityQueue->getSize() == 1);
    REQUIRE(testPriorityQueue->getFront() == err1);

    EPartArrival* err2 = new EPartArrival(new Parts(0,0,1),new Simulation());
    testPriorityQueue->enqueue(err2);
    REQUIRE(testPriorityQueue->getSize() == 2);

    EPartArrival* err3 = new EPartArrival(new Parts(0,0,1),new Simulation());
    testPriorityQueue->enqueue(err3);
    REQUIRE(testPriorityQueue->getSize() == 3);
}

TEST_CASE( "test Priority Queue without any function", "[Priority Queue]" ) {
    Priority* testPriorityQueue = new Priority();
    REQUIRE(!testPriorityQueue->getFront());
    REQUIRE(testPriorityQueue->isEmpty());
    REQUIRE(testPriorityQueue->getSize() == 0);
    REQUIRE(testPriorityQueue->dequeue() == nullptr);
}

TEST_CASE( "dequeue Test","[Priority Queue]" ) {
    Priority* testPriorityQueue = new Priority();
    EPartArrival* er = new EPartArrival(new Parts(0,0,1),new Simulation());
    REQUIRE(testPriorityQueue->getSize() == 0);
    testPriorityQueue->enqueue(er);
    REQUIRE(testPriorityQueue->getSize() == 1);
    testPriorityQueue->dequeue();
    REQUIRE(testPriorityQueue->getSize() == 0);
    REQUIRE(testPriorityQueue->dequeue() == nullptr);
}

TEST_CASE( "Priority Test","[Priority Queue]" ) {
    Priority* testPriorityQueue = new Priority();

    EPartArrival* er1 = new EPartArrival(new Parts(0,100,1),new Simulation());
    EPartArrival* er2 = new EPartArrival(new Parts(0,0,1),new Simulation());
    EPartArrival* er3 = new EPartArrival(new Parts(0,2,1),new Simulation());

    REQUIRE(testPriorityQueue->getSize() == 0);
    testPriorityQueue->enqueue(er1);
    testPriorityQueue->enqueue(er2);
    testPriorityQueue->enqueue(er3);
    REQUIRE(testPriorityQueue->getSize() == 3);
    REQUIRE(testPriorityQueue->getFront() == er2);

}