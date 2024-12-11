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
    // Constructor to initialize vehicle attributes and increment count
    Vehicle(string t, int s) : type(t), speed(s) {
        vehicleCount++;
    }

    // Destructor to decrement count when a Vehicle is destroyed
    ~Vehicle() {
        vehicleCount--;
    }

    // Display the details of the vehicle
    void displayDetails() {
        cout << "Vehicle Type: " << type << "\n";
        cout << "Speed: " << speed << " km/h\n";
    }

    void accelerate(int increment) {
        speed += increment;
        cout << type << " accelerates by " << increment << " km/h.\n";
    }

    // Static function to display the total number of Vehicle instances
    static void displayVehicleCount() {
        cout << "Total Vehicles: " << vehicleCount << "\n";
    }
};

// Initialize the static variable
int Vehicle::vehicleCount = 0;

// Class 2: TrafficLight
class TrafficLight {
private:
    string color;  

    // Static variable to track the number of TrafficLight instances
    static int lightCount;

public:
    // Constructor to initialize the color and increment count
    TrafficLight(string c) : color(c) {
        lightCount++;
    }

    // Destructor to decrement count when a TrafficLight is destroyed
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

    // Static function to display the total number of TrafficLight instances
    static void displayLightCount() {
        cout << "Total Traffic Lights: " << lightCount << "\n";
    }
};

// Initialize the static variable
int TrafficLight::lightCount = 0;

int main() {
    // Dynamic memory allocation for a Vehicle
    Vehicle* car = new Vehicle("Car", 60);
    car->displayDetails();
    car->accelerate(20);

    Vehicle::displayVehicleCount();

    cout << "\n";

    // Dynamic memory allocation for a TrafficLight
    TrafficLight* light = new TrafficLight("Red");
    light->showColor();
    light->changeColor("Green");

    // Display the current count of TrafficLight instances
    TrafficLight::displayLightCount();

    cout << "\n";

    // Freeing allocated memory
    delete car;
    delete light;

    // Display the counts after deletion
    Vehicle::displayVehicleCount();
    TrafficLight::displayLightCount();

    return 0;
}
