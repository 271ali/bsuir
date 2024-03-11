
#pragma once
#include<iostream>
#include<sstream>
#include<vector>
#include"RepairService.h"
using namespace std;
/*!
    \brief Implementation of the class BatteryInstallation
*/
class BatteryInstallation :public RepairService
{
public:
    BatteryInstallation(string, int, double);
    double getPrice() const override;

private:
    int rooms;
    double cost;
    void checkOptions() override;

};