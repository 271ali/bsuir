#pragma once
#include<iostream>
#include<sstream>
#include<vector>
#include"RepairService.h"

using namespace std; 
/*!
    \brief Implementation of the class TilesLaying
*/
class TilesLaying : public RepairService
{
public:
    TilesLaying(string, double, double, double);
    double getPrice() const override;

private:
    double tileArea;
    double area;
    double tileCost;
    void checkOptions() override;

};