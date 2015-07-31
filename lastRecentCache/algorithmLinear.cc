#include "algorithm.h"

LRUCacheLinear::LRUCacheLinear(int cap) {
    capacity = cap;
}

int LRUCacheLinear::get(int key) {
    deque<pair<int, int> >::iterator it;
    for (it = q.begin(); it != q.end(); ++it) {
        if (it->first == key) return it->second;
    }
    return -1; 
}

void LRUCacheLinear::set(int key, int value) {
    if (get(key) == -1) {
        if (q.size() >= capacity) {
            q.pop_front();
        }
        q.push_back(make_pair(key, value));
    } 
}
