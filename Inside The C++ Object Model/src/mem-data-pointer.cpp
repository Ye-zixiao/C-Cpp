//Author: Ye-zixiao
//Date: 2021-03-06

#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <bits/stl_tree.h>
#include <initializer_list>
#include <iostream>
#include <queue>
#include <sstream>
#include <cmath>
using namespace std;

struct X { int value1; };
struct Y { int value2; };
struct Z : X, Y { int value3; };

int main() {
	printf("%ld\n", &X::value1);
	printf("%ld\n", &Y::value2);
	printf("%ld\n", &Z::value1);
	printf("%ld\n", &Z::value2);//这个比较特殊，竟然不是4
	printf("%ld\n", &Z::value3);
	return 0;
}