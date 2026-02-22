#include <iostream>
#include <string>
#include <memory>
#include <sstream>
#include <regex>
#include <stdexcept>
#include <thread>
#include <mutex>
#include "vehicle/vehicle.hpp"
#include "ticket/ticket.cpp"
#include "parking/parkinglot.hpp"

using namespace std;

// ============ Implementation Layer ============




// ============ Main ============
int main() {

    ParkingLot& parkingLot = ParkingLot::getInstance();
    
    // Create Bikes
    Vehicle *vehicle;
    Bike bike1("Hero", "Splendor", 2020, "Bike", "BK001");
    Bike bike2("Honda", "Activa", 2021, "Bike", "BK002");
    Bike bike3("Bajaj", "Pulsar", 2022, "Bike", "BK003");
    Bike bike4("TVS", "Apache", 2023, "Bike", "BK004");
    Bike bike5("Royal Enfield", "Classic", 2024, "Bike", "BK005");
    
    // Create Cars
    Car car1("Maruti", "Swift", 2020, "Car", "CR001");
    Car car2("Hyundai", "i20", 2021, "Car", "CR002");
    Car car3("Toyota", "Fortuner", 2022, "Car", "CR003");
    Car car4("Honda", "City", 2023, "Car", "CR004");
    Car car5("BMW", "X5", 2024, "Car", "CR005");
    
    // Create Trucks
    Truck truck1("TATA", "Ace", 2020, "Truck", "TR001");
    Truck truck2("Ashok Leyland", "Dost", 2021, "Truck", "TR002");
    Truck truck3("Mahindra", "Bolero", 2022, "Truck", "TR003");
    Truck truck4("Volvo", "FH16", 2023, "Truck", "TR004");
    Truck truck5("Scania", "R440", 2024, "Truck", "TR005");
    
    cout << "========== TEST SCENARIOS ==========" << endl << endl;
    
    // TEST 1: Park a bike - basic functionality
    cout << "TEST 1: Park Bike 1" << endl;
    parkingLot.parkVehicle(&bike1, 100);  // Entry time: 100
    cout << "Bikes parked: " << parkingLot.getBikeCount() << " | Available spots: " << parkingLot.getAvailablebikeSpots() << endl << endl;
    
    // TEST 2: Park multiple bikes
    cout << "TEST 2: Park Bike 2 and Bike 3" << endl;
    parkingLot.parkVehicle(&bike2, 105);
    parkingLot.parkVehicle(&bike3, 110);
    cout << "Bikes parked: " << parkingLot.getBikeCount() << " | Available spots: " << parkingLot.getAvailablebikeSpots() << endl << endl;
    
    // TEST 3: Park a car
    cout << "TEST 3: Park Car 1" << endl;
    parkingLot.parkVehicle(&car1, 120);
    cout << "Cars parked: " << parkingLot.getCarCount() << " | Available spots: " << parkingLot.getAvailableCarSpots() << endl << endl;
    
    // TEST 4: Park a truck
    cout << "TEST 4: Park Truck 1" << endl;
    parkingLot.parkVehicle(&truck1, 150);
    cout << "Trucks parked: " << parkingLot.getTruckCount() << " | Available spots: " << parkingLot.getAvailableTruckSpots() << endl << endl;
    
    // TEST 5: Unpark a bike (successful)
    cout << "TEST 5: Unpark Bike 1 (exit time: 200)" << endl;
    parkingLot.unparkvehicle(&bike1, 200);
    cout << "Bikes parked after unpark: " << parkingLot.getBikeCount() << " | Available spots: " << parkingLot.getAvailablebikeSpots() << endl << endl;
    
    // TEST 6: Park the same bike again (reuse spot)
    cout << "TEST 6: Park Bike 1 again" << endl;
    parkingLot.parkVehicle(&bike1, 250);
    cout << "Bikes parked: " << parkingLot.getBikeCount() << " | Available spots: " << parkingLot.getAvailablebikeSpots() << endl << endl;
    
    // TEST 7: Try to unpark a vehicle that was never parked
    cout << "TEST 7: Try to unpark Bike 4 (never parked - should show error)" << endl;
    parkingLot.unparkvehicle(&bike4, 300);
    cout << endl;
    
    // TEST 8: Unpark a car
    cout << "TEST 8: Unpark Car 1 (exit time: 180)" << endl;
    parkingLot.unparkvehicle(&car1, 180);
    cout << "Cars parked after unpark: " << parkingLot.getCarCount() << " | Available spots: " << parkingLot.getAvailableCarSpots() << endl << endl;
    
    // TEST 9: Park multiple vehicles of different types
    cout << "TEST 9: Park multiple vehicles at once" << endl;
    parkingLot.parkVehicle(&bike5, 400);
    parkingLot.parkVehicle(&car2, 410);
    parkingLot.parkVehicle(&truck2, 420);
    cout << "Summary: Bikes=" << parkingLot.getBikeCount() << " Cars=" << parkingLot.getCarCount() 
         << " Trucks=" << parkingLot.getTruckCount() << endl << endl;
    
    // TEST 10: Unpark all and check final counts
    cout << "TEST 10: Unpark all remaining vehicles" << endl;
    parkingLot.unparkvehicle(&bike2, 500);
    parkingLot.unparkvehicle(&bike3, 510);
    parkingLot.unparkvehicle(&bike1, 520);
    parkingLot.unparkvehicle(&bike5, 530);
    parkingLot.unparkvehicle(&car2, 540);
    parkingLot.unparkvehicle(&truck1, 550);
    parkingLot.unparkvehicle(&truck2, 560);
    cout << "Final counts: Bikes=" << parkingLot.getBikeCount() << " Cars=" << parkingLot.getCarCount() 
         << " Trucks=" << parkingLot.getTruckCount() << endl << endl;
    
    cout << "========== ALL TESTS COMPLETED ==========" << endl;
    cout << "Vehicles created successfully!" << endl;
// string comp, string mod, int yr, string t, string numPl
}
    
