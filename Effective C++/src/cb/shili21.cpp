#include<iostream>
#include<new>

void outofMem(void) {
	std::cout << "out of memory\n";
// 	throw std::bad_alloc();
	std::set_new_handler(nullptr);
}

int main(void) {
	int* p = nullptr;
	std::set_new_handler(outofMem);
	try {
// 		p = new (std::nothrow) int[100223333300L];
        p=new int[1122222323L];
	}
	catch (const std::bad_alloc& err) {
		std::cout << err.what() << std::endl;
	}

    if(p){
        std::cout<<"delete[]p"<<std::endl;
        delete []p;
    }
	return 0;
}
