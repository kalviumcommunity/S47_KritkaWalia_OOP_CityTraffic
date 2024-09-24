#include <iostream>
#include <string>

using namespace std;

// Class 1: Vehicle
class Vehicle {
private:
    string type;
    int speed;

public:
    Vehicle(string type, int speed) {
        this->type = type;
        this->speed = speed;
    }

    void displayDetails() {
        cout << "Vehicle Type: " << this->type << "\n";
        cout << "Speed: " << this->speed << " km/h\n";
    }

    void accelerate(int increment) {
        this->speed += increment;
        cout << this->type << " accelerates by " << increment << " km/h.\n";
    }
};

// Class 2: TrafficLight
class TrafficLight {
private:
    string color;

public:
    TrafficLight(string color) {
        this->color = color;
    }

    void changeColor(string newColor) {
        this->color = newColor;
        cout << "Traffic light changes to " << this->color << ".\n";
    }

    void showColor() {
        cout << "Current Traffic Light Color: " << this->color << "\n";
    }
};

int main() {
    Vehicle vehicles[3] = {
        Vehicle("Car", 60),
        Vehicle("Bus", 50),
        Vehicle("Bike", 80)
    };

    for(int i = 0; i < 3; i++) {
        vehicles[i].displayDetails();
        vehicles[i].accelerate(10);
        cout << "\n";
    }

    TrafficLight lights[2] = {
        TrafficLight("Red"),
        TrafficLight("Green")
    };

    for(int i = 0; i < 2; i++) {
        lights[i].showColor();
        lights[i].changeColor("Yellow");
        cout << "\n";
    }

    return 0;
}
