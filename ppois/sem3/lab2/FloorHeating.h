#pragma once
#include<iostream>
#include<sstream>
#include<vector>
#include"RepairService.h"
using namespace std; 
/*!
    \brief Implementation of the class FloorHeating
*/
class FloorHeating :public RepairService
{
public:
    FloorHeating(string, double, double);
    double getPrice() const override;

private:
    double cost;
    double floorArea;
    void checkOptions() override;

};