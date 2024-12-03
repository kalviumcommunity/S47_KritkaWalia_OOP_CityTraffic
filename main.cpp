#include <iostream>
#include <string>

using namespace std;

// Class 1: Vehicle
class Vehicle {
private:
    string type;
    int speed;

public:
    Vehicle(string t, int s) : type(t), speed(s) {}

    void displayDetails() {
        cout << "Vehicle Type: " << type << "\n";
        cout << "Speed: " << speed << " km/h\n";
    }

    void accelerate(int increment) {
        speed += increment;
        cout << type << " accelerates by " << increment << " km/h.\n";
    }
};

// Class 2: TrafficLight
class TrafficLight {
private:
    string color;

public:
    TrafficLight(string c) : color(c) {}

    void changeColor(string newColor) {
        color = newColor;
        cout << "Traffic light changes to " << color << ".\n";
    }

    void showColor() {
        cout << "Current Traffic Light Color: " << color << "\n";
    }
};

int main() {
    // Dynamic memory allocation for Vehicle
    Vehicle* car = new Vehicle("Car", 60);
    car->displayDetails();
    car->accelerate(20);

    cout << "\n";

    // Dynamic memory allocation for TrafficLight
    TrafficLight* light = new TrafficLight("Red");
    light->showColor();
    light->changeColor("Green");

    // Freeing allocated memory
    delete car;
    delete light;

    return 0;
}
