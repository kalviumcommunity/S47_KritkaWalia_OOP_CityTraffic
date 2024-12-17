#include <iostream>
#include <string>

using namespace std;

// Class 1: Vehicle
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

// Class 2: TrafficLight
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

int main() {
    // Using the Default Constructor for Vehicle
    Vehicle v1;
    cout << "Vehicle created using Default Constructor:\n";
    v1.displayDetails();

    // Using the Parameterized Constructor for Vehicle
    Vehicle v2("Car", 60);
    cout << "\nVehicle created using Parameterized Constructor:\n";
    v2.displayDetails();

    Vehicle::displayVehicleCount();

    cout << "\n";

    // Using the Default Constructor for TrafficLight
    TrafficLight t1;
    cout << "Traffic Light created using Default Constructor:\n";
    t1.showColor();

    // Using the Parameterized Constructor for TrafficLight
    TrafficLight t2("Green");
    cout << "\nTraffic Light created using Parameterized Constructor:\n";
    t2.showColor();

    TrafficLight::displayLightCount();

    return 0;
}
