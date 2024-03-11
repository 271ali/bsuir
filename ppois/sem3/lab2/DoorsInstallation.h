#pragma once
#include<iostream>
#include<sstream>
#include<vector>
#include"RepairService.h"
using namespace std; 
/*!
    \brief Implementation of the class DoorsInstallation
*/
class DoorsInstallation :virtual public RepairService
{
public:
    DoorsInstallation(string, int, int, double);
    double getPrice() const override;
    void checkOptions() override;

protected:
    int singleDoor;
    int dualDoor;
    double doorCost;

};