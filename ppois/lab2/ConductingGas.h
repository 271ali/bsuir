#pragma once
#include<iostream>
#include<sstream>
#include<vector>
#include"RepairService.h"
/*!
    \brief Implementation of the class ConductingGas
*/
using namespace std; class ConductingGas :public RepairService
{
public:
    ConductingGas(string, int, double);
    double getPrice() const override;

private:
    int gasStove;
    double gasStoveCost;
    void checkOptions() override;

};


