#ifndef TICKET_H
#define TICKET_H

#include<stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Ticket
{
    private:
    int parkingTime;
    string vehicleType;
    int parkingSpotId;
    string numberPlate;
    static unordered_map<string,Ticket*> ticketList;
    static int ticketCount;

    public:
    Ticket(int time, string vType, int spotId, string numPlate) : parkingTime(time), vehicleType(vType), parkingSpotId(spotId), numberPlate(numPlate) {
        ticketList.insert({numPlate, this});
        ticketCount++;
    }
    ~Ticket()
    {
        ticketList.erase(numberPlate);
        ticketCount--;
    }
    void displayTicketInfo() {
        cout << "Parking Time: " << parkingTime << endl;
        cout << "Vehicle Type: " << vehicleType << endl;
        cout << "Parking Spot ID: " << parkingSpotId << endl;
        cout << "Number Plate: " << numberPlate << endl;
    }
    static Ticket* findTicket(string numplate)
    {
        if(ticketList.find(numplate)==ticketList.end())
        {
            return nullptr;
        }
        else
        {
            return ticketList[numplate];
        }
    }

    string getType()
    {
        return vehicleType;
    }

    int getSpotId()
    {
        return parkingSpotId;
    }


};

#endif