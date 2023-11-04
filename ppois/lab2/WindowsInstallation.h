#pragma once
#include<iostream>
#include<sstream>
#include<vector>
#include"RepairService.h"
using namespace std; 
/*!
    \brief Implementation of the class WindowsInstallation
*/
class WindowsInstallation :virtual public RepairService
{
public:
    WindowsInstallation(string, int, int, int, double, double);
    double getPrice() const override;

protected:
    WindowsInstallation(string, int, double, double);
    int withMechanism;
    double windowCost;
    double mechanismCost;
private:
    int singleWindow;
    int dualWindow;
    void checkOptions() override;
};