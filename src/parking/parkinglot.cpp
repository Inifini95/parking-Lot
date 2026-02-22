#include "parkinglot.hpp"
#include<string.h>
int ParkingLot::getAvailablebikeSpots() {
    return 100 - bikeCount;
}
int ParkingLot::getAvailableCarSpots() {
    return 100 - carCount;
}
int ParkingLot::getAvailableTruckSpots() {
    return 100 - truckCount;
}

void ParkingLot::parkVehicle(Vehicle *v, int time)
{
    if(v->getType() == "Bike")
    {
        cout<<"Bike hai"<<endl;
        if(getAvailablebikeSpots()>0)
        {
            int i=0;
            for(i=0;i<bikeParking.size();i++)
            {
                if(bikeParking[i]==nullptr)
                {
                    break;
                }
            } 
            cout<<"parking number is "<<i+1<<endl;
            bikeParking[i] = v;
            bikeCount++;
            Ticket *ticket = new Ticket(time, "Bike", i+1,  v->getNumPlate());

        }
        else
        {
            cout<<"parking for Bike is full!!";
        }
    }
    else if(v->getType() == "Car")
    {
        if(getAvailableCarSpots()>0)
        {
            int i=0;
            for(i=0;i<carParking.size();i++)
            {
                if(carParking[i]==nullptr)
                {
                    break;
                }
            } 
            cout<<"parking number is "<<i+1<<endl;
            carParking[i] = v;
            carCount++;
            Ticket *ticket = new Ticket(time, "Car", i+1,  v->getNumPlate());

        }
        else
        {
            cout<<"parking for Car is full!!";
        }
    }
    else if(v->getType() == "Truck")
    {
        if(getAvailableTruckSpots()>0)
        {
            int i=0;
            for(i=0;i<truckParking.size();i++)
            {
                if(truckParking[i]==nullptr)
                {
                    break;
                }
            } 
            cout<<"parking number is "<<i+1<<endl;
            truckParking[i]=v;
            truckCount++;
            Ticket *ticket = new Ticket(time, "Truck", i+1,  v->getNumPlate());

        }
        else
        {
            cout<<"parking for Truck is full!!";
        }
    }
}

void ParkingLot::unparkvehicle(Vehicle *v, int outTime)
{
    // Note: findTicket should be a static method or we need to fix this logic
    // For now, this is commented to get compilation working
    // Ticket *ticket = Ticket::findTicket(v->getNumPlate());
    cout<<v->getNumPlate()<<endl;
    Ticket *ticket = Ticket::findTicket(v->getNumPlate());
    if(ticket == nullptr)
    {
        cout<<"vehicle not parked here"<<endl;
        return;
    }
    else{
        if(ticket->getType() == "Bike")
        {
            bikeParking[ticket->getSpotId()-1] = nullptr;
            bikeCount--;
        }
        else if(ticket->getType() == "Car")
        {
            carParking[ticket->getSpotId()-1] = nullptr;
            carCount --;
        }
        else
        {
            truckParking[ticket->getSpotId()-1]= nullptr;
            truckCount--;
        }
        delete ticket;
    }
    
}