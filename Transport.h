#ifndef TRANSPORT_H_INCLUDED
#define TRANSPORT_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class Transport {  
    protected:
        string id;
        string type;

    public:
        Transport(string i, string t) {
            id = i;
            type = t;
        }

        string getID() const { return id; }

        string getType() const { return type; }  

        virtual void display() const = 0;

        virtual int getPassengerCapacity() const = 0;

        virtual double getCargoCapacity() const = 0;
};

class Land : public Transport {
    private:
        int passenger;
        double cargo;

    public:
        Land(string i, string t, int p, double c) : Transport(i, t) {
            passenger = p;
            cargo = c;
        }

    // Use override to override base class method in derived class
    // (GeeksforGeeks, 2024)

        void display() const override {
            cout << "ID             : " << id << endl;
            cout << "Type           : " << type << endl;
            cout << "# of Passenger : " << passenger << " people" << endl;
            cout << "Cargo Capacity : " << cargo << " kg" << endl;
            cout << endl;
        }

        int getPassengerCapacity() const { return passenger; }

        double getCargoCapacity() const { return cargo; }
};

class Water : public Transport {
    private:
        int passenger;
        double cargo;

    public:
        Water(string i, string t, int p, double c) : Transport(i, t) {
            passenger = p;
            cargo = c;
        }

        void display() const override {
            cout << "ID             : " << id << endl;
            cout << "Type           : " << type << endl;
            cout << "# of Passenger : " << passenger << " people" << endl;
            cout << "Cargo Capacity : " << cargo << " kg" << endl;
            cout << endl;
        }

        int getPassengerCapacity() const { return passenger; }

        double getCargoCapacity() const { return cargo; }
};

class Air : public Transport {
    private:
        int passenger;
        double cargo;

    public:
        Air(string i, string t, int p, double c) : Transport(i, t) {
            passenger = p;
            cargo = c;
        }

        void display() const override {
            cout << "ID             : " << id << endl;
            cout << "Type           : " << type << endl;
            cout << "# of Passenger : " << passenger << " people" << endl;
            cout << "Cargo Capacity : " << cargo << " kg" << endl;
            cout << endl;
        }

        int getPassengerCapacity() const { return passenger; }

        double getCargoCapacity() const { return cargo; }
};

#endif // TRANSPORT_H_INCLUDED