#include<iostream>
#include<vector>
#include<string>
#include<memory>
using namespace::std;

class Destination {
	friend class Connection;
public:
	Destination(const string&str,size_t p, double r):
		dest(str),port(p),rate(r){}

private:
	string dest;
	size_t port;
	double rate;
};

class Connection {
public:
	Connection(Destination*pd,size_t ld=1):
		pdest(pd),linked_device(ld){
		cout << pdest->dest << " connected" << endl;
	}
	Connection(const string&str,size_t p, double r,size_t ld=1):
		Connection(new Destination(str,p,r),ld){}

	ostream& get_connect_info(ostream& os = cout) const {
		return os << "Destination:  " << pdest->dest
			<< "\nPort:  " << pdest->port
			<< "\nLinked Rate:  " << pdest->rate
			<< "\nLinked Device:  " << linked_device << endl
			<<"-------------------------------------------------"<<endl;
	}

	Connection& reset(Destination* pd, size_t ld = 1) {
		pdest = pd;
		linked_device = ld;
		cout << "Connection reset" << endl;
		return *this;
	}
	Connection& reset(const string& str, size_t p, double r, size_t ld = 1) {//注意这里不会自动去释放原来的Destination动态对象，需要自己去主动去关闭
		return reset(new Destination(str, p, r), ld);
	}
	Connection& set_dest(const string& str) {
		pdest->dest = str;
		return *this;
	}
	Connection& set_port(size_t p) {
		pdest->port = p;
		return *this;
	}
	Connection& set_rate(size_t rate) {
		pdest->rate;
		return *this;
	}
	Connection& add_device(size_t num) {
		linked_device += num;
		cout << "Add " << num << " devices" << endl;
		return *this;
	}
	Connection& sub_device(size_t num) {
		if (num > linked_device) {
			cerr << "No enough devices for subbing" << endl;
			return *this;
		}
		linked_device -= num;
		cout << "Sub " << num << " devices" << endl;
		return *this;
	}
	Connection& set_device(size_t num) {
		linked_device = num;
		cout << "Linked devices reset" << endl;
		return *this;
	}

	void close(void) {
		cout << pdest->dest;
		delete pdest;
		cout << " closed" << endl;
	}

private:
	Destination* pdest;
	size_t linked_device;
};

Connection connect(Destination* pde)
{
	Connection temp(pde);
	return temp;
}

int main(void)
{
	auto pdest = new Destination("192.168.1.1", 10086, 55.32);
	auto con = connect(pdest);
	shared_ptr<Connection> pcon(&con, [](Connection* pcon) {pcon->close(); });
	pcon->get_connect_info();
	//reset connection
	pcon->close();
	pcon->reset("1.1.1.1", 2355, 32.22);
	con.get_connect_info();

	return 0;
}
