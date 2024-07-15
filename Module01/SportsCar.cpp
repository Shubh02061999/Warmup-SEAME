#include <iostream>
#include <string>

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
};

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
};

int main() {
    // Create a Car object
    Car car1("Toyota", "Camry", 2023);
    car1.drive();
    std::cout << std::endl;

    // Create a SportsCar object
    SportsCar sportsCar1("Ferrari", "488 GTB", 2022, 330.0);
    sportsCar1.drive();
    std::cout << std::endl;

    return 0;
}
