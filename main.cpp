#include <iostream>
#include <string>

using namespace std;

// Class 1: Vehicle
class Vehicle {
private:
    string type;  // Private data member for the vehicle type
    int speed;    // Private data member for the vehicle speed

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
        if (!t.empty()) { // Validation to ensure non-empty input
            type = t;
        } else {
            cout << "Invalid type. Type cannot be empty.\n";
        }
    }

    // Accessor for 'speed'
    int getSpeed() const {
        return speed;
    }

    // Mutator for 'speed'
    void setSpeed(int s) {
        if (s >= 0) { // Validation to ensure positive speed
            speed = s;
        } else {
            cout << "Speed cannot be negative.\n";
        }
    }

    // Display the details of the vehicle
    void displayDetails() const {
        cout << "Vehicle Type: " << type << "\n";
        cout << "Speed: " << speed << " km/h\n";
    }

    // Accelerate the vehicle
    void accelerate(int increment) {
        if (increment > 0) {
            speed += increment;
            cout << type << " accelerates by " << increment << " km/h.\n";
        } else {
            cout << "Acceleration increment must be positive.\n";
        }
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
    string color;  // Private data member for the traffic light color

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
        if (c == "Red" || c == "Yellow" || c == "Green") { // Validation for valid colors
            color = c;
        } else {
            cout << "Invalid color. Use 'Red', 'Yellow', or 'Green'.\n";
        }
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

    // Use mutators to update type and speed
    car->setType("Sports Car");
    car->setSpeed(80);
    cout << "Updated Vehicle Details:\n";
    car->displayDetails();

    // Accelerate the vehicle
    car->accelerate(20);

    // Display the total number of Vehicle instances
    Vehicle::displayVehicleCount();

    cout << "\n";

    // Dynamic memory allocation for a TrafficLight
    TrafficLight* light = new TrafficLight("Red");
    light->showColor();

    // Use mutator to change the color
    light->setColor("Yellow");
    light->showColor();

    // Change the color using the changeColor function
    light->changeColor("Green");

    // Display the total number of TrafficLight instances
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
