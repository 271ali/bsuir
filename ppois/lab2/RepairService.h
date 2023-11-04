#pragma once
#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

enum Status
{
    formed = 0,
    accepted = 1,
    inProgress = 2,
    completed = 3
};
/*!
    \brief Implementation of the class RepairService
*/
class RepairService
{
public:
    RepairService(string);
    string serviceName;
    virtual double getPrice() const = 0;
    Status status;
    void setStatus(Status);
    Status getStatus();
    void printStatus();
    virtual void checkOptions() = 0;
protected :
    double check(double);
    int check(int);
   
};