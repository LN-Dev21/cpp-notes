//
// Created by jay_211 on 25-7-30.
//

#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <string>
using namespace std;
class Animal {
public:
    Animal() = default;
    Animal(const char* name) : _name(name) {}
    Animal(const string& name) : _name(name) {}
    Animal(const Animal& animal) : _name(animal._name) {}
    virtual void speak() const {
        cout << "Animal " << _name << " 叫" << endl;
    }
protected:
    string _name = "animal";
};
class Dog : public Animal {
public:
    Dog() = default;
    Dog(const char* name) : Animal(name) {}
    Dog(const string& name) : Animal(name) {}
    Dog(const Dog& dog) : Animal(dog) {}
    void speak() const {
        cout << _name << "正在汪汪汪" << endl;
    }
};
class smallDog : public Dog {
public:
    smallDog() = default;
    smallDog(const char* name) : Dog(name) {}
    smallDog(const string& name) : Dog(name) {}
    smallDog(const smallDog& smallDog) : Dog(smallDog) {}
    void speak() const {
        cout << _name << "正在小声汪汪汪" << endl;
    }
};
class Cat : public Animal {
public:
    Cat() = default;
    Cat(const char* name) : Animal(name) {}
    Cat(const string& name) : Animal(name) {}
    Cat(const Cat& cat) : Animal(cat) {}
    virtual void speak() const {
        cout <<  _name << "正在喵喵喵" << endl;
    }
    void destructor(){}
};
void hear(const Animal& animal) {
    animal.speak();
}
#endif //ANIMAL_H
