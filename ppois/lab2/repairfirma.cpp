#include<iostream>
#include"RepairFirma.h"

using namespace std;

int main()
{
	Balcony object1("balcony", 1, 1, 41, 4, 15, 51, 4, 3, 1.87);

	ParquetLaying object2("parquet laying", 60, 38);

	ConductingGas object3("conducting gas", 1, 74.5);

	BatteryInstallation object4("batteries", 4, 55.7);

	DoorsInstallation doors1("doorsinstallation", 0, 1, 44);
	Cabinet cabinet1(2.5, 2, 1, 7, doors1);
	DoorsInstallation doors2("doorsinstallation", 1, 0, 30);
	Cabinet cabinet2(1.5, 2, 0.5, 3, doors2);
	vector<Cabinet> cabinets;
	cabinets.push_back(cabinet1);
	cabinets.push_back(cabinet2);
	CabinetInstallation object5("balcony", 21, cabinets);

	RepairService* request1 = &object1;
	RepairService* request2 = &object2;
	RepairService* request3 = &object3;
	RepairService* request4 = &object4;
	RepairService* request5 = &object5;
	vector<RepairService*> requests;
	requests.push_back(request1);
	requests.push_back(request2);
	requests.push_back(request3);
	requests.push_back(request4);
	requests.push_back(request5);
	Client client1("Alexey", requests, 50000);
	Client client2("Ivan", requests, 3000);
	RepairFirma firma("Remont", 1829839717);
	firma.work(client1);
	firma.work(client2);


}