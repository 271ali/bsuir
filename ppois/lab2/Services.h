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

class RepairService
{
public:
    RepairService(string);
    string serviceName;
    virtual double getPrice() = 0;
    Status status;
    void setStatus(Status);
    Status getStatus();
    void printStatus();
};

class Plumbing :public RepairService
{
public:
    Plumbing(string name, int tap, int toilet, double tapCost, double toiletCost);
    double getPrice() override;
private:
    int tap;
    int toilet;
    double tapCost;
    double toiletCost;
};

class Electrecity :public RepairService
{
public:
    Electrecity(string, int, int, double, double);
    double getPrice() override;

private:
    int lamp;
    int socket;
    double lampCost;
    double socketCost;

};

class WallsColoring :public RepairService
{
public:
    WallsColoring(string, double, double, double);
    double getPrice() override;

private:
    double length;
    double height;
    double paintCost;
};


class ParquetLaying :public RepairService
{
public:
    ParquetLaying(string, double, double);
    double getPrice() override;

private:
    double parquetCost;
    double floorArea;
};


class CeilingStretching : public RepairService
{
public:
    CeilingStretching(string, double, double);
    double getPrice() override;

private:
    double pvcCost;
    double ceilingArea;
};

class TilesLaying : public RepairService
{
public:
    TilesLaying(string, double, double, double);
    double getPrice() override;

private:
    double tileArea;
    double area;
    double tileCost;
};

class DoorsInstallation :virtual public RepairService
{
public:
    DoorsInstallation(string, int, int, double);
    double getPrice() override;
protected:
    int singleDoor;
    int dualDoor;
    double doorCost;

};

class WindowsInstallation :virtual public RepairService
{
public:
    WindowsInstallation(string, int, int, int, double, double);
    double getPrice() override;

protected:
    WindowsInstallation(string, int, double, double);
    int withMechanism;
    double windowCost;
    double mechanismCost;
private:
    int singleWindow;
    int dualWindow;
};

class Balcony :public DoorsInstallation, WindowsInstallation
{
public:
    Balcony(string, int, int, double, int, double, double, double, double, double);
    double getPrice() override;
private:
    double windowArea;
    double length;
    double height;
};
class Cabinet
{
public:
    Cabinet(double, double, double, int, DoorsInstallation);
    double length;
    double height;
    double width;
    int shelf;
    DoorsInstallation doorsInstallation;
};
class CabinetInstallation :public RepairService
{
public:
    CabinetInstallation(string, double, vector<Cabinet>);
    double getPrice() override;
private:
    vector<Cabinet> cabinets;
    double materialCost;
};
class ConductingGas :public RepairService
{
public:
    ConductingGas(string, int, double);
    double getPrice() override;

private:
    int gasStove;
    double gasStoveCost;

};
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
    double getPrice() override;


private:
    vector<Wall> walls;
    double bloñkVolume;
    double blockCost;
};

class Room
{
public:
    Room(double, double, double);
    double length;
    double width;
    double height;
};
class SoundInsulation :public RepairService
{
public:
    SoundInsulation(string, vector<Room>, double);
    double getPrice() override;

private:
    vector<Room> rooms;
    double cost;
};

class FloorHeating :public RepairService
{
public:
    FloorHeating(string, double, double);
    double getPrice() override;

private:
    double cost;
    double floorArea;
};
class BatteryInstallation :public RepairService
{
public:
    BatteryInstallation(string, int, double);
    double getPrice() override;

private:
    int rooms;
    double cost;

};







