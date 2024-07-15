#include <iostream>
#include <string>

// Base class
class Car {
protected:
    std::string make;
    std::string model;
    int year;

public:
    // Constructor
    Car(const std::string& make, const std::string& model, int year)
        : make(make), model(model), year(year) {
        std::cout << "Car Constructor called for " << make << " " << model << " " << year << " edition." << std::endl;
    }

    // Destructor
    virtual ~Car() {
        std::cout << "Car Destructor called for " << make << " " << model << " " << year << " edition." << std::endl;
    }

    // Drive function
    virtual void drive() {
        std::cout << "Driving " << make << " " << model << " " << year << " edition." << std::endl;
    }

    // Virtual function for getting car details (abstraction)
    virtual void getCarDetails() const {
        std::cout << "Make: " << make << ", Model: " << model << ", Year: " << year << std::endl;
    }
};

// Derived class
class SportsCar : public Car {
private:
    double topSpeed;

public:
    // Constructor
    SportsCar(const std::string& make, const std::string& model, int year, double topSpeed)
        : Car(make, model, year), topSpeed(topSpeed) {
        std::cout << "SportsCar Constructor called for " << make << " " << model << " " << year << " edition with top speed " << topSpeed << " km/h." << std::endl;
    }

    // Destructor
    ~SportsCar() {
        std::cout << "SportsCar Destructor called for " << make << " " << model << " " << year << " edition." << std::endl;
    }

    // Overridden drive function
    void drive() override {
        std::cout << "Driving " << make << " " << model << " " << year << " edition at top speed " << topSpeed << " km/h." << std::endl;
    }

    // Overridden function for getting car details
    void getCarDetails() const override {
        Car::getCarDetails();
        std::cout << "Top Speed: " << topSpeed << " km/h" << std::endl;
    }
};

// Another derived class to demonstrate polymorphism
class ElectricCar : public Car {
private:
    double batteryCapacity;

public:
    // Constructor
    ElectricCar(const std::string& make, const std::string& model, int year, double batteryCapacity)
        : Car(make, model, year), batteryCapacity(batteryCapacity) {
        std::cout << "ElectricCar Constructor called for " << make << " " << model << " " << year << " edition with battery capacity " << batteryCapacity << " kWh." << std::endl;
    }

    // Destructor
    ~ElectricCar() {
        std::cout << "ElectricCar Destructor called for " << make << " " << model << " " << year << " edition." << std::endl;
    }

    // Overridden drive function
    void drive() override {
        std::cout << "Driving " << make << " " << model << " " << year << " edition with battery capacity " << batteryCapacity << " kWh." << std::endl;
    }

    // Overridden function for getting car details
    void getCarDetails() const override {
        Car::getCarDetails();
        std::cout << "Battery Capacity: " << batteryCapacity << " kWh" << std::endl;
    }
};

int main() {
    // Create a Car object
    Car car1("Toyota", "Camry", 2023);
    car1.drive();
    car1.getCarDetails();
    std::cout << std::endl;

    // Create a SportsCar object
    SportsCar sportsCar1("Ferrari", "488 GTB", 2022, 330.0);
    sportsCar1.drive();
    sportsCar1.getCarDetails();
    std::cout << std::endl;

    // Create an ElectricCar object
    ElectricCar electricCar1("Tesla", "Model S", 2024, 100.0);
    electricCar1.drive();
    electricCar1.getCarDetails();
    std::cout << std::endl;

    // Demonstrating polymorphism
    Car* carPtr;
    carPtr = &sportsCar1;
    carPtr->drive();
    carPtr->getCarDetails();
    std::cout << std::endl;

    carPtr = &electricCar1;
    carPtr->drive();
    carPtr->getCarDetails();
    std::cout << std::endl;

    return 0;
}
