#pragma once
#include "ListItem.h"

class Parts: public ListItem{
private:
    int num;
    int time;
    int Quan;
public:
    Parts(int number, int time, int quantity);
    int getPartTime();
    int getPartNumber();
    int getQuan();
    ~Parts();
};