#pragma once
#include<iostream>
#include<sstream>
#include<vector>
#include"DoorsInstallation.h"
#include"WindowsInstallation.h"
using namespace std; 
/*!
    \brief Implementation of the class Balcony
*/
class Balcony :public DoorsInstallation, WindowsInstallation
{
public:
    Balcony(string, int, int, double, int, double, double, double, double, double);
    double getPrice() const override;
private:
    double windowArea;
    double length;
    double height;
    void checkOptions() override;
};