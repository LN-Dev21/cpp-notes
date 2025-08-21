//
// Created by jay_211 on 25-7-22.
//

#ifndef STACK_H
#define STACK_H

namespace jay {
    template<typename T, typename Container = deque<T>>
    class stack {
    public:
        void push(const T& x) {_con.push_back(x);}
        void pop(){_con.pop_back();}
        const T& top() const {return _con.back();}
        size_t size() const {return _con.size();}
        bool empty() const {return _con.empty();}

    private: Container _con;
    };
}
#endif //STACK_H
