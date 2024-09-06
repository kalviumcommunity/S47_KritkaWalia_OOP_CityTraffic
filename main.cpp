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
    Vehicle car("Car", 60);
    car.displayDetails();
    car.accelerate(20);

    cout << "\n";

    TrafficLight light("Red");
    light.showColor();
    light.changeColor("Green");

    return 0;
}