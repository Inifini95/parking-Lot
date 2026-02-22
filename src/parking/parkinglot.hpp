

#include<iostream>
#include <string>
#include <vector>
#include "../vehicle/vehicle.hpp"
#include "../ticket/ticket.cpp"
#include<stdio.h>
using namespace std;

class ParkingLot
{
    
private:
    ParkingLot() {}                     // private constructor
    ParkingLot(const ParkingLot&) = delete;            // prevent copy
    ParkingLot& operator=(const ParkingLot&) = delete; // prevent assign

    static int bikeCount;
    static int carCount;
    static int truckCount;

public:
    static std::vector<Vehicle*> bikeParking;
    static std::vector<Vehicle*> carParking;
    static std::vector<Vehicle*> truckParking;
    
    static ParkingLot& getInstance() {
        static ParkingLot instance;     // created once
        return instance;
    }

    int getAvailablebikeSpots();
    int getAvailableCarSpots();
    int getAvailableTruckSpots();

    void parkVehicle(Vehicle *v, int time);

    void unparkvehicle(Vehicle *v, int time);

    void displayParkedVehicles();

    int getBikeCount() const { return bikeCount; }
    int getCarCount() const { return carCount; }
    int getTruckCount() const { return truckCount; }

    
    




};