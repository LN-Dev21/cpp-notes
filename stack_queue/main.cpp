#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <queue>
#include <stack>
using namespace std;
#include "priority_queue.h"
#include "stack.h"
#include "queue.h"

template<typename T1, typename T2>
class Data {

};
template<typename T1, typename T2>
class Data<T1*,T2*> {

};
int main() {
    array<int, 5> arr = {1, 2, 3, 4, 5};
    arr.at(4) = 10;
    for (auto value: arr) {
        cout << value << " ";
    }

    return 0;
}
