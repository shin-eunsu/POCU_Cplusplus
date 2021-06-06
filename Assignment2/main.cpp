#include <cassert>

#include "Vehicle.h"
#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"
#include "Motorcycle.h"
#include "Sedan.h"
#include "Trailer.h"
#include "UBoat.h"
#include "DeusExMachina.h"
#include "Person.h"


using namespace assignment2;


void Test0();
void Test1();
void Test2();

int main()
{
	Test0();
}

void Test0()
{
	Person* p = new Person("Bob", 85);

	assert(p->GetName() == std::string("Bob"));
	assert(p->GetWeight() == 85);

	Person* p2 = new Person("James", 75);
	Person* p3 = new Person("Tina", 52);

	Person* p4 = new Person("Peter", 78);
	Person* p5 = new Person("Jane", 48);
	Person* p6 = new Person("Steve", 88);

	Airplane a(5);
	a.AddPassenger(p);
	a.AddPassenger(p2);
	a.AddPassenger(p3);

	assert(a.GetMaxPassengersCount() == 5);
	assert(a.GetPassengersCount() == 3);
	assert(a.GetPassenger(1) == p2);
	assert(a.GetFlySpeed() == 648);
	assert(a.GetDriveSpeed() == 59);
	assert(a.GetMaxSpeed() == 648);

	Boat b(5);
	b.AddPassenger(p4);
	b.AddPassenger(p5);
	b.AddPassenger(p6);

	Boatplane bp = a + b;

	assert(bp.GetPassengersCount() == 6);
	assert(bp.GetMaxPassengersCount() == 10);

	assert(a.GetPassengersCount() == 0);
	assert(b.GetPassengersCount() == 0);

	DeusExMachina* deusExMachina1 = DeusExMachina::GetInstance();
	DeusExMachina* deusExMachina2 = DeusExMachina::GetInstance();

	bool bSame = deusExMachina1 == deusExMachina2;
	assert(bSame);

	Airplane* airplane = new Airplane(5);
	Boat* boat = new Boat(5);
	Boatplane* boatplane = new Boatplane(5);
	Motorcycle* motorcycle = new Motorcycle();
	Sedan* sedan = new Sedan();
	Sedan* sedan2 = new Sedan();
	UBoat* uboat = new UBoat();

	bool bAdded = sedan2->AddTrailer(new Trailer(50));
	assert(bAdded);

	bAdded = sedan2->AddTrailer(new Trailer(60));
	assert(!bAdded);

	bAdded = deusExMachina1->AddVehicle(airplane);
	assert(bAdded);

	deusExMachina1->AddVehicle(boat);
	deusExMachina1->AddVehicle(boatplane);
	deusExMachina1->AddVehicle(motorcycle);
	deusExMachina1->AddVehicle(sedan);
	deusExMachina1->AddVehicle(sedan2);
	deusExMachina1->AddVehicle(uboat);
	deusExMachina1->AddVehicle(new Airplane(5));
	deusExMachina1->AddVehicle(new Airplane(5));
	deusExMachina1->AddVehicle(new Airplane(5));

	bAdded = deusExMachina1->AddVehicle(new Airplane(5));

	assert(!bAdded);

	deusExMachina1->RemoveVehicle(9);
	deusExMachina1->RemoveVehicle(8);
	bool bRemoved = deusExMachina1->RemoveVehicle(7);
	assert(bRemoved);

	bRemoved = deusExMachina1->RemoveVehicle(9);
	assert(!bRemoved);

	deusExMachina1->Travel(); // 모든 운송 수단이 이동
	deusExMachina1->Travel(); // Boat, Motorcycle, 두 Sedan, UBoat가 이동
	deusExMachina1->Travel(); // Motorcycle, 두 Sedan이 이동
	deusExMachina1->Travel(); // Boat, Motorcycle, 두 Sedan이 이동
	deusExMachina1->Travel(); // UBoat만 빼고 전부 이동
	deusExMachina1->Travel(); // 어떤 운송 수단도 움직이지 않음
	deusExMachina1->Travel(); // Boat, Motorcycle, 트레일러 안 달린 Sedan, UBoat가 이동
	deusExMachina1->Travel(); // Boat, Motorcycle, 두 Sedan, UBoat가 이동
	deusExMachina1->Travel(); // Airplane, Boatplane, Motorcycle, 두 Sedan이 이동
	deusExMachina1->Travel(); // Boat, Motorcycle, 두 Sedan이 이동
	deusExMachina1->Travel(); // Boat, Motorcycle, 두 Sedan이 이동
	deusExMachina1->Travel(); // 트레일러 달린 Sedan만 이동

	assert(deusExMachina1->GetFurthestTravelled() == boat);

	return 0;
}

