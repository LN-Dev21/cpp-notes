//
// Created by jay_211 on 25-7-30.
//

#ifndef CAR_H
#define CAR_H
#include <string>
#include <iostream>
using namespace std;
class Car {
public:
    virtual void run() const = 0;
    virtual void stop() const = 0;
    Car() = default;
    Car(const Car& car) = default;
    Car(const char* name, const char* carId, const int price, const int speed)
        : _name(name), _carId(carId), _price(price), _speed(speed) {
    }

    virtual ~Car() = default;
protected:
    string _name;
    string _carId;
    int _price = 0;
    int _speed = 0;
};
class Bmw final : public Car {
public:
    Bmw() = default;
    Bmw(const char* name, const char* carId, const int price, const int speed)
        : Car(name, carId, price, speed) {
    }
    Bmw(const Bmw& bmw) = default;
    void run() const override {
        cout << "Bmw is running" << endl;
    }

    void stop() const override {
        cout << "Bmw is stoping" << endl;
    }

    ~Bmw() override = default;
};
class Audi final : public Car {
public:
    Audi() = default;
    Audi(const char* name, const char* carId, const int price, const int speed)
        : Car(name, carId, price, speed) {}
    Audi(const Audi& audi) = default;
    void run() const override {
        cout << "Audi is running" << endl;
    }

    void stop() const override {
        cout << "Audi is stoping" << endl;
    }

    ~Audi() override = default;
};

inline void run(const Car& car) {car.run();}
#endif //CAR_H
