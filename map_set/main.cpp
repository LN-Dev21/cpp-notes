#include <iostream>
#include <map>
#include <set>
#include <vector>
#include "AVLTree.h"
using namespace std;
void TestAVLTree1(){
    AVLTree<int, int> t;
    // 常规的测试用例
    int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
    // 特殊的带有双旋场景的测试用例
    //int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };

    for (auto e : a){
        t.insert({ e, e });
    }

    t.inOrder();
    cout << t.isBalanceTree() << endl;
}

// 插入一堆随机值，测试平衡，顺便测试一下高度和性能等
void TestAVLTree2(){
    const int N = 1000000;
    vector<int> v;
    v.reserve(N);
    srand(time(0));
    for (size_t i = 0; i < N; i++) {
        v.push_back(rand() + i);
    }

    size_t begin2 = clock();
    AVLTree<int, int> t;
    for (auto e : v) {
        t.insert(make_pair(e, e));
    }
    size_t end2 = clock();

    cout << "insert:" << end2 - begin2 << endl;
    cout << t.isBalanceTree() << endl;

    cout << "height:" << t.height() << endl;
    cout << "size:" << t.size() << endl;

    size_t begin1 = clock();
    // 确定在的值
    for (auto e : v) {
        t.find(e);
    }
    // 随机值
    // for (size_t i = 0; i < N; i++)
    // {
    //     t.find((rand() + i));
    // }
    size_t end1 = clock();
    cout << "find:" << end1 - begin1 << endl;
}


int main(){
    TestAVLTree2();
    return 0;
}