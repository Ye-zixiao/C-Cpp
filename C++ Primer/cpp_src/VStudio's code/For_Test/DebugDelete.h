#ifndef _DEBUGDELETE_H_
#define _DEBUGDELETE_H_
//#define DEBUG
#include<iostream>

class DebugDelete {
public:
	DebugDelete(std::ostream&o=std::cerr):os(o){}

	template<typename T>
	void operator()(T* p) {
#ifdef DEBUG
		os << "Deleting obj..." << std::endl;
#endif
		delete p;
	}

private:
	std::ostream& os;
};

#endif