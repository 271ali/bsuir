
#include"Services.h"
#include<iostream>
using namespace std;

RepairService::RepairService(string name) :serviceName(name), status(formed) { };
void RepairService::setStatus(Status set)
{
    status = set;
}
Status RepairService::getStatus()
{
    return status;
}

void RepairService::printStatus()
{
    cout << "Status of " << serviceName << " is " << status << endl;
}

Plumbing::Plumbing(string name, int tap, int toilet, double tapCost, double toiletCost) :RepairService(name), tap(tap), toilet(toilet), tapCost(tapCost), toiletCost(toiletCost) {};
double Plumbing::getPrice()
{
    double value = tap * tapCost + toilet * toiletCost;
    return round(value * 100) / 100;
}


Electrecity::Electrecity(string name, int lamp, int socket, double lampCost, double socketCost) :RepairService(name), lamp(lamp), socket(socket), lampCost(lampCost), socketCost(socketCost) {};
double Electrecity::getPrice()
{
    double value = lamp * lampCost + socket * socketCost;
    return round(value * 100) / 100;
}

WallsColoring::WallsColoring(string name, double length, double height, double paintCost) :RepairService(name), length(length), height(height), paintCost(paintCost) {};
double WallsColoring::getPrice()
{
    double value = length * height * paintCost;
    return round(value * 100) / 100;
}

ParquetLaying::ParquetLaying(string name, double floorArea, double parquetCost) :RepairService(name), floorArea(floorArea), parquetCost(parquetCost) {};
double ParquetLaying::ParquetLaying::getPrice()
{
    double value = floorArea * parquetCost;
    return round(value * 100) / 100;
}

CeilingStretching::CeilingStretching(string name, double pvcCost, double ceilingArea) :RepairService(name), pvcCost(pvcCost), ceilingArea(ceilingArea) {};
double CeilingStretching::getPrice()
{
    double value = pvcCost * ceilingArea;
    return round(value * 100) / 100;
}

TilesLaying::TilesLaying(string name, double tileArea, double tileCost, double area) : RepairService(name), tileArea(tileArea), tileCost(tileCost), area(area) {};
double TilesLaying::getPrice()
{
    double value = area / tileArea * tileCost;
    return round(value * 100) / 100;
}

DoorsInstallation::DoorsInstallation(string name, int singleDoor, int dualDoor, double doorCost) :RepairService(name), singleDoor(singleDoor), dualDoor(dualDoor), doorCost(doorCost) {};
double DoorsInstallation::getPrice()
{
    double value = singleDoor * doorCost + 2 * dualDoor * doorCost;
    return round(value * 100) / 100;
}

WindowsInstallation::WindowsInstallation(string name, int singleWindow, int dualWindow, int withMechanism, double mechanismCost, double windowCost) :RepairService(name), singleWindow(singleWindow), dualWindow(dualWindow), mechanismCost(mechanismCost), windowCost(windowCost), withMechanism(withMechanism) {};
WindowsInstallation::WindowsInstallation(string name, int withMechanism, double mechanismCost, double windowCost) :RepairService(name), mechanismCost(mechanismCost), windowCost(windowCost), withMechanism(withMechanism), dualWindow(0), singleWindow(0) {};
double WindowsInstallation::getPrice()
{
    double value = singleWindow * windowCost + 2 * dualWindow * windowCost + withMechanism * mechanismCost;
    return round(value * 100) / 100;
}

Balcony::Balcony(string name, int singleDoor, int dualDoor, double doorCost, int withMechanism, double mechanismCost, double windowCost, double length, double height, double windowArea) :RepairService(name), DoorsInstallation(name, singleDoor, dualDoor, doorCost), WindowsInstallation(name, withMechanism, mechanismCost, windowCost)
{
    this->windowArea = windowArea;
    this->length = length;
    this->height = height;
};
double Balcony::getPrice()
{
    double value = (singleDoor * doorCost + 2 * dualDoor * doorCost) + (height * length / windowArea * windowCost) + withMechanism * mechanismCost;
    return round(value * 100) / 100;
}

Cabinet::Cabinet(double length, double width, double height, int shelf, DoorsInstallation doorsInstallation) :length(length), width(width), height(height), shelf(shelf), doorsInstallation(doorsInstallation) {};
CabinetInstallation::CabinetInstallation(string name, double materialCost, vector<Cabinet> cabinets) :RepairService(name), cabinets(cabinets), materialCost(materialCost) {};
double CabinetInstallation::getPrice()
{
    double price = 0;
    for (int i = 0; i < cabinets.size(); i++)
    {
        price += materialCost * (2 * cabinets[i].length * cabinets[i].width + 2 * cabinets[i].width * cabinets[i].height + cabinets[i].length + cabinets[i].height) + cabinets[i].doorsInstallation.getPrice();
    }
    return round(price * 100) / 100;
}

ConductingGas::ConductingGas(string name, int gasStove, double gasStoveCost) :RepairService(name), gasStove(gasStove), gasStoveCost(gasStoveCost) {};
double ConductingGas::getPrice()
{
    double value = gasStove * gasStoveCost;
    return round(value * 100) / 100;
}

Wall::Wall(double length, double width, double height) :length(length), thickness(width), height(height) {};
Walling::Walling(string name, vector<Wall> walls, double blockVolume, double blockCost) :RepairService(name), walls(walls), bloñkVolume(blockVolume), blockCost(blockCost) {};
double Walling::getPrice()
{
    double price = 0;
    for (int i = 0; i < walls.size(); i++)
    {
        price += (walls[i].length * walls[i].thickness * walls[i].height) / bloñkVolume * blockCost;
    }
    return round(price * 100) / 100;
}
Room::Room(double length, double width, double height) :length(length), width(width), height(height) {};
SoundInsulation::SoundInsulation(string name, vector<Room> rooms, double cost) :RepairService(name), rooms(rooms), cost(cost) {};
double SoundInsulation::getPrice()
{
    double price = 0;
    for (int i = 0; i < rooms.size(); i++)
    {
        price += 2 * (rooms[i].length * rooms[i].width + rooms[i].length * rooms[i].height + rooms[i].width * rooms[i].height) * cost;
    }
    return round(price * 100) / 100;
}

FloorHeating::FloorHeating(string name, double floorArea, double cost) :RepairService(name), floorArea(floorArea), cost(cost) {};
double FloorHeating::getPrice()
{
    double value = floorArea * cost;
    return round(value * 100) / 100;
}
BatteryInstallation::BatteryInstallation(string name, int rooms, double cost) :RepairService(name), rooms(rooms), cost(cost) {};
double BatteryInstallation::getPrice()
{
    double value = rooms * cost;
    return round(value * 100) / 100;
}







































