//
// Created by jay_211 on 25-7-25.
//

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <vector>
template<typename T>
    class Less {
public:
    bool operator()(const T& x, const T& y) {
        return x < y;
    }
};
template<typename T>
class Greater {
public:
    bool operator()(const T& x, const T& y) {
        return x > y;
    }
};
namespace jay {
    template<typename T, typename Container = std::vector<T>, typename Compare = Less<T>>
    class priority_queue {
    private:
        void adjustUp(int child) {
            Compare cmp;
            int parent = (child - 1) / 2;
            while (child > 0) {
                if (cmp(_con[child], _con[parent])) {
                    swap(_con[child],_con[parent]);
                    child = parent;
                    parent = (child - 1) / 2;
                }else {
                    break;
                }
            }
        }
        void adjustDown(size_t parent) {
            Compare cmp;
            size_t child = parent * 2 + 1;
            while (child < _con.size()) {
                if (child + 1 < _con.size() && cmp(_con[child+1], _con[child])) {
                    ++child;
                }
                if (cmp(_con[child], _con[parent])) {
                    swap(_con[child],_con[parent]);
                    parent = child;
                    child = parent * 2 + 1;
                }
                else {
                    break;
                }
            }
        }
    public:
        void push(const T& x) {
            _con.push_back(x);
            adjustUp(_con.size()-1);
        }
        void pop() {
            swap(_con[0], _con[_con.size()-1]);
            _con.pop_back();
            adjustDown(0);
        }
        const T& top() const {return _con[0];}
        size_t size() const {return _con.size();}
        bool empty() const {return _con.empty();}
    private:
        Container _con;
    };
}

#endif //PRIORITY_QUEUE_H
