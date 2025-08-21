//
// Created by jay_211 on 25-7-31.
//

#ifndef BSTREE_H
#define BSTREE_H
#include <iostream>
#include <string>
using namespace std;

namespace key {
    template<typename K>
    struct BSTNode {
        K _key;
        BSTNode<K> *_left;
        BSTNode<K> *_right;
        BSTNode() = default;
        explicit BSTNode(const K& key)
            : _key(key), _left(nullptr), _right(nullptr)
        {}
    };
    template<typename K>
    class BSTree {
        using Node = BSTNode<K>;
    public:
        bool insert(const K& key) {
            if (_root == nullptr) {
                _root = new Node(key);
                return true;
            }
            Node* parent = nullptr;
            Node* cur = _root;
            while (cur) {
                if (key > cur->_key) {
                    parent = cur;
                    cur = cur ->_right;
                }
                else if (key < cur->_key) {
                    parent = cur;
                    cur = cur->_left;
                }
                else return false;
            }
            cur = new Node(key);
            if (key > parent->_key) parent->_right = cur;
            else parent->_left = cur;
            return true;
        }

        bool find(const K& key) const {
            if (_root == nullptr) return false;
            Node* cur = _root;
            while (cur) {
                if (key > cur->_key) cur = cur->_right;
                else if (key < cur->_key) cur = cur->_left;
                else return true;
            }
            return false;
        }

        bool erase(const K& key) {
            if (_root == nullptr) return false;
            Node* parent = nullptr;
            Node* cur = _root;

            while (cur) {
                if (key > cur->_key) {
                    parent = cur;
                    cur = cur->_right;
                }
                else if (key < cur->_key) {
                    parent = cur;
                    cur = cur->_left;
                }
                // 找到节点
                else { // 0~1个孩子
                    if (cur->_left == nullptr) {
                        if (parent == nullptr) _root = cur->_right;
                        else if (parent->_right == cur) parent->_right = cur->_right;
                        else parent->_left = cur->_right;
                        delete cur;
                    }
                    else if (cur->_right == nullptr) {
                        if (parent == nullptr) _root = cur->_left;
                        else if (parent->_right == cur) parent->_right = cur->_left;
                        else parent->_left = cur->_left;
                        delete cur;
                    }
                    // 2个孩子
                    else {
                        // 用右子树最左节点替换
                        Node* replaceP = cur;
                        Node* replace = cur->_right;
                        while(replace->_left) {
                            replaceP = replace;
                            replace = replace->_left;
                        }
                        cur->_key = replace->_key;
                        if (replaceP->_left == replace) replaceP->_left = replace->_right;
                        if (replaceP->_right == replace) replaceP->_right = replace->_right;
                        delete replace;
                    }
                    return true;
                }
            }
            return false;
        }

        void inOrder() {
            _inOrder(_root);
            std::cout << std::endl;
        }
        void preOrder() {
            _preOrder(_root);
            std::cout << std::endl;
        }
        void postOrder() {
            _postOrder(_root);
            std::cout << std::endl;
        }
    private:
        void _inOrder(Node* root) {
            if (root == nullptr) return;
            _inOrder(root->_left);
            std::cout << root->_key << " ";
            _inOrder(root->_right);
        }
        void _preOrder(Node* root) {
            if (root == nullptr) return;
            std::cout << root->_key << " ";
            _preOrder(root->_left);
            _preOrder(root->_right);
        }
        void _postOrder(Node* root) {
            if (root == nullptr) return;
            _postOrder(root->_left);
            _postOrder(root->_right);
            std::cout << root->_key << " ";
        }
        Node* _root =  nullptr;
    };
}


