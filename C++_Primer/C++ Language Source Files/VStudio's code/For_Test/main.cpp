#include<iostream>
using namespace::std;

struct B{};
struct D1:virtual B{};
struct D2:virtual B{};
struct D :D1, D2 {
	D():B(),D1(),D2(){}
};

struct D3 :D1, D2 {
	D3():D1(),D2(){}//这样的话虚基类对象B会隐式的执行默认初始化
};