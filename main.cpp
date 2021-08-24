#include <iostream>
#include <thread>
#include "myRing.h"
#include "receiver.h"
#include "handler.h"

using namespace std;

int main(int argc, char **argv)
{
  int ret = rte_eal_init(argc, argv); // to verify whether dpdk is linked correctly
  if (ret < 0)
    rte_panic("Cannot init EAL\n");

  char name[3];  //string can be used with c_str() 
  name[0] = 'g';
  name[1] = 'k';
  name[2] = '\0';

  int* deq = new int();
  ringWrapper<int *>* temp = new ringWrapper<int*>(name, 32, 0, RING_F_SP_ENQ); // to try the ring wrapper
  
  receiver* myReceiver = new receiver();
  handler* myHandler = new handler();

  thread t1(&receiver::input, myReceiver, temp);
  thread t2(&handler::proccess, myHandler, temp, deq);

  t1.join(); t2.join();
  


  return 0;
}