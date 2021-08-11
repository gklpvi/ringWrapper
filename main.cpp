#include <iostream>
#include "rte_eal.h"
#include "rte_debug.h"

using namespace std;

int main(int argc, char** argv)
{
    cout<<"HelloW!\n";

    int ret = rte_eal_init(argc, argv);
    if (ret < 0)
		rte_panic("Cannot init EAL\n");

    return 0;
}