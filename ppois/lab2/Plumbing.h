#pragma once
#include<iostream>
#include<sstream>
#include<vector>
#include"RepairService.h"
using namespace std; 
/*!
    \brief Implementation of the class Plumbing
*/
class Plumbing :public RepairService
{
public:
    Plumbing(string name, int tap, int toilet, double tapCost, double toiletCost);
    double getPrice() const override;
private:
    int tap;
    int toilet;
    double tapCost;
    double toiletCost;
    void checkOptions() override;

};
