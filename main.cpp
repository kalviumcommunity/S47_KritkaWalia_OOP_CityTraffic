#include <iostream>
#include <string>

using namespace std;

// Abstract Base Class: AbstractVehicle
class AbstractVehicle {
public:
    virtual void printDetails() const = 0; // Pure Virtual Function
    virtual ~AbstractVehicle() {}          // Virtual Destructor
};

// Base Class: Vehicle (Inherits AbstractVehicle)
class Vehicle : public AbstractVehicle {
private:
    string type;
    int speed;

    static int vehicleCount;

public:
    // Default Constructor
    Vehicle() : type("Unknown"), speed(0) {
        vehicleCount++;
    }

    // Parameterized Constructor
    Vehicle(string t, int s) : type(t), speed(s) {
        vehicleCount++;
    }

    // Virtual Destructor
    virtual ~Vehicle() {
        vehicleCount--;
    }

    // Virtual Function (Overridden in Derived Classes)
    virtual void displayDetails() const {
        cout << "Vehicle Type: " << type << "\n";
        cout << "Speed: " << speed << " km/h\n";
    }

    // Implementation of Abstract Class Method
    void printDetails() const override {
        displayDetails();
    }

    static void displayVehicleCount() {
        cout << "Total Vehicles: " << vehicleCount << "\n";
    }
};

int Vehicle::vehicleCount = 0;

// Derived Class 1: Car (Single Inheritance)
class Car : public Vehicle {
private:
    int doors;

public:
    // Constructor
    Car(string t, int s, int d) : Vehicle(t, s), doors(d) {}

    // Overriding Virtual Function
    void displayDetails() const override {
        Vehicle::displayDetails();
        cout << "Number of Doors: " << doors << "\n";
    }

    void printDetails() const override {
        displayDetails();
    }
};

// Derived Class 2: Bike (Hierarchical Inheritance)
class Bike : public Vehicle {
private:
    bool hasCarrier;

public:
    // Constructor
    Bike(string t, int s, bool c) : Vehicle(t, s), hasCarrier(c) {}

    // Overriding Virtual Function
    void displayDetails() const override {
        Vehicle::displayDetails();
        cout << "Has Carrier: " << (hasCarrier ? "Yes" : "No") << "\n";
    }

    void printDetails() const override {
        displayDetails();
    }
};

int main() {
    // Demonstrating Abstract Class and Virtual Functions
    cout << "Demonstrating Abstract Class and Virtual Function:\n";

    // Creating an array of AbstractVehicle pointers
    AbstractVehicle* vehicles[2];

    // Assigning Car and Bike objects
    vehicles[0] = new Car("Sedan", 120, 4);
    vehicles[1] = new Bike("Mountain Bike", 45, true);

    // Using Polymorphism
    for (int i = 0; i < 2; i++) {
        vehicles[i]->printDetails();
        cout << "\n";
    }

    // Cleaning up memory
    for (int i = 0; i < 2; i++) {
        delete vehicles[i];
    }

    return 0;
}
