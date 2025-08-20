#include "Transport.h"
#include "Options.h"
#include "Fleet.h"
#include "Client.h"
#include <iostream>

using namespace std;

int main() {
    Fleet fleet;
    fleet.addInitialVehicles();

    cout << "Welcome to Universal Transports Booking System!" << endl;

    string name;
    cout << "Enter your name: ";
    getline(cin, name); // Program won't read \0 if we don't use getline

    string contact;
    cout << "Enter your contact number: ";
    getline(cin, contact);

    Client client(name, contact);

    while (true) {
        cout << endl << "== MENU ==" << endl;
        cout << "1. Display available vehicles" << endl;
        cout << "2. Book a vehicle" << endl;
        cout << "3. Add a new vehicle" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        try {
            switch (choice) {
                case 1:
                    fleet.displayAvailableVehicles();
                    break;
                case 2:
                    client.bookVehicle(fleet);
                    break;
                case 3: {
                    string confirmation;
                    cout << "Are you a staff member? (y/n): ";
                    cin >> confirmation;


                    if(confirmation == "y") {
                        string type;
                        cout << "Enter vehicle type (Car, Lorry, Boat, Ship, Plane, Helicopter): ";
                        cin >> type;

                        string id;
                        cout << "Enter vehicle ID: ";
                        cin >> id;

                        int passengerCapacity;
                        cout << "Enter passenger capacity: ";
                        cin >> passengerCapacity;

                        double cargoCapacity;
                        cout << "Enter cargo capacity (in kg): ";
                        cin >> cargoCapacity;

                        if (type == "Car") {
                            fleet.addVehicle(new Car(id, passengerCapacity, cargoCapacity));
                        } else if (type == "Lorry") {
                            fleet.addVehicle(new Lorry(id, passengerCapacity, cargoCapacity));
                        } else if (type == "Boat") {
                            fleet.addVehicle(new Boat(id, passengerCapacity, cargoCapacity));
                        } else if (type == "Ship") {
                            fleet.addVehicle(new Ship(id, passengerCapacity, cargoCapacity));
                        } else if (type == "Plane") {
                            fleet.addVehicle(new Plane(id, passengerCapacity, cargoCapacity));
                        } else if (type == "Helicopter") {
                            fleet.addVehicle(new Helicopter(id, passengerCapacity, cargoCapacity));
                        } else {
                            throw runtime_error("Invalid vehicle type!");
                        }
                        cout << "Vehicle added successfully!\n";
                        break;
                    } else if(confirmation == "n") {
                        cout << "This system is intended to be used by the staff." << endl;
                        break;
                    }
                }
                case 4:
                    cout << "Thank you for using Universal Transports Booking System!\n";
                    return 0;
                default:
                    throw runtime_error("Invalid choice! Please try again.");
            }
        } catch (const runtime_error& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    return 0;
}
