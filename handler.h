#ifndef HANDLER
#define HANDLER

#include <iostream>
#include <chrono>
#include "myRing.h"

using namespace std;

class handler
{

public:
    void proccess(ringWrapper<int *> *wrapper)
    {
        int* value = nullptr;
        while (true) 
        { // if received -1 receiver method ends, so should the handler
            value = nullptr;
            wrapper->dequeue(&value);
            if(value != nullptr){
                if(*value == -1)
                    break;
                for(int i=*value; i>=0; i--){
                    cout << i << endl;
                    this_thread::sleep_for(chrono::seconds(1));
                }
            }            
        } 
    };
};

#endif