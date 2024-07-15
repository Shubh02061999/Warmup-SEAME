#include <iostream>
#include <memory>
#include <vector>

// Manually implement make_unique for C++11 compatibility
namespace std {
template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}
}

// Base class
class Part {
public:
    virtual void print() = 0; // Pure virtual function to be overridden by derived classes
    virtual ~Part() = default;
};

class Engine : public Part {
public:
    void print() override {
        std::cout << "Engine part\n";
    }
};

class Wheel : public Part {
public:
    void print() override {
        std::cout << "Wheel part\n";
    }
};

class Brake : public Part {
public:
    void print() override {
        std::cout << "Brake part\n";
    }
};

class Transmission : public Part {
public:
    void print() override {
        std::cout << "Transmission part\n";
    }
};

class Car {
public:
    Car() {
        engine_ = std::make_unique<Engine>();
        for (int i = 0; i < 4; ++i) {
            wheels_.push_back(std::make_unique<Wheel>());
            brakes_.push_back(std::make_unique<Brake>());
        }
        transmission_ = std::make_unique<Transmission>();
    }

    void printParts() {
        engine_->print();
        for (const auto& wheel : wheels_) {
            wheel->print();
        }
        for (const auto& brake : brakes_) {
            brake->print();
        }
        transmission_->print();
    }

private:
    std::unique_ptr<Engine> engine_;
    std::vector<std::unique_ptr<Wheel> > wheels_; // Add space between angle brackets
    std::vector<std::unique_ptr<Brake> > brakes_; // Add space between angle brackets
    std::unique_ptr<Transmission> transmission_;
};

int main() {
    Car myCar;
    myCar.printParts();

    return 0;
}
