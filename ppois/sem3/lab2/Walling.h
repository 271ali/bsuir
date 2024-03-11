#pragma once
#include<iostream>
#include<sstream>
#include<vector>
#include"RepairService.h"
using namespace std; 
/*!
    \brief Implementation of the class Walling
*/
class Wall
{
public:
    Wall(double, double, double);
    double length;
    double height;
    double thickness;

};
class Walling :public RepairService
{
public:
    Walling(string name, vector<Wall>, double, double);
    double getPrice() const override;


private:
    vector<Wall> walls;
    double bloñkVolume;
    double blockCost;
    void checkOptions() override;

};