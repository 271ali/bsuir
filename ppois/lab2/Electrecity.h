#pragma once
#include<iostream>
#include<sstream>
#include<vector>
#include"RepairService.h"
using namespace std;
/*!
    \brief Implementation of the class Electrecity
*/
class Electrecity :public RepairService
{
public:
    Electrecity(string, int, int, double, double);
    double getPrice() const override;

private:
    int lamp;
    int socket;
    double lampCost;
    double socketCost;
    void checkOptions() override;

};