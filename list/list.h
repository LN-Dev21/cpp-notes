//
// Created by jay_211 on 25-7-14.
//

#ifndef LIST _H
#define LIST_H
#include <cinttypes>
#include <iterator>
using namespace std;
namespace jay {
    // 链表节点
    template<typename T>
    struct list_node {
        T _data;
        list_node *_next;
        list_node *_prev;

        list_node(const T& data = T())
            : _data(data)
            , _next(nullptr)
            , _prev(nullptr)
        {}
    };
    // 普通迭代器
    template<typename T, typename Ref, typename Ptr>
    struct list_iterator {
        typedef list_node<T> Node;
        typedef list_iterator Self;
        Node* _node;

        list_iterator(Node* node)
            : _node(node)
        {}

        Self& operator++() {
            _node = _node->_next;
            return *this;
        }
        Self& operator--() {
            _node = _node->_prev;
            return *this;
        }
        Self operator++(int) {
            Self tmp(*this);
            _node = _node->_next;
            return tmp;
        }
        Self operator--(int) {
            Self tmp(*this);
            _node = _node->_prev;
            return tmp;
        }
        bool operator==(const Self& s) const {return _node == s._node;}
        bool operator!=(const Self& s) const {return _node != s._node;}
        Ref operator*() const {return _node->_data;}
        Ptr operator->() const {return &_node->_data;}
    };

    // 链表
    template<typename T>
    class list {
        typedef list_node<T> Node;
    public:
        typedef list_iterator<T, T&, T*> iterator;
        typedef list_iterator<T, const T&, const T*> const_iterator;

        iterator begin() const {return Head->_next;}
        iterator end() const {return Head;}
        const_iterator cbegin() const {return Head->_next;}
        const_iterator cend() const {return Head;}

        void empty_init() {
            Head = new Node;
            Head->_next = Head;
            Head->_prev = Head;
            _size = 0;
        }
        list() {
            empty_init();
        }
        list(const list& lt) {
            empty_init();
            for (auto& e : lt) {
                push_back(e);
            }
        }
        template<typename InputIterator>
        list(InputIterator first, InputIterator last) {
            Head = new Node;
            Head->_next = Head;
            Head->_prev = Head;
            _size = 0;
            while (first != last) {
                push_back(*first);
                ++first;
            }
        }
        list(initializer_list<T> il) {
            empty_init();
            for (auto& e: il) {
                push_back(e);
            }
        }
        ~list() {
            clear();
            delete Head;
            Head = nullptr;
        }

        list& operator=(list tmp) {
            swap(tmp);
            return *this;
        }

        void swap(list<int>& lt) {
            std::swap(Head, lt.Head);
            std::swap(_size, lt._size);
        }

        void push_back(const T& data) {insert(end(), data);}

        iterator insert(iterator pos, const T& x) {
            Node* node = new Node(x);
            Node* cur = pos._node;
            Node* prev = cur->_prev;

            node->_next = cur;
            node->_prev = prev;
            cur->_prev = node;
            prev->_next = node;

            ++_size;
            return node;
        }

        void push_front(const T& data){ insert(begin(), data);}

        iterator erase(iterator pos) {
            if (pos != end()) {
                Node* prev = pos._node->_prev;
                Node* next = pos._node->_next;
                prev->_next = next;
                next->_prev = prev;
                delete pos._node;
                --_size;
                return next;
            }
            std::cout << "error: list::erase()" << std::endl;
            return end();
        }

        void pop_front() {
            if (_size) {
                erase(begin());
            }else {
                std::cout << "error: list::pop_front()" << std::endl;
            }
        }

        void pop_back() {
            if (_size) {
                erase(--end());
            }else {
                std::cout << "error: list::pop_back()" << std::endl;
            }
        }
        void clear() {
            auto it = begin();
            while (it != end()) {
                it = erase(it); // ++it，erase(it)后，it会失效（野指针），所以不能直接++it
            }
            _size = 0;
        }
        size_t size() const{return _size;}
        bool empty() const{return _size == 0;}

    private:
        Node* Head = nullptr;
        size_t _size = 0;
    };

    template<typename Container>
    void print_container(const Container& con) {
        for (auto e : con) {
            cout << e << " ";
        }
        cout << endl;
    }

    inline void test1() {
        vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        const list<int> l(v.begin()+3, v.end()-3);
        print_container(l);
    }
    inline void test2() {
        vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        list<int> l(v.begin(), v.end());
        list<int>::iterator it = l.begin();
        while (it != l.end()) {
            if (*it % 2) {
                it = l.erase(it);
            }
            else {
                ++it;
            }
        }
        print_container(l);
    }
} // jay

#endif //LIST_H
