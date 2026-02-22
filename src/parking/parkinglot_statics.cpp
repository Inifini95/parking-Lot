#include "parkinglot.hpp"

// Initialize static members for ParkingLot
int ParkingLot::bikeCount = 0;
int ParkingLot::carCount = 0;
int ParkingLot::truckCount = 0;
std::vector<Vehicle*> ParkingLot::bikeParking(100, nullptr);
std::vector<Vehicle*> ParkingLot::carParking(100, nullptr);
std::vector<Vehicle*> ParkingLot::truckParking(100, nullptr);