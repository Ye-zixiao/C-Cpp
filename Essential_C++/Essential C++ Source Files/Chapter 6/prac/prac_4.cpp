#include<iostream>
#include<fstream>
using namespace std;

template<typename elemType,int _rows=4,int _cols=4>     //使用非类型模板参数和类型模板参数一起融合创建一个可设置行列的矩阵类
class Matrix
{
public:
	Matrix();
	Matrix(const Matrix& rhs);
	~Matrix()
	{
		delete[] _matrix;
	}

	Matrix& operator=(const Matrix& rhs);
	void operator+=(const Matrix& rhs);
	void operator-=(const Matrix& rhs);
	elemType& operator()(int row, int col);
	elemType operator()(int row, int col) const;
	int rows() const { return _rows; }
	int cols() const { return _cols; }
	//void rows(int row) { _rows = row; }
	//void cols(int col) { _cols = col; }
	bool same_size(const Matrix& m) const
	{
		return (rows() == m.rows() && cols() == m.cols());
	}
	bool comfortable(const Matrix& m) const
	{
		return cols() == m.rows();
	}
	ostream& print(ostream& os) const;

private:
	elemType* _matrix;
};

template<typename elemType,int _rows,int _cols>
Matrix<elemType,_rows,_cols>::
Matrix()
{
	int size = _rows * _cols;
	_matrix = new elemType[size];
	for (int i = 0; i < size; ++i)
		_matrix[i] = elemType();
}

template<typename elemType,int _rows,int _cols>
Matrix<elemType,_rows,_cols>::
Matrix(const Matrix& rhs)
{
	int size = _rows * _cols;
	_matrix = new elemType[size];
	for (int i = 0; i < size; ++i)
		_matrix[i] = rhs._matrix[i];
}

template<typename elemType,int _rows,int _cols>
Matrix<elemType,_rows,_cols>& Matrix<elemType,_rows,_cols>::
operator=(const Matrix& rhs)
{
	if (this != &rhs)
	{
	/*	_rows = rhs.rows();					//注意非类型模板参数是常量表达式，是不可修改的左值
		_cols = rhs.cols();*/
		/*rows(rhs.rows());
		cols(rhs.cols());*/
		elemType* ptemp = _matrix;
		int size = _cols * _rows;
		_matrix = new elemType[size];
		for (int i = 0; i < size; ++i)
			_matrix[i] = rhs._matrix[i];
		delete[]ptemp;
	}

	return *this;
}

template<typename elemType,int _rows,int _cols>
void Matrix<elemType,_rows,_cols>::
operator+=(const Matrix& rhs)
{
	int size = _rows * _cols;
	for (int i = 0; i < size; ++i)
		_matrix[i] += rhs._matrix[i];
}

template<typename elemType, int _rows, int _cols>
void Matrix<elemType, _rows, _cols>::
operator-=(const Matrix& rhs)
{
	int size = _rows * _cols;
	for (int i = 0; i < size; ++i)
		_matrix[i] -= rhs._matrix[i];
}

template<typename elemType,int _rows,int _cols>
elemType& Matrix<elemType,_rows,_cols>::
operator()(int row, int col)
{
	return _matrix[row * cols() + col];
}

template<typename elemType,int _rows,int _cols>
elemType Matrix<elemType,_rows,_cols>::
operator()(int row, int col) const
{
	return _matrix[row * cols() + col];
}

template<typename elemType,int _rows,int _cols>
ostream& Matrix<elemType,_rows,_cols>::
print(ostream& os) const
{
	int size = _cols * _rows;
	for (int i = 0; i < size; ++i)
	{
		os << _matrix[i] << ' ';
		if ((i + 1) % cols() == 0)
			os << endl;
	}
	os << endl;
	return os;
}

/*------------------类外函数------------------*/
template<typename elemType,int _rows,int _cols>
Matrix<elemType,_rows,_cols> operator+(const Matrix<elemType,_rows,_cols>& m1, const Matrix<elemType,_rows,_cols>& m2)
{
	Matrix<elemType,_rows,_cols> result(m1);
	result += m2;
	return result;
}

template<typename elemType, int _rows, int _cols>
Matrix<elemType, _rows, _cols> operator-(const Matrix<elemType, _rows, _cols>& m1, const Matrix<elemType, _rows, _cols>& m2)
{
	Matrix<elemType, _rows, _cols> result(m1);
	result -= m2;
	return result;
}

template<typename elemType,int _rows,int _cols>
Matrix<elemType, _rows, _cols> operator*(const Matrix<elemType, _rows, _cols>& m1, const Matrix<elemType, _rows, _cols>& m2)
{
	Matrix<elemType,_rows,_cols> result;
	for(int i=0;i<_rows;i++)
		for (int j = 0; j < _cols; ++j)
		{
			result(i, j) = 0;
			for (int k = 0; k < _cols; k++)
				result(i, j) += m1(i, k) * m2(k, j);
		}
	return result;
}

template<typename elemType,int _rows,int _cols>
ostream& operator<<(ostream& os,const Matrix<elemType,_rows,_cols>& m)
{
	return m.print(os);
}

int main(void)
{
	Matrix<float, 4, 4> m1;
	cout << m1 << endl;

	float arr[16] = {
		1.,2.,3.,4.,
		5.,6.,7.,8.,
		8.,7.,6.,5.,
		4.,3.,2.,1.,
	};

	//int size = m1.rows() * m1.cols();
	for (int i = 0; i < m1.rows(); ++i)
		for (int j = 0; j < m1.cols(); ++j)
			m1(i, j) = arr[i * m1.cols() + j];
	cout << m1 << endl;


	Matrix<float, 4, 4> m2(m1);
	Matrix<float, 4, 4> m3;
	/*m3 = m1 * m2;*/
	m3 = m1 - m2;
	cout << m3 << endl;
	m3(1, 1) = 5;
	m3(1, 2) = 5;
	m3(2, 1) = 5;
	m3(2, 2) = 5;
	cout << m3 << endl;
	m3 -= m2;
	cout << m3 << endl;

	Matrix<int, 5, 5> m4;
	cout << m4 << endl;

	return 0;
}
