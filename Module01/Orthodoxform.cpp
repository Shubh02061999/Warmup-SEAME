#include <iostream>
#include <string>

class Car {
private:
    std::string name;
    double speed; // Assuming speed is in km/h

public:
    // Constructor
    Car(const std::string& n, double s) : name(n), speed(s) {
        std::cout << "Constructor called for " << name << std::endl;
    }

    // Copy constructor
    Car(const Car& other) : name(other.name), speed(other.speed) {
        std::cout << "Copy constructor called for " << name << std::endl;
    }

    // Copy assignment operator
    Car& operator=(const Car& other) {
        std::cout << "Copy assignment operator called for " << other.name << std::endl;
        if (this != &other) {
            name = other.name;
            speed = other.speed;
        }
        return *this;
    }

    // Destructor
    ~Car() {
        std::cout << "Destructor called for " << name << std::endl;
    }

    // Getter for name
    std::string getName() const {
        return name;
    }

    // Getter for speed
    double getSpeed() const {
        return speed;
    }
};

// Example usage in main function
int main() {
    // Create a Car object using the constructor
    Car car1("Toyota Camry", 120.5);

    // Use copy constructor to create car2 from car1
    Car car2 = car1;

    // Use copy assignment operator
    Car car3("Honda Civic", 100.0);
    car3 = car1;

    // Output the details of cars
    std::cout << "Car 1: " << car1.getName() << ", Speed: " << car1.getSpeed() << " km/h" << std::endl;
    std::cout << "Car 2: " << car2.getName() << ", Speed: " << car2.getSpeed() << " km/h" << std::endl;
    std::cout << "Car 3: " << car3.getName() << ", Speed: " << car3.getSpeed() << " km/h" << std::endl;

    return 0;
}
