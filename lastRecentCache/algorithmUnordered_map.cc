#include "algorithm.h"

LRUCacheUnordered::LRUCacheUnordered(int cap) {
    capacity = cap;
    length = 0;
}


int LRUCacheUnordered::get(int key) {
    unordered_map<int, pair<list<int>::iterator, int> >::iterator hashIt = hash.find(key);
    if (hashIt != hash.end()) {
        updateTime(hashIt, key);
        return hashIt->second.second;
    }
    return -1; 
}

void LRUCacheUnordered::set(int key, int value) {
    unordered_map<int, pair<list<int>::iterator, int> >::iterator hashIt = hash.find(key);
    if (hashIt != hash.end()) {
        hashIt->second.second = value;
        updateTime(hashIt, key);
    } else {
        if (length >= capacity) {
            int eraseKey = *times.begin();
            times.pop_front();
            hash.erase(eraseKey);
            length--;
        }
        times.push_back(key);
        hash.insert(make_pair(key, make_pair(--times.end(), value)));
        length++;
    }
}

void LRUCacheUnordered::updateTime(unordered_map<int, pair<list<int>::iterator, int> >::iterator hashIt, int key) {
    times.erase(hashIt->second.first);
    times.push_back(key);
    hashIt->second.first = --times.end();
}