namespace key_value {
    template<typename K, typename V>
    struct BSTNode {
        // pair<K, V> _kv;
        K _key;
        V _value;
        BSTNode *_left;
        BSTNode *_right;
        BSTNode() = default;
        BSTNode(const K& key, const V& value)
            : _key(key), _value(value), _left(nullptr), _right(nullptr)
        {}
    };
    template<typename K, typename V>
    class BSTree {
        using Node = BSTNode<K, V>;
    public:
        BSTree() = default;
        BSTree(const BSTree& tree) {
            _root = _copy(tree._root);
        }
        ~BSTree() {
            _destroy(_root);
            _root = nullptr;
        }
        BSTree& operator=(BSTree tmp) {
            swap(_root, tmp._root);
            return *this;
        }
        bool insert(const K& key, const V& value) {
            if (_root == nullptr) {
                _root = new Node(key, value);
                return true;
            }
            Node* parent = nullptr;
            Node* cur = _root;
            while (cur) {
                if (key > cur->_key) {
                    parent = cur;
                    cur = cur ->_right;
                }
                else if (key < cur->_key) {
                    parent = cur;
                    cur = cur->_left;
                }
                else return false;
            }
            cur = new Node(key, value);
            if (key > parent->_key) parent->_right = cur;
            else parent->_left = cur;
            return true;
        }

        Node* find(const K& key) const {
            Node* cur = _root;
            while (cur) {
                if (key > cur->_key) cur = cur->_right;
                else if (key < cur->_key) cur = cur->_left;
                else return cur;
            }
            return nullptr;
        }

        bool erase(const K& key) {
            if (_root == nullptr) return false;
            Node* parent = nullptr;
            Node* cur = _root;

            while (cur) {
                if (key > cur->_key) {
                    parent = cur;
                    cur = cur->_right;
                }
                else if (key < cur->_key) {
                    parent = cur;
                    cur = cur->_left;
                }
                // 找到节点
                else { // 0~1个孩子
                    if (cur->_left == nullptr) {
                        if (parent == nullptr) _root = cur->_right;
                        else if (parent->_right == cur) parent->_right = cur->_right;
                        else parent->_left = cur->_right;
                        delete cur;
                    }
                    else if (cur->_right == nullptr) {
                        if (parent == nullptr) _root = cur->_left;
                        else if (parent->_right == cur) parent->_right = cur->_left;
                        else parent->_left = cur->_left;
                        delete cur;
                    }
                    // 2个孩子
                    else {
                        // 用右子树最左节点替换
                        Node* replaceP = cur;
                        Node* replace = cur->_right;
                        while(replace->_left) {
                            replaceP = replace;
                            replace = replace->_left;
                        }
                        cur->_key = replace->_key;
                        if (replaceP->_left == replace) replaceP->_left = replace->_right;
                        if (replaceP->_right == replace) replaceP->_right = replace->_right;
                        delete replace;
                    }
                    return true;
                }
            }
            return false;
        }

        void inOrder() {
            _inOrder(_root);
            std::cout << std::endl;
        }
        void preOrder() {
            _preOrder(_root);
            std::cout << std::endl;
        }
        void postOrder() {
            _postOrder(_root);
            std::cout << std::endl;
        }
    private:
        Node* _copy(Node* root) {
            if (root == nullptr) return nullptr;
            Node* node = new Node(root->_key, root->_value);
            node->_left = _copy(root->_left);
            node->_right = _copy(root->_right);
            return node;
        }
        void _destroy(Node* root) {
            if (root == nullptr) {
                return ;
            }
            _destroy(root->_left);
            _destroy(root->_right);
            delete root;
        }
        void _inOrder(Node* root) {
            if (root == nullptr) return;
            _inOrder(root->_left);
            std::cout << root->_key << "->" << root->_value << std::endl;

            _inOrder(root->_right);
        }
        void _preOrder(Node* root) {
            if (root == nullptr) return;
            std::cout << root->_key << "->" << root->_value << std::endl;

            _preOrder(root->_left);
            _preOrder(root->_right);
        }
        void _postOrder(Node* root) {
            if (root == nullptr) return;
            _postOrder(root->_left);
            _postOrder(root->_right);
            std::cout << root->_key << "->" << root->_value << std::endl;
        }
        Node* _root =  nullptr;
    };
}

#endif //BSTREE_H
