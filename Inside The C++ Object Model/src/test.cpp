#include <iostream>
#include <typeinfo>

struct __mptr{
	int delta;
	int index;
	union {
		void* faddr;
		int v_offset;
	};
};