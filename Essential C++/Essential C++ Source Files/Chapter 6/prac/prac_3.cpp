/*---------------------这个程序是有问题的---------------------*/
#include<iostream>
#include<fstream>
using namespace std;

template<typename elemType>
class Matrix
{
public:
	Matrix(int rows, int cols);
	Matrix(const Matrix& m);
	~Matrix()
	{
		delete[]_matrix;
	}

	Matrix& operator=(const Matrix& m);
	void operator+=(const Matrix& m);
	void operator-=(const Matrix& m);
	elemType& operator()(int rows, int cols);
	const elemType& operator()(int rows, int cols) const;

	int rows() const { return _rows; }
	int cols() const { return _cols; }
	bool same_size(const Matrix& m) const;
	bool comfortable(const Matrix& m) const;
	ostream& print(ostream& os) const;

private:
	int _rows;
	int _cols;
	elemType* _matrix;
};

template<typename elemType>
Matrix<elemType>::
Matrix(int rows, int cols)
	:_rows(rows),_cols(cols)
{
	int size = rows * cols;
	_matrix = new elemType[size];
	for (int i = 0; i < size; ++i)
		_matrix[i] = elemType();
}

template<typename elemType>
Matrix<elemType>::
Matrix(const Matrix& m)
{
	_rows = m.rows();
	_cols = m.cols();
	int size = _rows * _cols;
	_matrix = new elemType[size];
	for (int i = 0; i < size; ++i)
		_matrix[i] = m._matrix[i];
}

template<typename elemType>
Matrix<elemType>& Matrix<elemType>::
operator=(const Matrix& m)
{
	if (this != &m)
	{
		_rows = m.rows();
		_cols = m.cols();
		int size = _rows * _cols;
		elemType* ptemp = _matrix;
		_matrix = new elemType[size];
		for (int i = 0; i < size; ++i)
			_matrix[i] = m._matrix[i];
	}

	return *this;
}

template<typename elemType>
void Matrix<elemType>::
operator+=(const Matrix& m)
{
	for (int i = 0; i < _rows * _cols; ++i)
		_matrix[i] += m._matrix[i];
}

template<typename elemType>
void Matrix<elemType>::
operator-=(const Matrix& m)
{
	for (int i = 0; i < _rows * _cols; ++i)
		_matrix[i] -= m._matrix[i];
}

template<typename elemType>
elemType& Matrix<elemType>::
operator()(int row, int col)//row行，col列
{
	return _matrix[row * cols() + col];
}

template<typename elemType>
const elemType& Matrix<elemType>::
operator()(int row, int col) const
{
	return _matrix[row * cols() + col];
}

template<typename elemType>
bool Matrix<elemType>::
same_size(const Matrix& m) const
{
	return (rows() == m.rows() && cols() == m.cols());
}

template<typename elemType>
bool Matrix<elemType>::
comfortable(const Matrix& m) const
{
	return cols() == m.rows();
}

template<typename elemType>
ostream& Matrix<elemType>::
print(ostream& os) const
{
	for (int i = 0; i < rows(); i++)
	{
		for (int j = 0; j < cols(); j++)
		{
			os << _matrix[i * cols() + j] << ' ';
		}
		os << endl;
	}

	return os;
}


/*------------------------类外普通函数-----------------*/
template<typename elemType>
Matrix<elemType>& operator+(const Matrix<elemType>& m1, const Matrix<elemType>& m2)
{
	if (!m1.same_size(m2))
		cerr << "Error" << endl;

	Matrix<elemType> result(m1);
	result += m2;

	return result;//this指针只能在类中的成员函数中使用
}

template<typename elemType>
Matrix<elemType>& operator-(const Matrix<elemType>& m1, const Matrix<elemType>& m2)
{
	if (!m1.same_size(m2))
		cerr << "Error" << endl;

	Matrix<elemType> result(m1);
	result -= m2;

	return result;
}

template<typename elemType>
Matrix<elemType>& operator*(const Matrix<elemType>& m1, const Matrix<elemType>& m2)
{
	if (!m1.comfortable(m2))
		cerr << "Error" << endl;

	Matrix<elemType> result(m1.rows(), m1.cols());
	for(int i=0;i<result.rows();++i)
		for (int j = 0; j < result.cols(); ++j)
		{
			result(i, j) = 0;
			for (int k = 0; k < result.cols(); ++k)
				result(i, j) += m1(i, k) * m2(k, j);
		}
	return result;
}

template<typename elemType>
ostream& operator<<(ostream &os,const Matrix<elemType>& m)
{
	return m.print(os);
}

int main(void)
{
	Matrix<float> m1(4, 4);
	cout << m1 << endl;

	float arr[16] = {
		1.,2.,3.,4.,
		5.,6.,7.,8.,
		8.,7.,6.,5.,
		4.,3.,2.,1.,
	};

	for (int i = 0; i < m1.rows(); ++i)
		for (int j = 0; j < m1.cols(); ++j)
			m1(i, j) = arr[i * m1.cols() + j];
	cout << m1 << endl;

	Matrix<float> m2(m1);
	cout << m2 << endl;
	Matrix<float> m3(m2);
	m3 = m2 - m1;
	cout << m3 << endl;

	return 0;
}
