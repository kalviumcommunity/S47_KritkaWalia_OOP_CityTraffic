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

    // Dynamic memory allocation for Vehicle
    Vehicle* car = new Vehicle("Car", 60);
    car->displayDetails();
    car->accelerate(20);


    // Dynamic memory allocation for TrafficLight
    TrafficLight* light = new TrafficLight("Red");
    light->showColor();
    light->changeColor("Green");

    // Freeing allocated memory
    delete car;
    delete light;


    return 0;
}
