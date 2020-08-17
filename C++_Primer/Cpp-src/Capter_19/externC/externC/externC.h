#ifndef EXTERNC_H_INCLUDED
#define EXTERNC_H_INCLUDED

#include<iostream>

extern "C" void cppfunc(int value){
    cout<<value<<endl;
}

#endif // EXTERNC_H_INCLUDED
