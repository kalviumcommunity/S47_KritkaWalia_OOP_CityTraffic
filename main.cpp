#include <iostream>
#include <string>

using namespace std;

// Class 1: Vehicle
class Vehicle {
private:
    string type;
    int speed;

    // Static variable to track the number of Vehicle instances
    static int vehicleCount;

public:
    Vehicle(string t, int s) : type(t), speed(s) {
        vehicleCount++;
    }

    ~Vehicle() {
        vehicleCount--;
    }

    void displayDetails() {
        cout << "Vehicle Type: " << type << "\n";
        cout << "Speed: " << speed << " km/h\n";
    }

    void accelerate(int increment) {
        speed += increment;
        cout << type << " accelerates by " << increment << " km/h.\n";
    }

    // Static function to access the static variable
    static void displayVehicleCount() {
        cout << "Total Vehicles: " << vehicleCount << "\n";
    }
};

int Vehicle::vehicleCount = 0; // Initialize static variable

// Class 2: TrafficLight
class TrafficLight {
private:
    string color;

    // Static variable to track the number of TrafficLight instances
    static int lightCount;

public:
    TrafficLight(string c) : color(c) {
        lightCount++;
    }

    ~TrafficLight() {
        lightCount--;
    }

    void changeColor(string newColor) {
        color = newColor;
        cout << "Traffic light changes to " << color << ".\n";
    }

    void showColor() {
        cout << "Current Traffic Light Color: " << color << "\n";
    }

    // Static function to access the static variable
    static void displayLightCount() {
        cout << "Total Traffic Lights: " << lightCount << "\n";
    }
};

int TrafficLight::lightCount = 0; // Initialize static variable

int main() {
    // Dynamic memory allocation for Vehicle
    Vehicle* car = new Vehicle("Car", 60);
    car->displayDetails();
    car->accelerate(20);

    // Display vehicle count
    Vehicle::displayVehicleCount();

    cout << "\n";

    // Dynamic memory allocation for TrafficLight
    TrafficLight* light = new TrafficLight("Red");
    light->showColor();
    light->changeColor("Green");

    // Display traffic light count
    TrafficLight::displayLightCount();

    cout << "\n";

    // Freeing allocated memory
    delete car;
    delete light;

    // Display counts after deletion
    Vehicle::displayVehicleCount();
    TrafficLight::displayLightCount();

    return 0;
}