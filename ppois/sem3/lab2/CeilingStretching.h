#pragma once
#include<iostream>
#include<sstream>
#include<vector>
#include"RepairService.h"
using namespace std;
/*!
    \brief Implementation of the class CeilingStretching
*/
class CeilingStretching : public RepairService
{
public:
    CeilingStretching(string, double, double);
    double getPrice() const override;

private:
    double pvcCost;
    double ceilingArea;
    void checkOptions() override;

};