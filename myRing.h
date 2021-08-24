#ifndef MYRING
#define MYRING 

#include <iostream>
#include "rte_eal.h"
#include "rte_debug.h"
#include "rte_ring.h"

using namespace std;

template <typename T>
class ringWrapper
{
  rte_ring *myRing;

public:
  ringWrapper(char *name, unsigned int count, int socket_id, unsigned int flags)
  {
    myRing = rte_ring_create(name, count, socket_id, flags);
  };                                         //contructor using create method
  ~ringWrapper() { rte_ring_free(myRing); }; // destructor using free method

  int enqueue(T obj) { return rte_ring_enqueue(myRing, obj); };
  int dequeue(T *objPtr) { return rte_ring_dequeue(myRing, reinterpret_cast<void**>(objPtr)); };

  rte_ring *getPtr() { return myRing; };
};

#endif