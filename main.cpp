#include <iostream>
#include <string>

using namespace std;

// Base Class: Vehicle
class Vehicle {
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

    // Destructor
    ~Vehicle() {
        vehicleCount--;
    }

    void displayDetails() const {
        cout << "Vehicle Type: " << type << "\n";
        cout << "Speed: " << speed << " km/h\n";
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

    void displayCarDetails() const {
        displayDetails();
        cout << "Number of Doors: " << doors << "\n";
    }
};

// Derived Class 2: Bike (Hierarchical Inheritance)
class Bike : public Vehicle {
private:
    bool hasCarrier;

public:
    // Constructor
    Bike(string t, int s, bool c) : Vehicle(t, s), hasCarrier(c) {}

    void displayBikeDetails() const {
        displayDetails();
        cout << "Has Carrier: " << (hasCarrier ? "Yes" : "No") << "\n";
    }
};

// Base Class: TrafficLight
class TrafficLight {
private:
    string color;

    static int lightCount;

public:
    // Default Constructor
    TrafficLight() : color("Red") {
        lightCount++;
    }

    // Parameterized Constructor
    TrafficLight(string c) : color(c) {
        lightCount++;
    }

    // Destructor
    ~TrafficLight() {
        lightCount--;
    }

    void showColor() const {
        cout << "Traffic Light Color: " << color << "\n";
    }

    static void displayLightCount() {
        cout << "Total Traffic Lights: " << lightCount << "\n";
    }
};

int TrafficLight::lightCount = 0;

// Derived Class: SmartTrafficLight (Single Inheritance)
class SmartTrafficLight : public TrafficLight {
private:
    bool sensorEnabled;

public:
    // Constructor
    SmartTrafficLight(string c, bool s) : TrafficLight(c), sensorEnabled(s) {}

    void displaySmartLightDetails() const {
        showColor();
        cout << "Sensor Enabled: " << (sensorEnabled ? "Yes" : "No") << "\n";
    }
};

int main() {
    // Demonstrating Single and Hierarchical Inheritance with Vehicle
    cout << "Creating a Car (Single Inheritance):\n";
    Car car1("Sports Car", 180, 2);
    car1.displayCarDetails();

    cout << "\nCreating a Bike (Hierarchical Inheritance):\n";
    Bike bike1("Mountain Bike", 45, true);
    bike1.displayBikeDetails();

    Vehicle::displayVehicleCount();

    cout << "\n";

    // Demonstrating Single Inheritance with TrafficLight
    cout << "Creating a Smart Traffic Light (Single Inheritance):\n";
    SmartTrafficLight smartLight1("Green", true);
    smartLight1.displaySmartLightDetails();

    TrafficLight::displayLightCount();

    return 0;
}
git 