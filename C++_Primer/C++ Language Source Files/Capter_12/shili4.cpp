#include<iostream>
#include<vector>
#include<string>
#include<memory>
using namespace::std;

struct Destination {											//记录连接目标地址和使用速率,需要通过create_dest函数来创建
	Destination(const string& str, double r) :
		dest(str), rate(r) {}

	string dest;
	double rate;
};

class Connection {
	friend void disconnect(Connection* pconnect);
public:
	explicit Connection(Destination* pd, size_t ld = 1) :			//连接必须手动关闭，不会自动关闭，关闭指的就是释放Destination的动态内存
		pdest(pd), link_devices(ld) {
		cout << pdest->dest << " connect!" << endl;
	}																//手动关闭有两种方法：一种是使用非成员函数disconnect，一种是使用成员函数close
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
	size_t link_devices;//设备连接数
};

void disconnect(Connection* pconnect)//关闭连接
{
	cout << pconnect->pdest->dest;
	delete pconnect->pdest;
	cout << " disconnect" << endl;
}

Destination* create_dest(const string& str, double r)//创建dest动态对象
{
	return new Destination(str, r);
}

Connection connect(Destination* pd)//创建连接(创建了一个动态Destination类对象用临时的Connection类对象包装，返回该临时Connection对象)
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
