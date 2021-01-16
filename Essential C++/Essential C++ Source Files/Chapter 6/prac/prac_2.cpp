#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

template<typename elemType>
class Matrix
{
	//friend Matrix<elemType> operator+(const Matrix<elemType>& m1,const Matrix<elemType>& m2);
	//friend Matrix<elemType> operator*(const Matrix<elemType>& m1, const Matrix<elemType>& m2);
public:
	Matrix(int rows, int columns);
	Matrix(const Matrix&);
	~Matrix()
	{
		delete[]_matrix;
	}

/*-------------------重载运算符---------------------*/
	Matrix& operator=(const Matrix&);
	void operator+=(const Matrix&);
	elemType& operator()(int row, int column)
	{
		return _matrix[row * cols() + column];
	}
	const elemType& operator()(int row, int column) const		/*该const成员函数虽然返回了一个引用变量，使得引用变量可以代表
																的返回数据成员，但是不用担心这个引用变量是不会改变原数据成员的*/
	{
		return _matrix[row * cols() + column];
	}


	int rows() const { return _rows; }
	int cols() const { return _cols; }

	bool same_size(const Matrix& m) const						//判断两个矩阵是否相等
	{
		return (rows() == m.rows() && cols() == m.cols());
	}
	bool comfortable(const Matrix& m) const						//判断两个矩阵是否可以相乘
	{
		return (cols() == m.rows());
	}
	ostream& print(ostream& os) const;							//打印输出

protected:
	int _rows;
	int _cols;
	elemType* _matrix;

};

template<typename elemType>
Matrix<elemType>::
Matrix(const Matrix& rhs)
{
	_rows = rhs._rows;
	_cols = rhs._cols;
	int mat_size = _rows * _cols;
	_matrix = new elemType[mat_size];
	for (int ix = 0; ix < mat_size; ++ix)
		_matrix[ix] = rhs._matrix[ix];
}

template<typename elemType>
Matrix<elemType>::
Matrix(int rows, int cols)
	:_rows(rows), _cols(cols)
{
	int size = _rows * _cols;
	_matrix = new elemType[size];
	for (int i = 0; i < size; i++)
		_matrix[i] = elemType();

}

template<typename elemType>
Matrix<elemType>& Matrix<elemType>::
operator=(const Matrix& rhs)
{
	if (this != &rhs)
	{
		_rows = rhs._rows;
		_cols = rhs._cols;
		int mat_size = _rows * _cols;
		delete[]_matrix;
		_matrix = new elemType[mat_size];
		for (int ix = 0; ix < mat_size; ++ix)
			_matrix[ix] = rhs._matrix[ix];
	}

	return *this;
}

template<typename elemType>
inline ostream&
operator<<(ostream& os, const Matrix<elemType>& m)
{
	return m.print(os);
}

template<typename elemType>
Matrix<elemType>
operator+(const Matrix<elemType>& m1, const Matrix<elemType>& m2)
{
	Matrix<elemType> result(m1);
	result += m2;
	return result;
}

template<typename elemType>
Matrix<elemType>
operator*(const Matrix<elemType>& m1, const Matrix<elemType>& m2)
{
	Matrix<elemType> result(m1.rows(), m2.cols());
	for (int ix = 0; ix < m1.rows(); ix++)
	{
		for (int jx = 0; jx < m1.cols(); jx++)
		{
			result(ix, jx) = 0;
			for (int kx = 0; kx < m1.cols(); kx++)
				result(ix, jx) += m1(ix, kx) * m2(kx, jx);
		}
	}
	return result;
}

template<typename elemType>
void Matrix<elemType>::
operator+=(const Matrix& m)
{
	int matrix_size = cols() * rows();
	for (int ix = 0; ix < matrix_size; ++ix)
		(*(_matrix + ix)) += (*(m._matrix + ix));
}

template<typename elemType>
ostream& Matrix<elemType>::
print(ostream& os) const
{
	int col = cols();
	int matrix_size = col * rows();
	for (int ix = 0; ix < matrix_size; ++ix)
	{
		if (ix % col == 0)
			os << endl;
		os << (*(_matrix + ix)) << ' ';
	}
	os << endl;
	return os;
}

int main(void)
{
	/*ofstream log("log.txt");
	if (!log)
	{
		cerr << "can't open log file!\n";
		return -1;
	}*/
	ostream& log = cout;

	Matrix<float> identity(4, 4);
	log << "identity: " << identity << endl;
	float ar[16] = {
		1.,0.,0.,0.,
		0.,1.,0.,0.,
		0.,0.,1.,0.,
		0.,0.,0.,1.,
	};

	for (int i = 0, k = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			identity(i, j) = ar[k++];
	log << "identity after set: " << identity << endl;

	Matrix<float> m(identity);
	log << "m:memberwise initialized: " << m << endl;

	Matrix<float> m2(8, 12);
	log << "m2: 8x12: " << m2 << endl;
	m2 = m;
	log << "m2 after memberwise assigned to m: "
		<< m2 << endl;

	float ar2[16] = {
		1.3,0.4,2.6,8.2,
		6.2,1.7,1.3,8.3,
		4.2,7.4,2.7,1.9,
		6.3,8.1,5.6,6.6,
	};

	Matrix<float> m3(4, 4);
	for (int ix = 0, kx = 0; ix < 4; ++ix)
		for (int j = 0; j < 4; ++j)
			m3(ix, j) = ar2[kx++];

	log << "m3:assigned random values: " << m3 << endl;
	Matrix<float> m4 = m3 * identity;
	log << m4 << endl;
	Matrix<float> m5 = m3 + m4;
	log << m5 << endl;

	m3 += m4;
	log << m3 << endl;

	return 0;
}
