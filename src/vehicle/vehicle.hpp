#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include<stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
    protected:
        string company;
        string type;
        int year;
        string numPlate;

        static int vehicleCount;
    public:
    virtual int getVehicleCount() = 0;
    virtual string getModel() = 0;
    Vehicle(string comp, string t, int yr, string numplate);
    ~Vehicle();
    void displayInfo();
    string getType() { return type; }
    string getNumPlate() { return numPlate; }
};

class Bike: public Vehicle{
    private:
        static int bikeCount;
        string model;
    public:
    int getVehicleCount();
    string getModel();
    Bike(string comp, string mod, int yr, string t, string numPlate);
    ~Bike();
    void displayInfo();
};

class Car: public Vehicle{
    private:
        static int carCount;
        string model;
    public:
    int getVehicleCount();
    string getModel();
    Car(string comp, string mod, int yr, string t, string numPlate);
    ~Car();
    void displayInfo();
};
class Truck: public Vehicle{
    private:
        static int truckCount;
        string model;
    public:
    int getVehicleCount();
    string getModel();
    Truck(string comp, string mod, int yr, string t, string numPlate);
    ~Truck();
    void displayInfo();
};

#endif