#pragma once
#include<iostream>
#include<sstream>
#include<vector>
#include"RepairService.h"
using namespace std; 
/*!
    \brief Implementation of the class WallsColoring
*/
class WallsColoring :public RepairService
{
public:
    WallsColoring(string, double, double, double);
    double getPrice() const override;

private:
    double length;
    double height;
    double paintCost;
    void checkOptions() override;

};