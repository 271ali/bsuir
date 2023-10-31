#include "pch.h"
#include "CppUnitTest.h"
#include"C:\Users\vgavr\source\repos\ppois_lab2_RepairFirma\ppois_lab2_RepairFirma\RepairFirma.h"
#include"C:\Users\vgavr\source\repos\ppois_lab2_RepairFirma\ppois_lab2_RepairFirma\Services.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Microsoft {
	namespace VisualStudio {
		namespace CppUnitTestFramework
		{
			template<> static std::wstring ToString<Status>(const Status& status)
			{
				switch (status){
				case formed:
					return L"formed";
				case accepted:
					return L"accepted";
				case inProgress:
					return L"inProgress";
				case completed:
					return L"completed";
				}
			};
		}
	}
}

namespace RepairFirmatest
{
	TEST_CLASS(RepairFirmatest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Plumbing object("plumbing repair", 3, 2, 10, 20);
			double answer = 70;
			Assert::AreEqual(object.getPrice(), answer);
		}
		TEST_METHOD(TestMethod2)
		{
			Electrecity object("electrecity repair", 7, 12, 10, 20);
			double answer = 310;
			Assert::AreEqual(object.getPrice(), answer);
		}
		TEST_METHOD(TestMethod3)
		{
			WallsColoring object("walls coloring", 6, 3, 10);
			double answer = 180;
			Assert::AreEqual(object.getPrice(), answer);
		}
		TEST_METHOD(TestMethod4)
		{
			ParquetLaying object("parquet laying", 60, 38);
			double answer = 2280;
			Assert::AreEqual(object.getPrice(), answer);
		}
		TEST_METHOD(TestMethod5)
		{
			ParquetLaying object("ceiling stretching", 27, 54);
			double answer = 1458;
			Assert::AreEqual(object.getPrice(), answer);
		}
		TEST_METHOD(TestMethod6)
		{
			TilesLaying object("tiles laying", 0.5,8, 27);
			double answer = 432;
			Assert::AreEqual(object.getPrice(), answer);
		}
		TEST_METHOD(TestMethod7)
		{
			DoorsInstallation object("doorsinstallation", 0, 2,44);
			double answer = 176;
			Assert::AreEqual(object.getPrice(), answer);
		}
		TEST_METHOD(TestMethod8)
		{
			WindowsInstallation object("windowsinstallation", 3, 4, 5,13,37);
			double answer = 472;
			Assert::AreEqual(object.getPrice(), answer);
		}
		TEST_METHOD(TestMethod9)
		{
			Balcony object("balcony", 1, 1, 41, 4, 15, 51,4, 3, 1.87);
			double answer = 510.27;
			Assert::AreEqual(object.getPrice(), answer);
		}
		TEST_METHOD(TestMethod10)
		{
			DoorsInstallation object1("doorsinstallation", 0, 1, 44);
			Cabinet cabinet1(2.5, 2, 1, 7, object1);
			DoorsInstallation object2("doorsinstallation", 1, 0, 30);
			Cabinet cabinet2(1.5, 2, 0.5, 3, object2);
			vector<Cabinet> cabinets;
			cabinets.push_back(cabinet1);
			cabinets.push_back(cabinet2);
			CabinetInstallation object("balcony",21,cabinets);
			double answer = 695.5;
			Assert::AreEqual(object.getPrice(), answer);
		}
		TEST_METHOD(TestMethod11)
		{
			ConductingGas object("conducting gas", 1, 74.5);
			double answer = 74.5;
			Assert::AreEqual(object.getPrice(), answer);
		}

		TEST_METHOD(TestMethod12)
		{
			Wall wall1(3.5, 0.3, 4);
			Wall wall2(2, 0.7, 2.5);
			Wall wall3(5, 0.2, 1);
			vector<Wall>walls;
			walls.push_back(wall1);
			walls.push_back(wall2);
			walls.push_back(wall3);
			Walling object("walling",walls,0.3,20);
			double answer = 580;
			Assert::AreEqual(object.getPrice(), answer);

		}
		TEST_METHOD(TestMethod13)
		{
			Room room(3, 4, 3.5);
			vector<Room> rooms;
			rooms.push_back(room);
			SoundInsulation object("soundinsulation",rooms,11);
			double answer = 803;
			Assert::AreEqual(object.getPrice(), answer);
		}
		TEST_METHOD(TestMethod14)
		{
			FloorHeating object("floor heating", 135, 6);
			double answer = 810;
			Assert::AreEqual(object.getPrice(), answer);
		}

