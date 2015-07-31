#include "algorithm.h"

LRUCache::LRUCache(int cap) {
    capacity = cap;
    length = 0;
}


int LRUCache::get(int key) {
    map<int, pair<list<int>::iterator, int> >::iterator hashIt = hash.find(key);
    if (hashIt != hash.end()) {
        updateTime(hashIt, key);
        return hashIt->second.second;
    }
    return -1; 
}

void LRUCache::set(int key, int value) {
    map<int, pair<list<int>::iterator, int> >::iterator hashIt = hash.find(key);
    if (hashIt != hash.end()) {
        hashIt->second.second = value;
        updateTime(hashIt, key);
    } else {
        if (length >= capacity) {
            int eraseKey = times.back();
            times.pop_back();
            hash.erase(eraseKey);
            length--;
        }
        times.push_front(key);
        hash.insert(make_pair(key, make_pair(times.begin(), value)));
        length++;
    }
}

void LRUCache::updateTime(map<int, pair<list<int>::iterator, int> >::iterator hashIt, int key) {
    times.erase(hashIt->second.first);
    times.push_front(key);
    hashIt->second.first = times.begin();
}


