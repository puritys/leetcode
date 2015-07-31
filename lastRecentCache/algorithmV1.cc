#include "algorithm.h"

LRUCacheV1::LRUCacheV1(int cap) {
    capacity = cap;
    length = 0;
    time = 0;
}


int LRUCacheV1::get(int key) {
    int val;
    map<int, pair<int, int> >::iterator hashIt = hash.find(key);
    map<int, pair<int, int> >::iterator timeIt;
    if (hashIt != hash.end()) {
        time++;
        val = hashIt->second.first;
        timeIt = times.find(hashIt->second.second);
        assert(timeIt != times.end());
        times.insert(make_pair(time, make_pair(key, val)));
        hashIt->second.second = time;
        times.erase(timeIt);
        return val;
    }
    return -1; 
}

void LRUCacheV1::set(int key, int value) {
    map<int, pair<int, int> >::iterator hashIt = hash.find(key);
    map<int, pair<int, int> >::iterator timeIt;
    if (hashIt != hash.end()) {
        time++;
        timeIt = times.find(hashIt->second.second);
        hashIt->second.second = time;
        hashIt->second.first = value;
        times.insert(make_pair(time, make_pair(key, value)));
        times.erase(timeIt);
    } else {
        if (length >= capacity) {
            int eraseKey = ((times.begin())++)->second.first;
            times.erase((times.begin()++));
            hash.erase(eraseKey);
            length--;
        }
        time++;
        times.insert(make_pair(time, make_pair(key, value)));
        hash.insert(make_pair(key, make_pair(value, time)));
        length++;
    }
}


