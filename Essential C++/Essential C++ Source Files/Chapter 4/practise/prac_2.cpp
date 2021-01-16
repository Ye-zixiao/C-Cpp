#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Matrix
{
public:
	Matrix(float v0 = 0, float v1 = 0, float v2 = 0, float v3 = 0, float v4 = 0,
		float v5 = 0, float v6 = 0, float v7 = 0, float v8 = 0, float v9 = 0, float v10 = 0,
		float v11 = 0, float v12 = 0, float v13 = 0, float v14 = 0, float v15 = 0);
	Matrix(float* parr);
	~Matrix(){}

	float Matrix_Multi(const Matrix& m) const;
	Matrix Matrix_Add(const Matrix& m) const;
	void print() const;
	void operator+=(const Matrix& m);
	float& operator()(int row, int column);
	const float operator()(int row, int column) const;

private:
	float matrix_elems[4][4];
};

Matrix::Matrix(float v0, float v1, float v2, float v3, float v4, float v5, float v6, float v7, float v8,
	float v9, float v10, float v11, float v12, float v13, float v14, float v15)
{
	matrix_elems[0][0] = v0;
	matrix_elems[0][1] = v0;
	matrix_elems[0][2] = v0;
	matrix_elems[0][3] = v0;

	matrix_elems[1][0] = v0;
	matrix_elems[1][1] = v0;
	matrix_elems[1][2] = v0;
	matrix_elems[1][3] = v0;

	matrix_elems[2][0] = v0;
	matrix_elems[2][1] = v0;
	matrix_elems[2][2] = v0;
	matrix_elems[2][3] = v0;

	matrix_elems[3][0] = v0;
	matrix_elems[3][1] = v0;
	matrix_elems[3][2] = v0;
	matrix_elems[3][3] = v0;
}


Matrix::
Matrix(float* parr)
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; ++j)
			matrix_elems[i][j] = parr[i*4+j];
}

float Matrix::
Matrix_Multi(const Matrix& m) const
{
	float result = 0.0;
	for(int i=0;i<4;i++)
		for (int j = 0; j < 4; j++)
		{
			result += this->matrix_elems[i][j] * m.matrix_elems[j][i];
		}
	return result;
}

Matrix Matrix::
Matrix_Add(const Matrix& m) const
{
	Matrix return_m;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			return_m.matrix_elems[i][j] += m.matrix_elems[i][j];
	return return_m;
}

void Matrix::
print() const
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << this->matrix_elems[i][j] << "   ";
		}
		cout << endl;
	}
}

void Matrix::
operator+=(const Matrix& m)
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			this->matrix_elems[i][j] += m.matrix_elems[i][j];
}

float& Matrix::
operator()(int row, int column)
{
	return this->matrix_elems[row][column];
}

const float Matrix::
operator()(int row, int column) const
{
	return this->matrix_elems[row][column];
}

int main(void)
{
	float arr[16] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
	Matrix test_matrix(arr);
	test_matrix.print();
	cout << endl;
	Matrix test_matrix2(arr);
	/*test_matrix += test_matrix2;//矩阵加法
	test_matrix.print();*/

	float value = test_matrix.Matrix_Multi(test_matrix2);//矩阵乘法
	cout << value << endl;

	cout << test_matrix(2, 3) << endl;//函数调用运算符（）重载
	value = test_matrix(2, 3);			//返回的是const数据
	value = 6;

	test_matrix(2, 3)=9;				//返回的是引用（实质上是地址），使用引用对它进行修改
	cout << test_matrix(2, 3)<<endl;

	float* p = &test_matrix(2, 3);		//返回的是引用
	*p = 4;								//对引用取地址得到矩阵[2][3]的地址，从而用指针对它进行修改
	cout << test_matrix(2, 3) << endl;


	return 0;
}
