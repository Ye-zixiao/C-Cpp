#include<iostream>
#include<string>
using namespace std;

template<typename valType>
class BinaryTree;					//前置声明


template<typename valType>
class BTnode																//模板节点类
{
	friend class BinaryTree<valType>;										//模板二叉树类是节点类的友元类
public:
	BTnode(const valType& val);

	void insert_value(const valType& val);									//插入节点（如果没有就插入，如果已经有就只是简单的增加_cnt）
	static void lchild_leaf(BTnode* leaf, BTnode* subtree);					//在节点subtree所在的节点的左子树的左孩子上插入leaf所代表的子树
	void remove_value(const valType& val, BTnode*& prev);					//移除节点（具有判断、删除、重新组织二叉树的功能）

	void preorder(BTnode* pt, ostream& os=cout) const;
	void inorder(BTnode* pt, ostream& os=cout) const;
	void postorder(BTnode* pt, ostream& os=cout) const;
	void display_val(BTnode* pt, ostream& os) const;

private:
	valType _val;
	int _cnt;
	BTnode* _lchild;
	BTnode* _rchild;
};


template<typename valType>													//二叉树模板类
class BinaryTree
{

public:
	BinaryTree();
	BinaryTree(const BinaryTree&);
	~BinaryTree();
	BinaryTree& operator=(const BinaryTree&);

	bool empty() { return _root == NULL; }
	void clear()
	{
		if (_root)
			clear(_root);
		_root = NULL;
	}

	void insert(const valType& val);													/*插入，在二叉树类中只是作为一个简单的接口
																						（检查根节点是否为空，如果不为空才会调用BTnode中的插入函数）*/
	void remove(const valType& val);													//移除普通节点：让待删的节点的右孩子代替原来的双亲结点，待删节点的左孩接到替代节点的左孩子上面
	void remove_root();																	/*移除根节点，其实使用方法与普通的remove并没有什么差别
																						主要的差别在于：
																							根节点是没有双亲结点的而普通节点是由双亲结点的
																							普通节点需要解决的是原来的双亲结点在其孩子节点删除之后，它的指向孩子节点的指针要指向哪一个
																						节点。而根节点需要解决的是根节点需要有新的代替*/

	void preorder(ostream& os) const;													//都是采用调用BTnode中的函数
	void postorder(ostream& os) const;
	void inorder(ostream& os) const;

	void print(ostream& os, void (BinaryTree::* pTraversel)(ostream& os) const) const;	//打印函数，其中一个参数是指向成员函数的指针

private:
	BTnode<valType>* _root;
	void clear(BTnode<valType>* proot);
	void copy(BTnode<valType>*& target, BTnode<valType>* source);						//指针的引用，其实起到的是二级指针的作用

};


/*--------------------BinaryTree类模板成员函数的定义----------------------*/
template<typename valType>
inline BinaryTree<valType>::
BinaryTree()
	:_root(NULL){}

template<typename valType>
BinaryTree<valType>::
BinaryTree(const BinaryTree& rhs)
{
	copy(_root, rhs._root);
}

template<typename valType>
inline BinaryTree<valType>::
~BinaryTree()
{
	clear();
}

template<typename valType>
inline BinaryTree<valType>& BinaryTree<valType>::
operator=(const BinaryTree& rhs)
{
	if (this != &rhs)
	{
		clear();
		copy(_root, rhs._root);
	}
	return *this;
}

template<typename valType>
void BinaryTree<valType>::
clear(BTnode<valType>* proot)
{
	if (proot)
	{
		clear(proot->_lchild);
		clear(proot->_rchild);
		delete proot;
	}
}


template<typename valType>
inline void BinaryTree<valType>::
insert(const valType& val)
{
	if (!_root)
		_root = new BTnode<valType>(val);							//插入一个新的元素
	else
		_root->insert_value(val);
}

template<typename valType>
inline void BinaryTree<valType>::
remove(const valType& val)											//移除一个元素
{
	if (_root)
	{
		if (_root->_val == val)
			remove_root();											//特例：移除根节点，并处理后续事宜
		else
			_root->remove_value(val, _root);						//移除普通的节点
	}
}

template<typename valType>
void BinaryTree<valType>::
remove_root()												/*-----其实这里采用的方法跟remove中的一般方法是相同的：让右孩子替换原来的节点，但还是有不同的*/
{
	if (!_root)
		return;
	BTnode<valType>* temp = _root;
	if (_root->_rchild)											//如果存在右孩子
	{
		_root = _root->_rchild;									//让右孩子成为根节点
		if (temp->_lchild)
		{
			BTnode<valType>* lc = temp->_lchild;
			BTnode<valType>* newlc = _root->_lchild;
			if (!newlc)											/*若右孩子（现在已经是根节点）的左孩子不存在，
																	则让原根节点的左孩子成为它的左孩子*/
				_root->_lchild = lc;
			else
				BTnode<valType>::lchild_leaf(lc, newlc);		//否则就在右孩子（现在已经是根节点）的左子树最左边的孩子的位置上加入成为叶节点
		}
	}
	else
		_root = _root->_lchild;									//若不存在右孩子，只有左孩子（可能连左孩子都没有）

	delete temp;
}

template <typename valType>
void BinaryTree<valType>::
copy(BTnode<valType>*& tar, BTnode<valType>* src)
{
	if (src) {
		tar = new BTnode<valType>(src->_val);
		if (src->_lchild)
			copy(tar->_lchild, src->_lchild);
		if (src->_rchild)
			copy(tar->_rchild, src->_rchild);
	}
}

