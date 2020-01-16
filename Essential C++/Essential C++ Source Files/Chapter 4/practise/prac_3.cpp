#include<iostream>
using namespace std;

typedef float elemType;

class Matrix
{
	//friend Matrix operator+(const Matrix& m1, const Matrix& m2);//这两个函数没必要作为该类的友元函数，因为它没有直接访问private成员
	//friend Matrix operator*(const Matrix& m1, const Matrix& m2);

public:
	Matrix(const elemType* arr);						//构造函数
	Matrix();

	int rows() const { return 4; }						//返回矩阵行数和列数
	int cols() const { return 4; }

	ostream& print(ostream& os) const;					//打印矩阵中的每一个数据

	void operator+=(const Matrix& m);					//重载+=，用于矩阵与另一个矩阵相加，然后将结果保存到当前矩阵当中
	elemType operator()(int row, int column) const { return _matrix[row][column]; }//返回矩阵中某一个元素的数据，不能修改矩阵中的数据
	elemType& operator()(int row, int column) { return _matrix[row][column]; }		/*返回矩阵中某一个元素的引用（实质是地址），
																					可以用此修改矩阵中的数据*/

private:
	elemType _matrix[4][4];
};


inline ostream& operator<<(ostream& os, const Matrix& m1)			//这个是内联到主调函数中的！
{
	return m1.print(os);
}

Matrix::
Matrix()
{
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			_matrix[i][j] = 0;
}

Matrix::
Matrix(const elemType* arr)
{
	int index = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			_matrix[i][j] = arr[index++];
}

void Matrix::
operator+=(const Matrix& m)
{
	for (int index = 0; index < 4; ++index)
		for (int jndex = 0; jndex < 4; ++jndex)
			_matrix[index][jndex] += m._matrix[index][jndex];//这里犯了个错误，现已改正没有写m._matrix
	/*cout << *this << endl;*/
}

ostream& Matrix::
print(ostream& os) const
{
	int cnt = 0;
	for(int i=0;i<4;i++)
		for (int j = 0; j < 4; j++, cnt++)
		{
			if (cnt && !(cnt % 4))
				os << endl;
			os << _matrix[i][j] << ' ';
		}
	os << endl;
	return os;
}

Matrix operator+(const Matrix& m1, const Matrix& m2)			/*这两个函数其实没有必要添加到Matrix中作为友元，
																因为他们都没有直接访问Matrix中的私有成员*/
{
	Matrix result(m1);
	result += m2;
	return result;
}

Matrix operator*(const Matrix& m1, const Matrix& m2)			//效果就是 返回m1*m2的结果矩阵
{
	Matrix result;
	for(int i=0;i<m1.cols();++i)
		for (int j = 0; j < m1.rows(); j++)
		{
			for (int k = 0; k < m1.cols(); k++)
				result(i, j) += m1(i, k) * m2(k, j);
		}
	return result;
}


int main(void)
{
	Matrix m;
	cout << "m:" << endl;
	cout << m << endl;

	elemType arr1[16] = {
		1,0,0,0,
		0,1,0,0,
		0,0,1,0,
		0,0,0,1,
	};
	Matrix m1(arr1);				//默认成员逐一复制操作
	cout << "m1" << endl;
	cout << m1 << endl;

	elemType arr2[16] = {
		1.3,0.4,2.6,8.2,
		6.2,1.7,1.3,8.3,
		4.2,7.4,2.7,1.9,
		6.3,8.1,5.6,6.6
	};
	Matrix m2(arr2);
	cout << "m2:" << endl;
	cout << m2 << endl;

	Matrix m3 = m2 * m1;
	cout << "m3=m1*m2:" << endl;
	cout << m3 << endl;

	/*cout << m1 << endl;
	cout << m2 << endl;*/
	Matrix m4 = m1+m2;
	cout << "m4=m1+m2:" << endl;
	cout << m4 << endl;

	return 0;
}
