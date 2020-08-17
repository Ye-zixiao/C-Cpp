#include<iostream>
#include<string>
#include<memory>
using namespace::std;

class TreeNode {
public:
	TreeNode(const string& str = string()) :
		value(str), count(new size_t(1)), left(nullptr), right(nullptr) {}
	TreeNode(const TreeNode& item) :
		value(item.value), count(item.count), left(item.left), right(item.right) {
		++* item.count;
	}
	~TreeNode() {
		if (-- * count==0) {
			if (left) {
				delete left;
				left = nullptr;
			}
			if (right) {
				delete right;
				right = nullptr;
			}
			delete count;
			count = nullptr;
		}
	}

	TreeNode& operator=(const TreeNode& item) {
		++* item.count;
		if (-- * count == 0) {
			if (left)delete left;
			if (right)delete right;
		}
		value = item.value;
		count = item.count;
		left = item.left;
		right = item.right;
		return *this;
	}


private:
	string value;
	size_t* count;
	TreeNode* left;
	TreeNode* right;
};

class BinStrTree {
public:
	BinStrTree():
		root(new TreeNode()){}
	BinStrTree(const BinStrTree& item):
		root(new TreeNode(*item.root)){}
	~BinStrTree() {
		delete root;
	}

	BinStrTree& operator=(const BinStrTree& item) {
		TreeNode* ptemp = new TreeNode(*item.root);
		delete root;
		root = ptemp;
		return *this;
	}

private:
	TreeNode* root;
};

int main(void)
{

}
