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

    // Accessor for 'type'
    string getType() const {
        return type;
    }

    // Mutator for 'type'
    void setType(const string& t) {
        type = t;
    }

    // Accessor for 'speed'
    int getSpeed() const {
        return speed;
    }

    // Mutator for 'speed'
    void setSpeed(int s) {
        speed = s;
    }

    // Display the details of the vehicle
    void displayDetails() const {
        cout << "Vehicle Type: " << type << "\n";
        cout << "Speed: " << speed << " km/h\n";
    }

    // Accelerate the vehicle
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

    // Accessor for 'color'
    string getColor() const {
        return color;
    }

    // Mutator for 'color'
    void setColor(const string& c) {
        color = c;
    }

    // Change the color of the traffic light
    void changeColor(string newColor) {
        setColor(newColor);
        cout << "Traffic light changes to " << color << ".\n";
    }

    // Show the current color of the traffic light
    void showColor() const {
        cout << "Current Traffic Light Color: " << getColor() << "\n";
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

    // Use the mutator to update speed
    car->setSpeed(80);
    cout << "Updated Speed: " << car->getSpeed() << " km/h\n";

    car->accelerate(20);
    Vehicle::displayVehicleCount();

    cout << "\n";

    // Dynamic memory allocation for a TrafficLight
    TrafficLight* light = new TrafficLight("Red");
    light->showColor();

    // Use the mutator to update color
    light->setColor("Yellow");
    light->showColor();

    light->changeColor("Green");
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
