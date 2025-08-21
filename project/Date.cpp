// Date.cpp
// Created by jay_211 on 25-7-1.

#include "Date.h"

namespace date {

    void Date::print() const {
        std::cout << _year << "-" << _month << "-" << _day << std::endl;
    }

    Date Date::operator+(int day) const {
        Date date;
        date._year = _year;
        date._month = _month;
        date._day = _day + day;
        return date;
    }

    Date Date::operator++() {
        ++_day;
        return *this;
    }

    Date Date::operator++(int) {
        Date temp = *this;
        ++_day;
        return temp;
    }

    // 定义友元函数 operator<<
    ostream& operator<<(ostream& os, const Date& date) {
        os << date._year << "-" << date._month << "-" << date._day;
        return os;
    }

} // namespace date
