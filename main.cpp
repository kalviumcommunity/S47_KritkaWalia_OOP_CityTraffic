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

    // Parameterized Constructor (Constructor Overloading)
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

    // Parameterized Constructor (Constructor Overloading)
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
    // Demonstrating Constructor Overloading in Vehicle
    cout << "Creating Vehicles:\n";
    Vehicle v1;  // Default Constructor
    v1.displayDetails();

    Vehicle v2("Car", 80);  // Parameterized Constructor
    v2.displayDetails();

    Vehicle::displayVehicleCount();
    cout << "\n";

    // Demonstrating Single Inheritance with Car
    cout << "Creating a Car (Single Inheritance):\n";
    Car car1("Sedan", 120, 4);
    car1.displayCarDetails();
    cout << "\n";

    // Demonstrating Hierarchical Inheritance with Bike
    cout << "Creating a Bike (Hierarchical Inheritance):\n";
    Bike bike1("Road Bike", 50, true);
    bike1.displayBikeDetails();
    cout << "\n";

    // Display Vehicle Count
    Vehicle::displayVehicleCount();
    cout << "\n";

    // Demonstrating Constructor Overloading in TrafficLight
    cout << "Creating Traffic Lights:\n";
    TrafficLight t1;  // Default Constructor
    t1.showColor();

    TrafficLight t2("Green");  // Parameterized Constructor
    t2.showColor();

    TrafficLight::displayLightCount();
    cout << "\n";

    // Demonstrating Single Inheritance with SmartTrafficLight
    cout << "Creating a Smart Traffic Light (Single Inheritance):\n";
    SmartTrafficLight smartLight1("Yellow", true);
    smartLight1.displaySmartLightDetails();

    TrafficLight::displayLightCount();

    return 0;
}