		TEST_METHOD(TestMethod15)
		{
			BatteryInstallation object("batteries", 4, 55.7);
			double answer = 222.8;
			Assert::AreEqual(object.getPrice(), answer);
		}
		TEST_METHOD(TestMethod16)
		{
			Plumbing object1("plumbing repair", 3, 2, 10, 20);
			RepairService* request1 = &object1;
			ParquetLaying object2("ceiling stretching", 27, 54);
			RepairService* request2 = &object2;
			WindowsInstallation object3("windowsinstallation", 3, 4, 5, 13, 37);
			RepairService* request3 = &object3;
			vector<RepairService*> requests{request1,request2,request3};
			Client person("Alexey", requests, 10899);
			RepairFirma firma("firma", 345555555555);
			firma.pay(person);
			double answer = 8899;
			Assert::AreEqual(person.money, answer);
		}
		TEST_METHOD(TestMethod17)
		{
			Plumbing object1("plumbing repair", 3, 2, 10, 20);
			RepairService* request1 = &object1;
			ParquetLaying object2("ceiling stretching", 27, 54);
			RepairService* request2 = &object2;
			WindowsInstallation object3("windowsinstallation", 3, 4, 5, 13, 37);
			RepairService* request3 = &object3;
			vector<RepairService*> requests{ request1,request2,request3 };
			Client person("Alexey", requests, 1889);
			RepairFirma firma("firma", 345555555555);
			bool answer = false;
			Assert::AreEqual(firma.consultation(person), answer);
		}
		TEST_METHOD(TestMethod18)
		{
			Plumbing object1("plumbing repair", 3, 2, 10, 20);
			RepairService* request1 = &object1;
			ParquetLaying object2("ceiling stretching", 27, 54);
			RepairService* request2 = &object2;
			WindowsInstallation object3("windowsinstallation", 3, 4, 5, 13, 37);
			RepairService* request3 = &object3;
			vector<RepairService*> requests{ request1,request2,request3 };
			Client person("Alexey", requests, 1889);
			RepairFirma firma("firma", 345555555555);
			double answer = 2000;
			Assert::AreEqual(firma.getPrice(person), answer);
		}
		TEST_METHOD(TestMethod19)
		{
			Plumbing object1("plumbing repair", 3, 2, 10, 20);
			RepairService* request1 = &object1;
			ParquetLaying object2("ceiling stretching", 27, 54);
			RepairService* request2 = &object2;
			WindowsInstallation object3("windowsinstallation", 3, 4, 5, 13, 37);
			RepairService* request3 = &object3;
			vector<RepairService*> requests{ request1,request2,request3 };
			Client person("Alexey", requests, 1889);
			RepairFirma firma("firma", 345555555555);
			firma.accept(person);
			Status answer = accepted;
			Assert::AreEqual((*person.requests[2]).status, answer);

		}
		TEST_METHOD(TestMethod20)
		{
			Plumbing object1("plumbing repair", 3, 2, 10, 20);
			RepairService* request1 = &object1;
			ParquetLaying object2("ceiling stretching", 27, 54);
			RepairService* request2 = &object2;
			WindowsInstallation object3("windowsinstallation", 3, 4, 5, 13, 37);
			RepairService* request3 = &object3;
			vector<RepairService*> requests{ request1,request2,request3 };
			Client person("Alexey", requests, 1889);
			RepairFirma firma("firma", 345555555555);
			firma.start(person);
			Status answer = inProgress;
			Assert::AreEqual((*person.requests[2]).status, answer);

		}
		TEST_METHOD(TestMethod21)
		{
			Plumbing object1("plumbing repair", 3, 2, 10, 20);
			RepairService* request1 = &object1;
			ParquetLaying object2("ceiling stretching", 27, 54);
			RepairService* request2 = &object2;
			WindowsInstallation object3("windowsinstallation", 3, 4, 5, 13, 37);
			RepairService* request3 = &object3;
			vector<RepairService*> requests{ request1,request2,request3 };
			Client person("Alexey", requests, 1889);
			RepairFirma firma("firma", 345555555555);
			firma.finish(person);
			Status answer = completed;
			Assert::AreEqual((*person.requests[2]).status, answer);

		}
		TEST_METHOD(TestMethod22)
		{
			Plumbing object1("plumbing repair", 3, 2, 10, 20);
			RepairService* request1 = &object1;
			ParquetLaying object2("ceiling stretching", 27, 54);
			RepairService* request2 = &object2;
			WindowsInstallation object3("windowsinstallation", 3, 4, 5, 13, 37);
			RepairService* request3 = &object3;
			vector<RepairService*> requests{ request1,request2,request3 };
			Client person("Alexey", requests, 1889);
			RepairFirma firma("firma", 345555555555);
			(*person.requests[0]).setStatus(accepted);
			(*person.requests[1]).setStatus(accepted);
			Status answer = formed;
			Assert::AreEqual(firma.defineStatus(person), answer);

		}

	};
}
//TEST_METHOD(TestMethod1)
//{
//	Worker worker("Alexey", 10);
//	worker.changeState();
//	Assert::AreEqual(worker.employed, true);
//}
//TEST_METHOD(TestMethod2)
//{
//	Electrecity electrecity;
//	electrecity.execute();
//	Assert::AreEqual(electrecity.electrecity, true);
//}
//TEST_METHOD(TestMethod3)
//{
//	Electrecity electrecity;
//	electrecity.execute();
//	Assert::AreEqual(electrecity.electrecity, true);
//}
//TEST_METHOD(TestMethod4)
//{
//	Electrecity electrecity;
//	electrecity.execute();
//	Assert::AreEqual(electrecity.electrecity, true);
//}
//TEST_METHOD(TestMethod5)
//{
//	Electrecity electrecity;
//	electrecity.execute();
//	Assert::AreEqual(electrecity.electrecity, true);
//}
//TEST_METHOD(TestMethod6)
//{
//	Plumbing plumbing;
//	plumbing.execute();
//	Assert::AreEqual(plumbing.plumbing, true);
//}
//TEST_METHOD(TestMethod7)
//{
//	ParquetLaying parquetLaying;
//	parquetLaying.execute();
//	Assert::AreEqual(parquetLaying.parquetLaying, true);
//}
//TEST_METHOD(TestMethod8)
//{
//	WallsColoring wallscoloring;
//	wallscoloring.execute();
//	Assert::AreEqual(wallscoloring.wallsColoring, true);
//}
//TEST_METHOD(TestMethod9)
//{
//	TilesLaying tileslaying;
//	tileslaying.execute();
//	Assert::AreEqual(tileslaying.tilesLaying, true);
//}
//TEST_METHOD(TestMethod10)
//{
//	CeilingStretching ceilingstretching;
//	ceilingstretching.execute();
//	Assert::AreEqual(ceilingstretching.ceilingStretching, true);
//}
//TEST_METHOD(TestMethod11)
//{
//	Furnitur furnitur;
//	furnitur.execute();
//	Assert::AreEqual(furnitur.furnitur, true);
//}
//TEST_METHOD(TestMethod12)
//{
//	Kitchen kitchen;
//	kitchen.execute();
//	Assert::AreEqual(kitchen.kitchen, true);
//}
//TEST_METHOD(TestMethod13)
//{
//	Bathroom bathroom;
//	bathroom.execute();
//	Assert::AreEqual(bathroom.bathroom, true);
//}
//TEST_METHOD(TestMethod14)
//{
//
//	vector <RepairService*> services1;
//	vector <RepairService*> services2;
//	vector<Worker> workers;
//	WallsColoring s1("wallscoloring", 15.1, 1);
//	CeilingStretching s2("ceilingstretching", 10.2, 1);
//	WallsColoring r1(53);
//	CeilingStretching r2(42);
//	RepairService* s11 = &s1;
//	RepairService* s22 = &s2;
//	RepairService* r11 = &r1;
//	RepairService* r22 = &r2;
//	services1.push_back(s11);
//	services1.push_back(s22);
//	services2.push_back(r11);
//	services2.push_back(r22);
//	RepairFirma firma("firma", services1, workers);
//	Client client1("petr", services2, 20000);
//	Assert::AreEqual(firma.getPrice(client1), 1434.5);
//}
//TEST_METHOD(TestMethod15)
//{
//
//	vector <RepairService*> services1;
//	vector <RepairService*> services2;
//	vector<Worker> workers;
//	WallsColoring s1("wallscoloring", 15.1, 1);
//	CeilingStretching s2("ceilingstretching", 10.2, 1);
//	WallsColoring r1(53);
//	CeilingStretching r2(42);
//	RepairService* s11 = &s1;
//	RepairService* s22 = &s2;
//	RepairService* r11 = &r1;
//	RepairService* r22 = &r2;
//	services1.push_back(s11);
//	services1.push_back(s22);
//	services2.push_back(r11);
//	services2.push_back(r22);
//	RepairFirma firma("firma", services1, workers);
//	Client client1("petr", services2, 20000);
//	firma.pay(client1);
//	Assert::AreEqual(firma.profit, 1434.5);
//}
//TEST_METHOD(TestMethod16)
//{
//
//	vector <RepairService*> services1;
//	vector <RepairService*> services2;
//	vector<Worker> workers;
//	WallsColoring s1("wallscoloring", 15.1, 1);
//	CeilingStretching s2("ceilingstretching", 10.2, 1);
//	WallsColoring r1(53);
//	CeilingStretching r2(42);
//	RepairService* s11 = &s1;
//	RepairService* s22 = &s2;
//	RepairService* r11 = &r1;
//	RepairService* r22 = &r2;
//	services1.push_back(s11);
//	services1.push_back(s22);
//	services2.push_back(r11);
//	services2.push_back(r22);
//	RepairFirma firma("firma", services1, workers);
//	Client client1("petr", services2, 20000);
//	firma.pay(client1);
//	Assert::AreEqual(firma.consultation(client1), true);
//}
//
//TEST_METHOD(TestMethode17)
//{
//	vector <RepairService*> services1;
//	vector <RepairService*> services2;
//	WallsColoring s1("wallscoloring", 15.1, 1);
//	CeilingStretching s2("ceilingstretching", 10.2, 1);
//	WallsColoring r1(53);
//	CeilingStretching r2(42);
//	RepairService* s11 = &s1;
//	RepairService* s22 = &s2;
//	RepairService* r11 = &r1;
//	RepairService* r22 = &r2;
//	services1.push_back(s11);
//	services1.push_back(s22);
//	services2.push_back(r11);
//	services2.push_back(r22);
//	Client client1("petr", services2, 20000);
//	vector<Worker> workers;
//	Painter painter("Yuriy", 7);
//	CeilingInstaller ceilingstretcher("Valriy", 4);
//	workers.push_back(painter);
//	workers.push_back(ceilingstretcher);
//	RepairFirma firma("firma", services1, workers);
//	firma.workersSort(client1);
//	vector<Worker>brigade;
//	brigade.push_back(painter);
//	brigade.push_back(ceilingstretcher);
//	Assert::AreEqual(brigade[0].name, firma.brigade[0].name);
//
//}
//TEST_METHOD(TestMethode18)
//{
//
//	vector <RepairService*> services1;
//	vector <RepairService*> services2;
//	WallsColoring s1("wallscoloring", 15.1, 1);
//	CeilingStretching s2("ceilingstretching", 10.2, 1);
//	WallsColoring r1(53);
//	CeilingStretching r2(42);
//	RepairService* s11 = &s1;
//	RepairService* s22 = &s2;
//	RepairService* r11 = &r1;
//	RepairService* r22 = &r2;
//	services1.push_back(s11);
//	services1.push_back(s22);
//	services2.push_back(r11);
//	services2.push_back(r22);
//	Client client1("petr", services2, 20000);
//	vector<Worker> workers;
//	Painter painter("Yuriy", 7);
//	CeilingInstaller ceilingstretcher("Valriy", 4);
//	workers.push_back(painter);
//	workers.push_back(ceilingstretcher);
//	RepairFirma firma("firma", services1, workers);
//	firma.workersSort(client1);
//	vector<Worker>brigade;
//	brigade.push_back(painter);
//	brigade.push_back(ceilingstretcher);
//	firma.workersCompensation(client1);
//	Assert::AreEqual(firma.profit, 1283.8);
//}