#include "inheritance.h"

int main() {
    // Student s1;
    // Student s2(s1);
    // Student s3("Jay","02110053","香港特别行政区");
    // s1 = s3;
    // Assistant a;
    // cout << a._count << endl;

    class Base1 {
    public:
        int _b1;
    };
    class Base2 {
    public:
        int _b2;
    };
    class Derive : public Base1, public Base2 {
    public:
        int _d;
    };


    Derive d;
    Base1* p1 = &d;
    Base2* p2 = &d;
    Derive* p3 = &d;
    // return 0;
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;
    return 0;
}