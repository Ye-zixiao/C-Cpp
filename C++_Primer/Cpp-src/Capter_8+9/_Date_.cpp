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
*��Ա��������write_dateinfo(const string&)
*���ã�����һ�����·�/����/��ݡ���ʽ���ַ�������ʽû��̫������ƣ������е�������Ϣ��ȡ�����ֱ���
*		unsigned���ݳ�Ա���д��
*/
void _Date_::write_dateinfo(const string& date_str)
{
	string::size_type pos = 0;
	while (!isalpha(date_str[pos]) && !isdigit(date_str[pos]))			//�����ǰ������ֺͷ���ĸ���ַ�
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
		month = stoi(date_str.substr(date_str.find_first_of(numbers, pos)));//��ȡ�·����ݣ����·�����������ʽ������
		pos = date_str.find_first_not_of(numbers, pos);					//��λ���·ݺ���ĵ�һ���������ַ�
	}
	pos = date_str.find_first_of(numbers, pos);							//��λ���·ݺ����һ�������ַ�λ��
	day = stoi(date_str.substr(pos));
	pos = date_str.find_first_not_of(numbers, pos);						//�ҵ����ں����һ���������ַ�λ��
	year = stoi(date_str.substr(date_str.find_first_of(numbers, pos)));	//Ȼ��ֱ��ȡ���һ�������ַ�λ���ϵ���
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
