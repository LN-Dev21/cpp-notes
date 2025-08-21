//
// Created by jay_211 on 25-7-13.
//
#ifndef VECTOR_H
#define VECTOR_H

#include <cassert>
#include <iostream>
#include <algorithm>
#include <string>
#include <list>
using namespace std;

namespace jay {
    template<typename T>
    class vector {
    public:
        typedef T* iterator;
        typedef const T* const_iterator;

        vector() = default; // C++11 默认构造

        vector(const int n, const T& val = T()) {
            reserve(n);
            for (int i = 0; i < n; ++i) {
                push_back(val);
            }
        }

        vector(const vector& v) {
            reserve(v.size());
            for (auto& e : v) {
                push_back(e);
            }
        }

        template<class InputIterator>
        vector(InputIterator first, InputIterator last) {
            while (first != last) {
                push_back(*first);
                ++first;
            }
        }

        vector(initializer_list<T> v) {
            for (auto& e: v) {
                push_back(e);
            }
        }

        ~vector() {
            if (_start != nullptr) {
                delete[] _start;
                _start = _finish = _end_of_storage = nullptr;
            }
        }

        iterator begin() {return _start;}
        iterator end() {return _finish;}
        const_iterator begin() const {return _start;}
        const_iterator end() const {return _finish;}


        void reserve(size_t  n) {
            if (n > capacity()) {
                size_t old_size = size();
                T* tmp = new T[n];
                // memcpy(tmp, _start, size() * sizeof(T)); // 浅拷贝
                for (size_t i = 0; i < old_size; ++i) {
                    tmp[i] = _start[i];
                }
                delete[] _start;
                _start = tmp;
                _finish = tmp + old_size;
                _end_of_storage = _start + n;
            }
        }

        void resize(size_t n, const T& val = T()) {
            if (n < size()) {
                _finish = _start + n;
            }
            else {
                reserve(n);
                while (_finish < _start + n) {
                    *_finish = val;
                    ++_finish;
                }
            }
        }

        size_t size() const {return _finish - _start;}

        size_t capacity() const {return _end_of_storage - _start;}

        bool empty() {return _start == _finish;}

        void push_back(const T& val) {
            if (_finish == _end_of_storage) reserve(capacity() == 0 ? 4 : capacity() * 2);
            *_finish = val;
            ++_finish;
        }

        void pop_back() {
            assert(!empty());
            --_finish;
        }

        /**
         * 扩容导致内存重新分配
         * 原内存释放导致_start\_finish\_end_of_storage指针重新指向新的内存
         * 参数 pos 指向原来的位置
         * 但原来的位置已经释放 相当于野指针
         * 因此需要重新计算pos
         */
        iterator insert(iterator pos, const T& val) {
            assert(pos >= _start && pos <= _finish);
            int ipos = pos - _start;
            if (_finish == _end_of_storage) reserve(capacity() == 0 ? 4 : capacity() * 2);
            pos = _start + ipos;
            iterator end = _finish -1;
            while (end >= pos) {
                *(end+1) = *end;
                --end;
            }
            *pos = val;
            ++_finish;
            return pos;
        }

        void erase(iterator pos) {
            assert(pos >= _start && pos <= _finish);
            iterator it = pos + 1;
            while (it != _finish) {
                *(it - 1) = *it;
                ++it;
            }
            --_finish;
        }

        void clear() {
            _finish = _start;
        }

        T& operator[](size_t i) const {
            assert(i < size());
            return *(_start + i);
        }

        void swap(vector& v) {
            std::swap(_start,v._start);
            std::swap(_finish,v._finish);
            std::swap(_end_of_storage,v._end_of_storage);
        }

        vector& operator=(vector v) {
            swap(v);
            return *this;
        }

    private:
        iterator _start = nullptr; // 指向第一个元素
        iterator _finish = nullptr; // 指向最后一个元素的下一个位置
        iterator _end_of_storage = nullptr; // 指向存储空间末尾
    };
    template<typename T>
    void print(const vector<T>& v) {
        /**
         * typename vector<T>::const_iterator it = v.begin();
         * 没有实例化的类模板里面取东西
         * 编译器不能区分const_iterator是类型还是静态成员变量
         * 需要加上typename
         */
        auto it = v.begin();
        while (it != v.end()) {
            cout << *it << " ";
            ++it;
        }
        cout << endl;
        for (int i = 0; i < v.size(); ++i) {
            cout << v[i] << " ";
        }
        cout << endl;
        for (const auto& i: v) {
            cout << i << " ";
        }
        cout << endl;
    }
}

#endif //VECTOR_H
