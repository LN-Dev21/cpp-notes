#include "animal.h"
#include "buyTicket.h"
#include "car.h"
#include <iostream>
using namespace std;
class Base {
public:
    virtual void func1() { cout << "Base::func1" << endl; }
    virtual void func2() { cout << "Base::func2" << endl; }
    void func5() { cout << "Base::func5" << endl; }
protected:
    int a = 1;
};
class Derive : public Base
{
public:
    // 重写基类的func1
    virtual void func1() { cout << "Derive::func1" << endl; }
    virtual void func3() { cout << "Derive::func1" << endl; }
    void func4() { cout << "Derive::func4" << endl; }
protected:
    int b = 2;
};
int main()
{
    int i = 0;
    static int j = 1;
    int* p1 = new int;
    const char* p2 = "xxxxxxxx";
    printf("栈:%p\n", &i);
    printf("静态区:%p\n", &j);
    printf("堆:%p\n", p1);
    printf("常量区:%p\n", p2);
    Base b;
    Derive d;
    Base* p3 = &b;
    Derive* p4 = &d;
    printf("Person虚表地址:%p\n", *(int*)p3);
    printf("Student虚表地址:%p\n", *(int*)p4);
    printf("虚函数地址:%p\n", &Base::func1);
    printf("普通函数地址:%p\n", &Base::func5);
    return 0;
}