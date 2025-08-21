//
// Created by jay_211 on 25-8-13.
//

#ifndef AVLTREE_H
#define AVLTREE_H
#include <cassert>
#include <utility>
using namespace std;
template<class K, class V>
struct AVLTreeNode {
	// 需要parent指针，后续更新平衡因子可以看到
	pair<K, V> _kv;
	AVLTreeNode* _left;
	AVLTreeNode* _right;
	AVLTreeNode* _parent;

	int _bf; // balance factor

	AVLTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
	{}
};

template<class K, class V>
class AVLTree {
	typedef AVLTreeNode<K, V> Node;
public:
	bool insert(const pair<K, V>& kv) {
		if (_root == nullptr) {
			_root = new Node(kv);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur) {
			if (cur->_kv.first < kv.first) {
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first) {
				parent = cur;
				cur = cur->_left;
			}
			else {
				return false;
			}
		}

		cur = new Node(kv);
		if (parent->_kv.first < kv.first) {
			parent->_right = cur;
		}
		else {
			parent->_left = cur;
		}
		// 链接父亲
		cur->_parent = parent;

		// 控制平衡
		// 更新平衡因子
		while (parent)
		{
			if (cur == parent->_left)parent->_bf--;
			else parent->_bf++;

			if (parent->_bf == 0) break;
			else if (parent->_bf == 1 || parent->_bf == -1) {
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2) {
				if (parent->_bf == -2 && cur->_bf == -1)
					RotateR(parent);
				else if (parent->_bf == 2 && cur->_bf == 1)
					RotateL(parent);
				else if (parent->_bf == -2 && cur->_bf == 1)
					RotateLR(parent);
				else if (parent->_bf == 2 && cur->_bf == -1)
					RotateRL(parent);
				else assert(false);

				break;
			}
			else assert(false);

		}
		return true;
	}
	void inOrder(){
		_InOrder(_root);
		cout << endl;
	}

	int height(){
		return _Height(_root);
	}

	int size(){
		return _Size(_root);
	}

	bool isBalanceTree(){
		return _IsBalanceTree(_root);
	}

	Node* find(const K& key){
		Node* cur = _root;
		while (cur){
			if (cur->_kv.first < key)cur = cur->_right;
			else if (cur->_kv.first > key)cur = cur->_left;
			else return cur;
		}
		return nullptr;
	}
private:
	void RotateR(Node* parent) {
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if(subLR) subLR->_parent = parent;

		Node* pParent = parent->_parent;

		subL->_right = parent;
		parent->_parent = subL;

		if (parent == _root) {
			_root = subL;
			subL->_parent = nullptr;
		}
		else {
			if (pParent->_left == parent) {
				pParent->_left = subL;
			}
			else{
				pParent->_right = subL;
			}

			subL->_parent = pParent;
		}

		subL->_bf = 0;
		parent->_bf = 0;
	}

	void RotateL(Node* parent){
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL) subRL->_parent = parent;

		Node* parentParent = parent->_parent;
		subR->_left = parent;
		parent->_parent = subR;

		if (parentParent == nullptr){
			_root = subR;
			subR->_parent = nullptr;
		}
		else{
			if (parent == parentParent->_left){
				parentParent->_left = subR;
			}
			else{
				parentParent->_right = subR;
			}
			subR->_parent = parentParent;
		}

		parent->_bf = subR->_bf = 0;
	}

	void RotateLR(Node* parent){
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;

		RotateL(parent->_left);
		RotateR(parent);

		if (bf == -1){
			subLR->_bf = 0;
			subL->_bf = 0;
			parent->_bf = 1;
		}
		else if (bf == 1){
			subLR->_bf = 0;
			subL->_bf = -1;
			parent->_bf = 0;
		}
		else if (bf == 0){
			subLR->_bf = 0;
			subL->_bf = 0;
			parent->_bf = 0;
		}
		else assert(false);
	}

	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		int bf = subRL->_bf;
		RotateR(parent->_right);
		RotateL(parent);

		if (bf == 0){
			subR->_bf = 0;
			subRL->_bf = 0;
			parent->_bf = 0;
		}
		else if (bf == 1){
			subR->_bf = 0;
			subRL->_bf = 0;
			parent->_bf = -1;
		}
		else if (bf == -1){
			subR->_bf = 1;
			subRL->_bf = 0;
			parent->_bf = 0;
		}
		else assert(false);

	}

	void _InOrder(Node* root){
		if (root == nullptr) return;

		_InOrder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_InOrder(root->_right);
	}

	int _Height(Node* root){
		if (root == nullptr) return 0;

		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);
		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}

	int _Size(Node* root){
		if (root == nullptr)return 0;

		return _Size(root->_left) + _Size(root->_right) + 1;
	}

	bool _IsBalanceTree(Node* root){
		// 空树也是AVL树
		if (nullptr == root)
			return true;
		// 计算pRoot结点的平衡因子：即pRoot左右子树的高度差
		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);
		int diff = rightHeight - leftHeight;

		// 如果计算出的平衡因子与pRoot的平衡因子不相等，或者
		// pRoot平衡因子的绝对值超过1，则一定不是AVL树
		if (abs(diff) >= 2){
			cout << root->_kv.first << "高度差异常" << endl;
			return false;
		}
		if (root->_bf != diff){
			cout << root->_kv.first << "平衡因子异常" << endl;
			return false;
		}
		return _IsBalanceTree(root->_left) && _IsBalanceTree(root->_right);
	}
private:
	Node* _root = nullptr;
};
#endif //AVLTREE_H
