#include<iostream>
#include<string>
#include<vector>
#include<cctype>
using namespace::std;

class _Date_ {
public:
	_Date_():year(0),month(0),day(0){}
	_Date_(const string& date_str) {
		write_dateinfo(date_str);
	}

	string get_date(void) const;
	_Date_& change_date(const string& date_str) {
		write_dateinfo(date_str);
		return *this;
	}

private:
	unsigned convert_nnum_month(const string& date_str);
	void write_dateinfo(const string& date_str);

private:
	const string numbers{ "1234567890" };
	unsigned year;
	unsigned month;
	unsigned day;

};

unsigned _Date_::convert_nnum_month(const string& date_str)
{
	const vector<string> monvec{ "Jan","Feb","Mar","Apr","May",
		"Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
	for (unsigned i = 0; i < monvec.size(); ++i)
		if (date_str.find(monvec[i]) != string::npos)
			return i + 1;
	return 0;
}

/*
*成员函数名：write_dateinfo(const string&)
*作用：接收一个“月份/日期/年份”形式的字符串，格式没有太大的限制，将其中的日期信息提取出来分别用
*		unsigned数据成员进行存放
*/
void _Date_::write_dateinfo(const string& date_str)
{
	string::size_type pos = 0;
	while (!isalpha(date_str[pos]) && !isdigit(date_str[pos]))			//处理掉前面非数字和非字母的字符
		++pos;

	if (isalpha(date_str[pos]))
	{
		try {
			if ((month = convert_nnum_month(date_str)) == 0)
				throw runtime_error(date_str);
		}
		catch (runtime_error err) {
			cerr << err.what() << " is not right!";
			cout << " Please enter month(number) for this:\n\t";
			cin >> month;
		}
	}
	else{
		month = stoi(date_str.substr(date_str.find_first_of(numbers, pos)));//获取月份数据（当月份是以数字形式给出）
		pos = date_str.find_first_not_of(numbers, pos);					//定位到月份后面的第一个非数字字符
	}
	pos = date_str.find_first_of(numbers, pos);							//定位到月份后面第一个数字字符位置
	day = stoi(date_str.substr(pos));
	pos = date_str.find_first_not_of(numbers, pos);						//找到日期后面第一个非数字字符位置
	year = stoi(date_str.substr(date_str.find_first_of(numbers, pos)));	//然后直接取最后一个数字字符位置上的年
}

string _Date_::get_date(void) const
{
	return (year | month | day) == 0 ? "****-**-**" : (to_string(year) + '-' +
		to_string(month) + '-' + to_string(day));
}

int main(void)
{
	_Date_ date;
	cout << date.get_date() << endl;
	cout << date.change_date("#Mar-#6#-2020").get_date() << endl;

	return 0;
}
