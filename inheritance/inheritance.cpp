//
// Created by jay_211 on 25-7-29.
//
#include "inheritance.h"
int Person::_count = 0;
void Display(const Person &p, const Student &s) {
    cout << p._name << endl;
    cout << s._stuId << endl;
}