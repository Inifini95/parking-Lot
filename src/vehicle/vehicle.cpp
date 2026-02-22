#include "vehicle.hpp"

Vehicle::Vehicle(string comp, string t, int yr, string numplate) : company(comp), type(t), year(yr), numPlate(numplate)
{
    vehicleCount++;
}
Vehicle::~Vehicle()
{
    vehicleCount--;
}
void Vehicle::displayInfo()
{
    cout << "Company: " << company << endl;
    cout << "Year: " << year << endl;
}
int Vehicle::getVehicleCount()
{
    return vehicleCount;
}

Bike::Bike(string comp, string mod, int yr, string t, string numPl) : Vehicle(comp, t, yr, numPl), model(mod)
{
    bikeCount++;
}
Bike::~Bike()
{
    bikeCount--;
}   
void Bike::displayInfo()
{
    Vehicle::displayInfo();
    cout << "Model: " << model << endl;
    cout << "Number Plate: " << numPlate << endl;
}

int Bike::getVehicleCount()
{
    return bikeCount;
}
string Bike::getModel()
{
    return model;
}

Car::Car(string comp, string mod, int yr, string t, string numPl) : Vehicle(comp, t, yr, numPl), model(mod)
{
    carCount++;
}
Car::~Car()
{
    carCount--;
}
void Car::displayInfo()
{
    Vehicle::displayInfo();
    cout << "Model: " << model << endl;
    cout << "Number Plate: " << numPlate << endl;
}

int Car::getVehicleCount()
{
    return carCount;
}
string Car::getModel()
{
    return model;
}

Truck::Truck(string comp, string mod, int yr, string t, string numPl) : Vehicle(comp, t, yr, numPl), model(mod)
{
    truckCount++;
}
Truck::~Truck()
{
    truckCount--;
}
void Truck::displayInfo()
{
    Vehicle::displayInfo();
    cout << "Model: " << model << endl;
    cout << "Number Plate: " << numPlate << endl;
}

int Truck::getVehicleCount()
{
    return truckCount;
}
string Truck::getModel()
{
    return model;
}