void Test1()
{
	//const char* MAX_SPEED_LABLE = "Max Speed: ";
	//const char* CUR_P_LABLE = "Current Person: ";
	//const unsigned int MAX_CAPACITY = 10;

	//Vehicle* air = new Airplane(MAX_CAPACITY);

	//Person* toAdd;
	//const unsigned int personWeight = 10;

	//for (size_t i = 0; i < MAX_CAPACITY + 10; i++)
	//{
	//	toAdd = new Person(STR(i), i);
	//	if (air->AddPassenger(toAdd) == false)
	//	{
	//		delete toAdd;
	//	}

	//	cout << MAX_SPEED_LABLE << air->GetMaxSpeed() << endl
	//		<< CUR_P_LABLE << air->GetPassengersCount() << endl;
	//}

	//while (air->RemovePassenger(0))
	//{
	//	cout << CUR_P_LABLE << air->GetPassengersCount() << endl;;
	//}

	//Person* overlapTest = new Person("Overlap Test", 100);
	//air->AddPassenger(overlapTest);
	//air->AddPassenger(overlapTest);
	//assert(air->GetPassengersCount() == 1); // 빌드봇은 이런 테스트 안함

	//toAdd = NULL;
	//assert(air->AddPassenger(toAdd) == false); // 빌드봇은 이런 테스트 안함

	//delete air;

	//Airplane dockingTest1(10);
	//Boat dockingTest2(10);

	//for (size_t i = 0; i < 5; i++)
	//{
	//	dockingTest1.AddPassenger(new Person(STR(i), i));
	//	dockingTest2.AddPassenger(new Person(STR(i), i));
	//}

	//const Person* comp1 = dockingTest1.GetPassenger(0);

	//Boatplane bp1 = dockingTest1 + dockingTest2;
	//Boatplane bp2 = dockingTest2 + dockingTest1;

	//const Person* comp2 = bp1.GetPassenger(0);

	//assert(comp1 == comp2); // 빌드봇은 이런 테스트 안함
	//assert(dockingTest1.GetPassengersCount() == 0);
	//assert(dockingTest2.GetPassengersCount() == 0);
	//assert(bp1.GetPassengersCount() == 10);
	//assert(bp2.GetPassengersCount() == 0);

	//Boatplane copyConstuctorTest(bp1);

	//for (size_t i = 0; i < bp1.GetPassengersCount(); i++)
	//{
	//	const Person* p1 = bp1.GetPassenger(i);
	//	const Person* p2 = copyConstuctorTest.GetPassenger(i);
	//	assert(p1 != p2);
	//}
	//assert(bp1.GetMaxPassengersCount() == copyConstuctorTest.GetMaxPassengersCount());
	//assert(bp1.GetPassengersCount() == copyConstuctorTest.GetPassengersCount());
	//assert(bp1.GetMaxSpeed() == copyConstuctorTest.GetMaxSpeed());

	//Sedan sedanTest;
	//Trailer* t1 = new Trailer(10);
	//Trailer* t2 = new Trailer(20);

	//assert(sedanTest.AddTrailer(t1));
	//assert(!sedanTest.AddTrailer(t1));
	//assert(!sedanTest.AddTrailer(t2));
	//assert(sedanTest.RemoveTrailer());
	//assert(sedanTest.AddTrailer(t2));
	//assert(sedanTest.RemoveTrailer());

	//DeusExMachina* d = DeusExMachina::GetInstance();
	//Vehicle* demAirplain = new Airplane(MAX_CAPACITY);
	//Vehicle* demBoat = new Airplane(MAX_CAPACITY);
	//Vehicle* demBoatplain = new Boatplane(MAX_CAPACITY);
	//Vehicle* demMotorcycle = new Motorcycle();
	//Vehicle* demSedan1 = new Sedan();
	//Vehicle* demSedan2 = new Sedan();
	//Trailer* demTrailer = new Trailer(10);
	//static_cast<Sedan*>(demSedan2)->AddTrailer(demTrailer);
	//Vehicle* demUBoat = new UBoat();

	//d->AddVehicle(demAirplain);
	//d->AddVehicle(demBoat);
	//d->AddVehicle(demBoatplain);
	//d->AddVehicle(demMotorcycle);
	//d->AddVehicle(demSedan1);
	//d->AddVehicle(demSedan2);
	//d->AddVehicle(demUBoat);

	//for (size_t i = 0; i < 7; i++)
	//{
	//	Vehicle* tempVPointer = d->GetVehicle(i);
	//	for (size_t j = tempVPointer->GetPassengersCount(); j < tempVPointer->GetMaxPassengersCount(); j++)
	//	{
	//		tempVPointer->AddPassenger(new Person(STR((i + j)), 10));
	//	}
	//}

	//for (size_t i = 0; i < 10; i++)
	//{
	//	d->Travel();
	//}

	//delete d;
}

void Test2()
{
	//Airplane* airplane = new Airplane(0);
	//Boat* boat = new Boat(0);
	//DeusExMachina* deusExMachina = DeusExMachina::GetInstance();
	//deusExMachina->AddVehicle(airplane);
	//deusExMachina->AddVehicle(boat);
	//deusExMachina->Travel();
	//assert(deusExMachina->GetFurthestTravelled() == airplane);
}