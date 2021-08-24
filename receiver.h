#ifndef RECEIVER
#define RECEIVER

#include <iostream>
#include "myRing.h"

using namespace std;

class receiver
{

public:
    void input(ringWrapper<int *> *wrapper)
    {
        cout << "-1 to exit" << endl;
        int *value = new int();

        while (true)
        {
            cin >> *value;
            wrapper->enqueue(value);

            if (*value == -1)
                break;
        }

        delete value;
    };
};

#endif