#include<iostream>
#include<vector>
#include<string>
using namespace std;

class test_for_err
{
public:
	test_for_err(int index, int max)
		:_index(index), _max(max) {}

	int index() const { return _index; }
	int max() const { return _max; }

	void what_happend(ostream& os = cerr) const
	{
		os << "Internal error: current index "
			<< _index << " exceeds maximum bound: "
			<< _max;
		os << endl;
	}

private:
	int _index;
	int _max;
};

class test
{
public:
	test(int index)
		:_max(10)
	{
		try
		{
		    if (index > _max)
            {
                test_for_err ex(index, _max);
                throw ex;
            }
            else
                cout << "ok" << endl;
		}
		catch(test_for_err& iof)
		{
		    iof.what_happend();
		}
	}

private:
	int _max;
};

int main(void)
{
	test ts(11);

	return 0;
}
