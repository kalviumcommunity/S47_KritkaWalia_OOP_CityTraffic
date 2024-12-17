#include <iostream>
#include <string>

using namespace std;

// Class 1: Vehicle
class Vehicle {
private:
    string type;      // Private data member for the vehicle type
    int speed;        // Private data member for the vehicle speed

    // Static variable to track the number of Vehicle instances
    static int vehicleCount;

public:
    // Constructor to initialize vehicle attributes and increment count
    Vehicle(string t, int s) : type(t), speed(s) {
        vehicleCount++; // Increment count when a new Vehicle object is created
    }

    // Destructor to decrement count when a Vehicle object is destroyed
    ~Vehicle() {
        vehicleCount--; // Decrement count when a Vehicle object is deleted
    }

    // Accessor (Getter) for 'type'
    string getType() const {
        return type;
    }

    // Mutator (Setter) for 'type' with input validation
    void setType(const string& t) {
        if (!t.empty()) { // Ensure the type is not an empty string
            type = t;
        } else {
            cout << "Invalid type. Type cannot be empty.\n";
        }
    }

    // Accessor (Getter) for 'speed'
    int getSpeed() const {
        return speed;
    }

    // Mutator (Setter) for 'speed' with input validation
    void setSpeed(int s) {
        if (s >= 0) { // Ensure the speed is non-negative
            speed = s;
        } else {
            cout << "Speed cannot be negative.\n";
        }
    }

    // Function to display the details of the vehicle
    void displayDetails() const {
        cout << "Vehicle Type: " << type << "\n";
        cout << "Speed: " << speed << " km/h\n";
    }

    // Function to accelerate the vehicle by a given increment
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

// Initialize the static variable for Vehicle count
int Vehicle::vehicleCount = 0;

// Class 2: TrafficLight
class TrafficLight {
private:
    string color;     // Private data member for the traffic light color

    // Static variable to track the number of TrafficLight instances
    static int lightCount;

public:
    // Constructor to initialize the traffic light color and increment count
    TrafficLight(string c) : color(c) {
        lightCount++; // Increment count when a new TrafficLight object is created
    }

    // Destructor to decrement count when a TrafficLight object is destroyed
    ~TrafficLight() {
        lightCount--; // Decrement count when a TrafficLight object is deleted
    }

    // Accessor (Getter) for 'color'
    string getColor() const {
        return color;
    }

    // Mutator (Setter) for 'color' with input validation
    void setColor(const string& c) {
        if (c == "Red" || c == "Yellow" || c == "Green") { // Ensure color is valid
            color = c;
        } else {
            cout << "Invalid color. Use 'Red', 'Yellow', or 'Green'.\n";
        }
    }

    // Function to change the color of the traffic light
    void changeColor(string newColor) {
        setColor(newColor); // Call setColor for validation
        cout << "Traffic light changes to " << color << ".\n";
    }

    // Function to display the current color of the traffic light
    void showColor() const {
        cout << "Current Traffic Light Color: " << getColor() << "\n";
    }

    // Static function to display the total number of TrafficLight instances
    static void displayLightCount() {
        cout << "Total Traffic Lights: " << lightCount << "\n";
    }
};

// Initialize the static variable for TrafficLight count
int TrafficLight::lightCount = 0;

int main() {
    // Dynamic memory allocation for a Vehicle object
    Vehicle* car = new Vehicle("Car", 60);
    car->displayDetails(); // Display initial vehicle details

    // Update vehicle type and speed using setters
    car->setType("Sports Car");
    car->setSpeed(80);
    cout << "Updated Vehicle Details:\n";
    car->displayDetails();

    // Accelerate the vehicle
    car->accelerate(20);

    // Display total number of Vehicle instances
    Vehicle::displayVehicleCount();

    cout << "\n";

    // Dynamic memory allocation for a TrafficLight object
    TrafficLight* light = new TrafficLight("Red");
    light->showColor(); // Display initial traffic light color

    // Change the traffic light color using the setter
    light->setColor("Yellow");
    light->showColor();

    // Change the traffic light color using the changeColor function
    light->changeColor("Green");

    // Display total number of TrafficLight instances
    TrafficLight::displayLightCount();

    cout << "\n";

    // Free allocated memory
    delete car;   // Delete Vehicle object
    delete light; // Delete TrafficLight object

    // Display counts after deletion
    Vehicle::displayVehicleCount();
    TrafficLight::displayLightCount();

    return 0; // End of the program
}
