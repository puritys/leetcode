// https://leetcode.com/problems/lru-cache/
#include "algorithm.h"

int main () {
    LRUCache *c = new LRUCache(3);
    c->set(1, 11);

    cout << "val = " << c->get(1) << endl;
    cout << "val = " << c->get(1) << endl;


    return 0;
}
