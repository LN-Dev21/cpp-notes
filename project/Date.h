//
// Created by jay_211 on 25-7-1.
//

#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <vector>
using namespace std;

namespace date {

    class Date {
    private:
        int _year;
        int _month;
        int _day;
    public:
        //无参构造
        Date():_year(0),_month(0),_day(0){}
        //构造函数
        Date(int year, int month, int day):_year(year),_month(month),_day(day){}

        void print() const;

        Date operator+(int day) const;
        //前置++
        Date operator++();
        //后置++
        Date operator++(int);
        friend ostream& operator<<(ostream& out, const Date& date);
    };
}



#endif //DATE_H
