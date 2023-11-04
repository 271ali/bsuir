#pragma once
#include<iostream>
#include<sstream>
#include<vector>
#include"RepairService.h"
using namespace std; 
/*!
    \brief Implementation of the class Room
*/
class Room
{
public:
    Room(double, double, double);
    double length;
    double width;
    double height;
};
/*!
    \brief Implementation of the class SoundInsulation
*/
class SoundInsulation :public RepairService
{
public:
    SoundInsulation(string, vector<Room>, double);
    double getPrice() const override;

private:
    vector<Room> rooms;
    double cost;
    void checkOptions() override;

};