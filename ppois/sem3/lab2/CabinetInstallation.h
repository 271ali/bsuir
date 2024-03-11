#pragma once
#include<iostream>
#include<sstream>
#include<vector>
#include"DoorsInstallation.h"
using namespace std;
/*!
    \brief Implementation of the class Cabinet
*/
class Cabinet
{
public:
    Cabinet(double, double, double, int, DoorsInstallation);
    double length;
    double height;
    double width;
    int shelf;
    DoorsInstallation doorsInstallation;
};
/*!
    \brief Implementation of the class CabinetInstallation
*/
class CabinetInstallation :public RepairService
{
public:
    CabinetInstallation(string, double, vector<Cabinet>);
    double getPrice() const override;
private:
    void checkOptions() override;
    vector<Cabinet> cabinets;
    double materialCost;
};