template<typename valType>
void BinaryTree<valType>::
preorder(ostream& os) const
{
	_root->preorder(_root, os);
}

template<typename valType>
void BinaryTree<valType>::
inorder(ostream& os) const
{
	_root->inorder(_root, os);
}

template<typename valType>
void BinaryTree<valType>::
postorder(ostream& os) const
{
	(*_root).postorder(_root, os);							//为什么需要使用->运算符对BTnode类中的成员函数进行调用？
}															/*  这是因为BTnode中的成员函数是普通的成员函数，需要依托于真实存在的类对象obj来进行调用，
															而*_root或者_root->本身就代表着真实存在的BTnode类对象，所以才可以进行访问。
																但是如果想通过BTnode<valType>::postorder(参数)来调用遍历函数是不切实际的：
																	1、BTnode中的postorder这里遍历函数都是普通成员函数而不是静态成员函数，不能直接调用
																	2、普通成员函数的执行必须依托于真实存在的类对象，不管是类指针还是类引用还是直接的类名*/

template<typename valType>
inline BTnode<valType>::
BTnode(const valType& val)
	:_val(val)
{
	_cnt = 1;
	_lchild = _rchild = NULL;
}

template<typename valType>
ostream& operator<<(ostream& os, const BinaryTree<valType>& bt)
{
	os << "Tree: " << endl;
	bt.print(os, &BinaryTree<valType>::postorder);
	return os;
}

template<typename valType>
void BinaryTree<valType>::
print(ostream& os, void(BinaryTree<valType>::* pTraversel)(ostream& os) const) const
{
	(this->*pTraversel)(os);											/*指向成员函数的指针的调用过程：
																			首先，对pTraversel进行解引用，调用了BinaryTree<valType>::inorder（中序遍历）
																		然后，使用当前二叉树的根节点去调用BTnode中的中序遍历函数完成工作*/
}


/*--------------------BTnode类模板的定义-------------------------*/
template<typename valType>
void BTnode<valType>::
insert_value(const valType& val)
{
	if (val == _val)
	{
		_cnt++;
		return;
	}
	else if (val < _val)
	{
		if (!_lchild)
			_lchild = new BTnode<valType>(val);
		else
			_lchild->insert_value(val);
	}
	else
	{
		if (!_rchild)
			_rchild = new BTnode<valType>(val);
		else
			_rchild->insert_value(val);
	}
}

template<typename valType>
void BTnode<valType>::
lchild_leaf(BTnode* leaf, BTnode* subtree)
{
	while (subtree->_lchild)
		subtree = subtree->_lchild;
	subtree->_lchild = leaf;
}

template<typename valType>
void BTnode<valType>::
remove_value(const valType& val, BTnode*& prev)						//其实这种方法对于根节点同样是有效的，但是两者的不同之处在于根节点它没有父节点，而普通的节点是有父节点的
{
	if (val < _val)
	{
		if (!_lchild)
			return;
		else
			_lchild->remove_value(val, _lchild);
	}
	else if (val>_val)
	{
		if (!_rchild)
			return;
		else
			_rchild->remove_value(val, _rchild);
	}
	else
	{
		if (_rchild)
		{
			prev = _rchild;
			if (_lchild)
				if (!prev->_lchild)
					prev->_lchild = _lchild;
				else
					BTnode<valType>::lchild_leaf(_lchild, prev->_lchild);//这里我没搞懂它的static为什么还可访问非静态成员？？？
		}
		else
			prev = _lchild;

		delete this;
	}
}

template<typename valType>
void BTnode<valType>::
preorder(BTnode* pt, ostream& os) const
{
	if (pt)									//检查下根节点/入口节点是否存在
	{
		display_val(pt, os);
		preorder(pt->_lchild,os);
		preorder(pt->_rchild, os);
	}
}

template<typename valType>
void BTnode<valType>::
inorder(BTnode* pt, ostream& os) const
{
	if (pt)
	{
		inorder(pt->_lchild, os);
		display_val(pt, os);
		inorder(pt->_rchild, os);
	}
}

template<typename valType>
void BTnode<valType>::
postorder(BTnode* pt, ostream& os) const
{
	if (pt)
	{
		postorder(pt->_lchild, os);
		postorder(pt->_rchild, os);
		display_val(pt, os);
	}
}

template <typename valType>
inline void BTnode<valType>::
display_val(BTnode* pt, ostream& os) const
{
	os << pt->_val;
	if (pt->_cnt > 1)
		os << "( " << pt->_cnt << " ) ";
	else os << ' ';
}

/*------------------------其他------------------------*/


int main(void)
{
	BinaryTree<string> bt;

	bt.insert("Piglet");
	bt.insert("Eeyore");
	bt.insert("Roo");
	bt.insert("Tigger");
	bt.insert("Chris");
	bt.insert("Pooh");
	bt.insert("Kanga");
	bt.insert("Piglet");

	cout << "Preorder traversal:\n";
	bt.preorder(cout);

	bt.remove("Piglet");
	cout << "\n\nInorder traversal after Piglet removal:\n";
	bt.inorder(cout);

	bt.remove("Eeyore");

	cout << "\n\nPostorder traversal after Eeyore removal:\n";
	bt.postorder(cout);
	cout << endl;

	cout << "\n";
	cout << bt << endl;//重载输出运算符
	return 0;
}
