#include "PartiallyProduct.h"

PartiallyProduct::PartiallyProduct(int p0, int p1, int quantity){
    this->p0 = p0;
    this->p1 = p1;
    this->quantity = quantity;
}

int PartiallyProduct::getP0() {return this->p0;}

int PartiallyProduct::getP1() {return this->p1;}

int PartiallyProduct::getQuan() {return this->quantity;}

PartiallyProduct::~PartiallyProduct(){}