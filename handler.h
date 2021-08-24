#ifndef HANDLER
#define HANDLER

#include <iostream>
#include "myRing.h"

using namespace std;

class handler
{

public:
    void proccess(ringWrapper<int *> *wrapper, int *deq)
    {
        int *value = new int();

        do
        { // if received -1 receiver method ends, so should the handler
            *value = wrapper->dequeue(&deq);

            // insert a thread to make it wait for 'temp' seconds  sleep()?
        } while (*value != -1);
        
        delete value;
    };
};

#endif