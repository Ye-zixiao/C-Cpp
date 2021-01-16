#include<iostream>
#include<vector>
#include<string>
#include<memory>
using namespace::std;

struct Destination {											//��¼����Ŀ���ַ��ʹ������,��Ҫͨ��create_dest����������
	Destination(const string& str, double r) :
		dest(str), rate(r) {}

	string dest;
	double rate;
};

class Connection {
	friend void disconnect(Connection* pconnect);
public:
	explicit Connection(Destination* pd, size_t ld = 1) :			//���ӱ����ֶ��رգ������Զ��رգ��ر�ָ�ľ����ͷ�Destination�Ķ�̬�ڴ�
		pdest(pd), link_devices(ld) {
		cout << pdest->dest << " connect!" << endl;
	}																//�ֶ��ر������ַ�����һ����ʹ�÷ǳ�Ա����disconnect��һ����ʹ�ó�Ա����close
	Connection(const string& str, double r, size_t ld = 1) :
		Connection(new Destination(str,r),ld){}

	/*Connection& operator=(const Connection& item) {
		this->pdest = item.pdest;
		this->link_devices = item.link_devices;
		return *this;
	}*/

	ostream& get_connect_info(ostream& os = cout) const;
	Connection& reset(const string& str, double r) {
		pdest->dest = str;
		pdest->rate = r;
		cout << "connection reset!" << endl;
		return *this;
	}
	void close(void) {
		cout << pdest->dest;
		delete pdest;
		cout << " closed!" << endl;
	}
	Connection& add_device(size_t num) {
		link_devices += num;
		cout << "linked devices added!" << endl;
		return *this;
	}
	Connection& sub_device(size_t num) {
		if (num > link_devices)
		{
			cerr << "number is wrong,connection linked devices only have " << link_devices << " devices" << endl;
			return *this;
		}
		link_devices -= num;
		cout << "linked devices subed!" << endl;
		return *this;
	}
	size_t link_numbers(void)const {
		return link_devices;
	}

private:
	Destination* pdest;
	size_t link_devices;//�豸������
};

void disconnect(Connection* pconnect)//�ر�����
{
	cout << pconnect->pdest->dest;
	delete pconnect->pdest;
	cout << " disconnect" << endl;
}

Destination* create_dest(const string& str, double r)//����dest��̬����
{
	return new Destination(str, r);
}

Connection connect(Destination* pd)//��������(������һ����̬Destination���������ʱ��Connection������װ�����ظ���ʱConnection����)
{
	Connection temp(pd);
	return temp;
}

ostream& Connection::get_connect_info(ostream& os)const
{
	return os << "Destination:  " << pdest->dest
		<< "\nLinked User Rate:  " << pdest->rate
		<< "\nLinked User Devices:  " << link_devices
		<< "\n===============================================" << endl;
}

int main(void)
{
	auto pdest = create_dest("192.168.1.1", 100.0);
	Connection con = connect(pdest);
	//shared_ptr<Connection> p(&con, disconnect);
	shared_ptr<Connection> p(&con, [](Connection* pcon) { disconnect(pcon); });
	//shared_ptr<Connection> p(&con, [](Connection* pcon) {pcon->close(); });
	p->get_connect_info();
	p->reset("255.255.091.122", 110.0);
	con.add_device(10);
	p->get_connect_info();

	Connection con_2("0.0.0.0", 500.0);
	con_2.get_connect_info();
	con_2.close();

	return 0;
}
