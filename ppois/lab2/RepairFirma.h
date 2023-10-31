#pragma once
#include <iostream>
#include <vector>
#include"Services.h"
using namespace std;

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

class RepairFirma
{
public:
    RepairFirma(string, double);
    string name;
    void work(Client);
    void pay(Client);;
    bool consultation(Client);
    double getPrice(Client);
    void accept(Client);
    void start(Client);
    void finish(Client);
    Status defineStatus(Client client);
    void showStatus(Client client);
private:
    double account;
};


