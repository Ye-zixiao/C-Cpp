#ifndef _SALES_DATA_
#define _SALES_DATA_

#include<iostream>
#include<string>

class Sales_data {
	friend std::istream& read(Sales_data& item, std::istream& is);
	friend std::ostream& print(const Sales_data& item, std::ostream& os);
public:
	Sales_data(const std::string& bn, unsigned cnt, double price) :
		bookNo(bn), units_sold(cnt), revenue(price* units_sold) {}
	Sales_data() :Sales_data("", 0, 0) {}
	explicit Sales_data(const std::string& bn) :Sales_data(bn, 0, 0) {}
	explicit Sales_data(std::istream& is) :Sales_data() {//�ؼ���explicit��ֹת�����캯����ʹ�ã�����ֹ��ǰ�����͵���ʽ��������ת����
		read(*this, is);
	}

	const Sales_data& operator=(const Sales_data&);

	std::string isbn(void)const { return bookNo; }
	Sales_data& combine(const Sales_data& item);
	unsigned get_units_sold(void)const { return units_sold; }

private:
	double avg_price(void)const { return units_sold > 0 ? (revenue / units_sold) : 0; }
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0;
};

//���ڷǳ�Ա������Ҫ��ͷ�ļ�������һ�£����������еĳ�Ա�����������Ա�������������Ѿ���ͷ�ļ�����������
//������ĳ�Ա������Ҫʹ��extern�ؼ���ָ����Ա�����Ƕ����ںδ�
extern std::istream& read(Sales_data& item, std::istream& is = std::cin);
extern std::ostream& print(const Sales_data& item, std::ostream& os = std::cout);


#endif