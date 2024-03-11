#pragma once
#include <iostream>
#include <vector>
#include"Services.h"
using namespace std;
/*!
    \brief Implementation of the class Client
*/
class Client
{
public:
    Client(string name, vector<RepairService*> requests, double money) :name(name), requests(requests), value(money), status(Status::formed) {};
    string name;
    double& money{ value };
    vector<RepairService*> requests;
    Status status;
    void setStatus(Status);
private:
    double value;
};
/*!
    \brief Implementation of the class RepairFirma
*/
class RepairFirma
{
public:
    RepairFirma(string, double);
    string name;
    void work(Client);
    void showStatus(Client);
    void checkRequests(Client);
private:
    double account;
    void pay(Client);
    bool consultation(Client)const;
    double getPrice(Client)const;
    void accept(Client);
    void start(Client);
    void finish(Client);
    Status defineStatus(Client client) const;
};


