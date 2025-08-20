#ifndef FLEET_H_INCLUDED
#define FLEET_H_INCLUDED

#include "Transport.h"
#include <vector>
#include <stdexcept> // (Apache STDCXX, n.d.)
#include <iostream>
#include <algorithm>

using namespace std;

// Use auto to iterate through vector:
// (R/cpp_questions, 2018)

class Fleet {
    private:
        vector<Transport*> vehicles;

    public:
        ~Fleet() {
            for (auto& vehicle : vehicles) {
                delete vehicle;
            }
        }

        void addVehicle(Transport* vehicle) {
            vehicles.push_back(vehicle);
        }

        void displayAvailableVehicles() const {
            cout << endl << "== AVAILABLE VEHICLES ==" << endl;
            for (const auto& vehicle : vehicles) {
                vehicle->display();
            }
        }

        Transport* findVehicle(const string& id) const {
            for (const auto& vehicle : vehicles) {
                if (vehicle->getID() == id) {
                    return vehicle;
                }
            }
            throw runtime_error("Vehicle not found!");
        }

        vector<Transport*> findVehiclesByType(const string& type) const {
            vector<Transport*> result;
            for (const auto& vehicle : vehicles) {
                if (vehicle->getType() == type) {
                    result.push_back(vehicle);
                }
            }
            return result;
        }

        vector<Transport*> assignVehiclesByPassengers(const vector<Transport*>& availableVehicles, int passengers) {
            vector<Transport*> bookedVehicles;
            int remainingPassengers = passengers;

            for (auto vehicle : availableVehicles) {
                if (remainingPassengers <= 0) break;
                int capacity = vehicle->getPassengerCapacity();
                if (capacity > 0) {
                    bookedVehicles.push_back(vehicle);
                    remainingPassengers -= capacity;
                }
            }

            if (remainingPassengers > 0) {
                throw runtime_error("Not enough vehicles to accommodate all passengers!");
            }

            for (auto vehicle : bookedVehicles) {
                removeVehicle(vehicle);
            }

            return bookedVehicles;
        }

        vector<Transport*> assignVehiclesByCargo(const vector<Transport*>& availableVehicles, double cargo) {
            vector<Transport*> bookedVehicles;
            double remainingCargo = cargo;

            for (auto vehicle : availableVehicles) {
                if (remainingCargo <= 0) break;
                double capacity = vehicle->getCargoCapacity();
                if (capacity > 0) {
                    bookedVehicles.push_back(vehicle);
                    remainingCargo -= capacity;
                }
            }

            if (remainingCargo > 0) {
                throw runtime_error("Not enough vehicles to accommodate all cargo!");
            }

            for (auto vehicle : bookedVehicles) {
                removeVehicle(vehicle);
            }

            return bookedVehicles;
        }

        void removeVehicle(Transport* vehicle) {
            vehicles.erase(remove(vehicles.begin(), vehicles.end(), vehicle), vehicles.end());
        }

        // This is basically the list of the vehicles.
        void addInitialVehicles() {
            addVehicle(new Car("C1", 5, 200));
            addVehicle(new Lorry("L1", 2, 5000));
            addVehicle(new Boat("B1", 10, 2000));
            addVehicle(new Ship("S1", 50, 100000));
            addVehicle(new Plane("P1", 150, 20000));
            addVehicle(new Helicopter("H1", 5, 1000));
        }
};

#endif // FLEET_H_INCLUDED
