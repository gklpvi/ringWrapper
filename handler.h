#ifndef HANDLER
#define HANDLER

#include <iostream>
#include <chrono>
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
            this_thread::sleep_for(chrono::seconds(*value));
            //cout << *value << endl;
        } while (*value != -1);

        delete value;
    };
};

#endif