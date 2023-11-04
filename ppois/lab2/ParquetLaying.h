#pragma once
#include<iostream>
#include<sstream>
#include<vector>
#include"RepairService.h"
using namespace std; 
/*!
    \brief Implementation of the class ParquetLaying
*/
class ParquetLaying :public RepairService
{
public:
    ParquetLaying(string, double, double);
    double getPrice() const override;

private:
    double parquetCost;
    double floorArea;
    void checkOptions() override;

};
