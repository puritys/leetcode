#include "algorithm.h"
#include "smartPerf.h"

template <typename obj>
void run(obj o, int max) {
    int i;
    for (i = 0 ; i < max; i++ ) {
        o->set(floor(random() % 5000), i);
        o->get(floor(random() % 10));
    }
}

int main() {
    int max = 25000;
    srand(1); 
    smartPerf::start("Linear");
    LRUCacheLinear *CL = new LRUCacheLinear(300);
    run(CL, max);
    smartPerf::end(true);


    smartPerf::start("Two object");
    LRUCacheV1 *CL2 = new LRUCacheV1(300);
    run(CL2, max);
    smartPerf::end(true);


    smartPerf::start("Two object with the iterator of list");
    LRUCache *CL3 = new LRUCache(300);
    run(CL3, max);
    smartPerf::end(true);

    smartPerf::start("Two object, use unordered_map");
    LRUCacheUnordered *CL4 = new LRUCacheUnordered(300);
    run(CL4, max);
    smartPerf::end(true);

    smartPerf::print();

}
