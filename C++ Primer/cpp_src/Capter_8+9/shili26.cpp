#include<iostream>
#include<vector>
using namespace::std;

int main(void)
{
    vector<int> ivec;
    cout << "size:" << ivec.size() << endl
        << "capacity:" << ivec.capacity() << endl;

    for (size_t i = 0; i < 32; ++i)
        ivec.push_back(i);

    cout << "size:" << ivec.size() << endl
        << "capacity:" << ivec.capacity() << endl;

    ivec.reserve(50);
    cout << "size:" << ivec.size() << endl
        << "capacity:" << ivec.capacity() << endl;

    while (ivec.size() != ivec.capacity())
        ivec.push_back(0);

    cout << "size:" << ivec.size() << endl
        << "capacity:" << ivec.capacity() << endl;

    ivec.push_back(1);
    cout << "size:" << ivec.size() << endl
        << "capacity:" << ivec.capacity() << endl;

    ivec.shrink_to_fit();
    cout << "size:" << ivec.size() << endl
        << "capacity:" << ivec.capacity() << endl;

    return 0;
}
