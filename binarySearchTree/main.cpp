#include "bsTree.h"

// int main() {
//     key_value::BSTree<string, string> dict;
//     dict.insert("left", "左边");
//     dict.insert("right", "右边");
//     dict.insert("up", "上边");
//     dict.insert("down", "下边");
//
//     string str;
//     while (cin >> str) {
//         auto ret = dict.find(str);
//         if (ret) {
//             cout << "->" << ret->_value << endl;
//         }
//         else {
//             cout << "无此单词，请重新输入" << endl;
//         }
//     }
//     return 0;
// }
int main() {
    string str[] = {"苹果","西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜","苹果",
    "香蕉", "苹果","香蕉"};
    key_value::BSTree<string, int> countTree;
    for (const auto& e : str) {
        auto ret = countTree.find(e);
        if (ret ==  nullptr) countTree.insert(e,1);
        else ++ret->_value;
    }
    countTree.inOrder();
    key_value::BSTree<string, int> countTree2 = countTree;

    countTree2.inOrder();
    return 0;
}