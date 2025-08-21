#include <iostream>
#include <vector>
#include "vector.h"
using namespace std;

void vectorExpand() {
    vector<int> vi;
    vi.reserve(50);
    vi.reserve(25);
    size_t sz = vi.capacity();
    cout << "capacity changed " << sz << endl;

    cout << "making vi grow" << endl;
    for (int i = 0; i < 100; i++) {
        vi.push_back(i);
        if (sz != vi.capacity()) {
            sz = vi.capacity();
            cout << "capacity changed " << sz << endl;
        }
    }
}
void test1() {
    vector<int> v1;
    vector<int> v2(10,1);
    vector<int> v3(v2.begin()+1,v2.end()-1);

    for (const int i : v3) {
        cout << i << " ";
    }
    cout << endl;

    for(const auto i : v3) {
        cout << i << " ";
    }
    cout << endl;
    auto it = v3.begin();
    while (it != v3.end()) {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
}
void test2() {
    vector<int> v(10,1);
    v.reserve(20);
    cout << v.size() << endl;
    cout << v.capacity() << endl;

    v.resize(15,2);
    cout << v.size() << endl;
    cout << v.capacity() << endl;

    v.resize(25,3);
    cout << v.size() << endl;
    cout << v.capacity() << endl;

    v.resize(5);
    cout << v.size() << endl;
    cout << v.capacity() << endl;
}
void test3() {
    vector<int> v(10,1);
    v.push_back(2);
    v.insert(v.begin(),0);
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}
void test4() {
    vector<string> v {"hi","hello","world","c++", "c"};
    vector<vector<string>> vv(5,v);

    for(auto & i : vv) {
        for (const auto & j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}
void test5() {
    jay::vector<int> v;
    jay::vector<int> v1;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    auto v2 = v;
    v1 = v2;
    jay::print(v1);
}
void test6() {
    string str = "hello world";
    jay::vector<char> v(str.begin()+1,str.end()-1);
    jay::print(v);

    cout << endl;

    list<int> l {1,2,3,4,5};

    jay::vector<int> v1(l.begin(),l.end());
    jay::print(v1);
}
void test7() {
    jay::vector<int> v(10,1);
    jay::print(v);
}
void test8() {
    jay::vector<string> v;
    v.push_back("1111111111111111");
    v.push_back("1111111111111111");
    v.push_back("1111111111111111");
    v.push_back("1111111111111111");
    v.push_back("1111111111111111");
    for (auto s: v) {
        cout << s << " ";
    }
}
void test9() {
    jay::vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    jay::print(v);
}
int main() {
    test9();
    return 0;
}