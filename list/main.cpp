#include <iostream>
#include <list>
#include <algorithm>
#include <ctime>
#include <vector>
#include "list.h"
using namespace std;
class A {
public:
    A(int _a = 1, int _b = 2)
        : _a(_a), _b(_b) {
        cout << "A(int _a = 1, int _b = 2)" << endl;
    }
    int _a;
    int _b;
    A(const A &a)
        : _a(a._a), _b(a._b)
    {
        cout << "A(const A &a)" << endl;
        _a = a._a;
        _b = a._b;
    }
};
void test0() {
    list<int> li = {1, 2, 3, 4, 5};
    list<double> ld(5, 3.14);
    list<char> lc = {'a', 'b', 'c', 'd', 'e'};
    list<char> lc1(++lc.begin(), --lc.end());
    for (auto c: lc1) {
        cout << c << " ";
    }
}
void test1() {
    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);

    auto it = lt.begin();
    while (it != lt.end()) {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
    for (auto i: lt) {
        cout << i << " ";
    }
}
void test2() {
    list<A> la;
    A aa(1,1);
    la.push_back(aa);
    la.push_back(A(2,2));
    // la.push_back(2,2);

    la.emplace_back(aa);
    la.emplace_back(2,2);

    for (const auto& la1: la) {
        cout << la1._a << " " << la1._b << endl;
    }
}
void test3() {
    list<int> li;
    li.push_back(4);
    li.push_back(3);
    li.push_back(2);
    li.push_back(5);
    li.push_back(1);
    li.reverse();
    for (const auto& i: li) {
        cout << i << " ";
    }
    cout << endl;
    reverse(li.begin(),li.end());
    for (const auto& i: li) {
        cout << i << " ";
    }
    cout << endl;
    li.sort(greater<int> ());
    for (const auto& i: li) {
        cout << i << " ";
    }
}
void test4() {
    list<int> li = {1,5,7,7,7,8,2,2,2,4,4,6,9};
    for (auto i: li) {
        cout << i << " ";
    }
    cout << endl;
    li.sort(greater<int>());
    for (auto i: li) {
        cout << i << " ";
    }
    cout << endl;
    li.unique();
    for (auto i: li) {
        cout << i << " ";
    }
    cout << endl;
}
void test5() {
    list<int> li0 = {88, 99, 100};
    list<int> li1 = {1,2,3,4,5};
    li1.splice(++li1.begin(), li0);
    for (auto i: li1) {
        cout << i << " ";
    }
    cout << endl;
    for (auto i: li0) {
        cout << i << " ";
    }
}
void test6() {
    list<int> li = {1,2,3,4,5};
    li.splice(li.begin(), li, ++++++li.begin(),li.end());
    for (auto i: li) {
        cout << i << " ";
    }
}
void test7() {
    srand(time(nullptr));
    const int N = 1000000;
    list<int> li;
    vector <int> v;

    for (int i = 0; i < N; ++i) {
        auto e = rand() + i;
        li.push_back(e);
        v.push_back(e);
    }

    int beginls = clock();
    li.sort();
    int endls = clock();
    cout << "list sort time: " << endls - beginls << endl;

    int beginv = clock();
    sort(v.begin(), v.end());
    int endv = clock();
    cout << "vector sort time: " << endv - beginv << endl;

}
void test8() {
    jay::list<int> li;
    for (int i = 1; i < 10; ++i) {
        li.push_back(i);
    }
    for (const auto& i: li) {
        cout << i << " ";
    }
    cout << endl;
    jay::list<int>::iterator it = li.begin();
    while (it != li.end()) {
        cout << *it << " ";
        ++it;
    }
}
void test9() {
    jay::list<int> li;
    for (int i = 1; i < 10; ++i) {
        li.push_back(i);
    }
    // jay::list<int>::const_reverse_iterator it = li.crbegin();
    // while (it != li.crend()) {
    //     cout << *it << " ";
    //     ++it;
    // }
    // cout << endl;
    for (auto i: li) {
        cout << i << " ";
    }
    cout << endl;
    jay::print_container(li);

}
void test10() {
    struct A {
        int _a = 1;
        int _b = 2;
    };

    jay::list<A> la;
    la.push_back(A());
    la.push_back(A());
    la.push_back(A());
    la.push_back(A());
    la.push_back(A());
    auto ita = la.begin();
    while (ita != la.end()) {
        cout << ita->_a << " ";
        ++ita;
    }

}
void test11() {
    jay::list<int> ls;
    for (int i = 1; i < 10; ++i) {
        ls.push_back(i);
    }
    jay::list<int>::iterator cit = ls.begin();
    cout << cit._node << endl;
    while (cit != ls.end()) {
        // *cit._node = 0;
        if (cit._node == nullptr) break;
    }
    cout << cit._node;
}
void test12() {
    jay::list<int> ls;
    for (int i = 1; i < 10; ++i) {
        ls.push_back(i);
    }
    jay::list<int>::iterator it = ls.begin();
    while (it != ls.end()) {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
}
void test13() {
    // jay::list<int> lt1({1,2,3,4,5});
    jay::list<int> lt1 = {1,2,3,4,5}; // 隐式类型转换
    //
    // jay::list<int> lt2(lt1);
    // jay::print_container(lt1);
    // jay::print_container(lt2);

    jay::list<int> lt3 = lt1;
    jay::print_container(lt3);
    const jay::list<int>& lt4 = {1,2,3,4,5}; // 隐式类型转换

}
int main() {
    test13();

    return 0;
}