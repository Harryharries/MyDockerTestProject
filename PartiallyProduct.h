#pragma once
#include "ListItem.h"

class PartiallyProduct : public ListItem{
private:
    int p0;
    int p1;
    int quantity;
public:
    PartiallyProduct(int p0, int p1, int quantity);
    int getP0();
    int getP1();
    int getQuan();
    ~PartiallyProduct();
};