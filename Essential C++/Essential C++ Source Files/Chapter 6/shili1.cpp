#include<iostream>
#include<string>
using namespace std;

template<typename valType>
class BinaryTree;					//ǰ������


template<typename valType>
class BTnode																//ģ��ڵ���
{
	friend class BinaryTree<valType>;										//ģ����������ǽڵ������Ԫ��
public:
	BTnode(const valType& val);

	void insert_value(const valType& val);									//����ڵ㣨���û�оͲ��룬����Ѿ��о�ֻ�Ǽ򵥵�����_cnt��
	static void lchild_leaf(BTnode* leaf, BTnode* subtree);					//�ڽڵ�subtree���ڵĽڵ���������������ϲ���leaf�����������
	void remove_value(const valType& val, BTnode*& prev);					//�Ƴ��ڵ㣨�����жϡ�ɾ����������֯�������Ĺ��ܣ�

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


template<typename valType>													//������ģ����
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

	void insert(const valType& val);													/*���룬�ڶ���������ֻ����Ϊһ���򵥵Ľӿ�
																						�������ڵ��Ƿ�Ϊ�գ������Ϊ�ղŻ����BTnode�еĲ��뺯����*/
	void remove(const valType& val);													//�Ƴ���ͨ�ڵ㣺�ô�ɾ�Ľڵ���Һ��Ӵ���ԭ����˫�׽�㣬��ɾ�ڵ���󺢽ӵ�����ڵ����������
	void remove_root();																	/*�Ƴ����ڵ㣬��ʵʹ�÷�������ͨ��remove��û��ʲô���
																						��Ҫ�Ĳ�����ڣ�
																							���ڵ���û��˫�׽��Ķ���ͨ�ڵ�����˫�׽���
																							��ͨ�ڵ���Ҫ�������ԭ����˫�׽�����亢�ӽڵ�ɾ��֮������ָ���ӽڵ��ָ��Ҫָ����һ��
																						�ڵ㡣�����ڵ���Ҫ������Ǹ��ڵ���Ҫ���µĴ���*/

	void preorder(ostream& os) const;													//���ǲ��õ���BTnode�еĺ���
	void postorder(ostream& os) const;
	void inorder(ostream& os) const;

	void print(ostream& os, void (BinaryTree::* pTraversel)(ostream& os) const) const;	//��ӡ����������һ��������ָ���Ա������ָ��

private:
	BTnode<valType>* _root;
	void clear(BTnode<valType>* proot);
	void copy(BTnode<valType>*& target, BTnode<valType>* source);						//ָ������ã���ʵ�𵽵��Ƕ���ָ�������

};


/*--------------------BinaryTree��ģ���Ա�����Ķ���----------------------*/
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
		_root = new BTnode<valType>(val);							//����һ���µ�Ԫ��
	else
		_root->insert_value(val);
}

template<typename valType>
inline void BinaryTree<valType>::
remove(const valType& val)											//�Ƴ�һ��Ԫ��
{
	if (_root)
	{
		if (_root->_val == val)
			remove_root();											//�������Ƴ����ڵ㣬�������������
		else
			_root->remove_value(val, _root);						//�Ƴ���ͨ�Ľڵ�
	}
}

template<typename valType>
void BinaryTree<valType>::
remove_root()												/*-----��ʵ������õķ�����remove�е�һ�㷽������ͬ�ģ����Һ����滻ԭ���Ľڵ㣬�������в�ͬ��*/
{
	if (!_root)
		return;
	BTnode<valType>* temp = _root;
	if (_root->_rchild)											//��������Һ���
	{
		_root = _root->_rchild;									//���Һ��ӳ�Ϊ���ڵ�
		if (temp->_lchild)
		{
			BTnode<valType>* lc = temp->_lchild;
			BTnode<valType>* newlc = _root->_lchild;
			if (!newlc)											/*���Һ��ӣ������Ѿ��Ǹ��ڵ㣩�����Ӳ����ڣ�
																	����ԭ���ڵ�����ӳ�Ϊ��������*/
				_root->_lchild = lc;
			else
				BTnode<valType>::lchild_leaf(lc, newlc);		//��������Һ��ӣ������Ѿ��Ǹ��ڵ㣩������������ߵĺ��ӵ�λ���ϼ����ΪҶ�ڵ�
		}
	}
	else
		_root = _root->_lchild;									//���������Һ��ӣ�ֻ�����ӣ����������Ӷ�û�У�

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
	(*_root).postorder(_root, os);							//Ϊʲô��Ҫʹ��->�������BTnode���еĳ�Ա�������е��ã�
}															/*  ������ΪBTnode�еĳ�Ա��������ͨ�ĳ�Ա��������Ҫ��������ʵ���ڵ������obj�����е��ã�
															��*_root����_root->����ʹ�������ʵ���ڵ�BTnode��������Բſ��Խ��з��ʡ�
																���������ͨ��BTnode<valType>::postorder(����)�����ñ��������ǲ���ʵ�ʵģ�
																	1��BTnode�е�postorder�����������������ͨ��Ա���������Ǿ�̬��Ա����������ֱ�ӵ���
																	2����ͨ��Ա������ִ�б�����������ʵ���ڵ�����󣬲�������ָ�뻹�������û���ֱ�ӵ�����*/

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
	(this->*pTraversel)(os);											/*ָ���Ա������ָ��ĵ��ù��̣�
																			���ȣ���pTraversel���н����ã�������BinaryTree<valType>::inorder�����������
																		Ȼ��ʹ�õ�ǰ�������ĸ��ڵ�ȥ����BTnode�е��������������ɹ���*/
}


/*--------------------BTnode��ģ��Ķ���-------------------------*/
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
remove_value(const valType& val, BTnode*& prev)						//��ʵ���ַ������ڸ��ڵ�ͬ������Ч�ģ��������ߵĲ�֮ͬ�����ڸ��ڵ���û�и��ڵ㣬����ͨ�Ľڵ����и��ڵ��
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
					BTnode<valType>::lchild_leaf(_lchild, prev->_lchild);//������û�㶮����staticΪʲô���ɷ��ʷǾ�̬��Ա������
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
	if (pt)									//����¸��ڵ�/��ڽڵ��Ƿ����
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

/*------------------------����------------------------*/


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
	cout << bt << endl;//������������
	return 0;
}
