#include <iostream>
#include "rte_eal.h"
#include "rte_debug.h"
#include "rte_debug.h"

#include "rte_ring.h"

using namespace std;

class ringWrapper{
  rte_ring* myRing;

public:
  ringWrapper(char* name, unsigned int count, int socket_id, unsigned int flags )
  {myRing = rte_ring_create(name, count, socket_id, flags);};
  ~ringWrapper(){rte_ring_free(myRing);};

  //ringWrapper(rte_ring &);
  //ring* operator=(){};

  void enqueue(void* obj){rte_ring_enqueue(myRing, obj);};
  int dequeue(void** objPtr){return rte_ring_dequeue(myRing, objPtr);};

};


int main(int argc, char** argv)
{
    int ret = rte_eal_init(argc, argv);
    if (ret < 0)
		rte_panic("Cannot init EAL\n");

  //ringWrapper temp(g, );
    return 0;
}