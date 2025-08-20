#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

#include "Fleet.h"
#include <iostream>
#include <vector>

using namespace std;

class Client {
private:
    string name;
    string contact;
    vector<Transport*> bookedVehicles;

public:
    // Constructor 
    Client(string n, string c) {
        name = n;
        contact = c;
    }

    // Book a vehicle from Fleet.h
    void bookVehicle(Fleet& fleet) {
        cout << endl;
        cout << "Enter vehicle type (Car, Lorry, Boat, Ship, Plane, Helicopter): ";
        string type;
        cin >> type;

        cout << endl;
        cout << "Enter booking criteria:" << endl;
        cout << "1. Number of passengers" << endl;
        cout << "2. Cargo capacity" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        vector<Transport*> availableVehicles = fleet.findVehiclesByType(type);

        if (availableVehicles.empty()) {
            cout << "No available vehicles of that type."<< endl;
            return;
        }

        switch (choice) {
            case 1: {
                cout << endl;
                cout << "Enter the number of passengers: ";
                int passengers;
                cin >> passengers;
                try {
                    bookedVehicles = fleet.assignVehiclesByPassengers(availableVehicles, passengers);
                    cout << "Vehicles booked successfully!";
                    printBookingDetails();
                } catch (const runtime_error& e) {
                    cout << "Error: " << e.what() << endl;
                }
                break;
            }
            case 2: {
                cout << "Enter the cargo capacity (kg): ";
                double cargo;
                cin >> cargo;
                try {
                    bookedVehicles = fleet.assignVehiclesByCargo(availableVehicles, cargo);
                    cout << "Vehicles booked successfully!" << endl;
                    printBookingDetails();
                } catch (const runtime_error& e) {
                    cout << "Error: " << e.what() << endl;
                }
                break;
            }
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    // Print booking details
    void printBookingDetails() const {
        cout << endl << "== BOOKING DETAILS ==" << endl;
        cout << "Name           : " << name << endl;
        cout << "Contact        : " << contact << endl;
        for (const auto& vehicle : bookedVehicles) {
            vehicle->display();
        }
    }
};

#endif // CLIENT_H_INCLUDED
