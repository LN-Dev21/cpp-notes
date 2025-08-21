//
// Created by jay_211 on 25-7-27.
//

#ifndef INHERITANCE_H
#define INHERITANCE_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 前向声明
class Student;
class Teacher;

class Person {
public:
    friend void Display(const Person& p, const Student& s);
    Person(const char* name = "peter")
        :_name(name){
        ++_count;
    }
    Person(const Person& p)
        :_name(p._name) {
        ++_count;
    }
    Person& operator=(const Person& p) {
        if (this != &p) _name = p._name;
        return *this;
    }
    ~Person() {
        --_count;
    }

public:
    string _name;
    static int _count;
};

class Student : virtual public Person {
public:
    friend void Display(const Person& p, const Student& s);
    Student() = default;
    Student(const char* name, const char* stuId, const char* address)
        : Person(name),
        _stuId(stuId),
        _address(address) {
    }
// 实际上编译器默认生成的拷贝构造就是下面这个
// 深拷贝时才需要自己写
// Student(const Student& s) : Person(s),
//     _stuId(s._stuId),
//     _address(s._address) {
// }

    Student& operator=(const Student& s) {
        if (this != &s) {
            Person::operator=(s);
            _stuId = s._stuId;
            _address = s._address;
        }
        return *this;
    }

protected:
    string _stuId = "2023005756";
    string _address = "台湾省台北市";
};

class Teacher : virtual public Person {
public:
    Teacher() = default;
    Teacher(const char* name, const char* title)
        : Person(name),
        _title(title)
    {}
protected:
    string _title;
};

class Assistant : public Teacher, public Student {
public:
    Assistant() = default;

    Assistant(const char *name, const char* title, const char* stuId, const char *address)
        : Teacher(name,title),
        Student(name, stuId, address) {
    }
protected:
    int _num;
};
namespace jay {
    template<typename T>
    class stack : public vector<T> {
    public:
        void push(const T& x) {
            this->push_back(x);
        }
        void pop() {
            this->pop_back();
        }
        const T& top() const {
            return vector<T>::back();
        }
        bool empty() const {
            return vector<T>::empty();
        }
    };
}

#endif //INHERITANCE_H
