#include "Parts.h"

Parts::Parts(int number, int time, int quantity): num(number), time(time){
    this->Quan = quantity;
}

int Parts::getPartNumber() {return this->num;}

int Parts::getPartTime() {return this->time;}

int Parts::getQuan() {return this->Quan;}

Parts::~Parts(){};