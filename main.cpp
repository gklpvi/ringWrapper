#include <iostream>
#include "rte_eal.h"
#include "rte_debug.h"

#include "rte_ring.h"

using namespace std;

class ringWrapper{
  rte_ring* myRing;

public:
  ringWrapper(char* name, unsigned int count, int socket_id, unsigned int flags)
  {myRing = rte_ring_create(name, count, socket_id, flags);};  //contructor using create method
  ~ringWrapper(){rte_ring_free(myRing);};  // destructor using free method

  int enqueue(void* obj){return rte_ring_enqueue(myRing, obj);};
  int dequeue(void** objPtr){return rte_ring_dequeue(myRing, objPtr);};
  
  rte_ring* getPtr(){return myRing;};
};

int main(int argc, char** argv)
{
    int ret = rte_eal_init(argc, argv);  // to verify whether dpdk is linked correctly
    if (ret < 0)		  rte_panic("Cannot init EAL\n");
    
    char name[3];
    name[0] = 'g';
    name[1] = 'k';
    name[2] = '\0';

    ringWrapper temp(name, 32, 0, RING_F_SP_ENQ);  // to try ring wrapper

    cout << temp.getPtr() <<endl;
    cout <<"full: " << rte_ring_full(temp.getPtr()) << " -  empty: " <<  rte_ring_empty(temp.getPtr()) <<endl;

    int x = 5;
    void* ptrInt = &x;
    cout << "Enq: " << temp.enqueue(ptrInt) << endl;
    cout <<"full: " << rte_ring_full(temp.getPtr()) << " -  empty: " <<  rte_ring_empty(temp.getPtr()) <<endl;

    void* deq;
    cout << temp.dequeue(&deq) << endl;
    int* derefPtr = (int*) deq;
    cout << *derefPtr << endl;

    return 0;
}