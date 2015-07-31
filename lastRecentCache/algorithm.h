#include "math.h"
#include "assert.h"
#include <iostream>
#include <deque>  
#include <map>
#include <list>
#include <string>
#include <vector>

using namespace std;


class LRUCache{
private:
    list<int> times;
    map<int, pair<list<int>::iterator, int> > hash;
    int capacity;
    int length;
public:
    LRUCache(int capacity);
    int get(int key);
    void set(int key, int value);
    void updateTime(map<int, pair<list<int>::iterator, int> >::iterator hashIt, int key);
};

class LRUCacheV1 {
private:
    map<int, pair<int, int> > times;
    map<int, pair<int, int> > hash;
    int time;
    int capacity;
    int length;
public:
    LRUCacheV1(int capacity);
    int get(int key);
    void set(int key, int value);
};

class LRUCacheLinear{
private:
    deque<pair<int, int> > q;
    int capacity;
public:
    LRUCacheLinear(int capacity);
    int get(int key);
    void set(int key, int value);
};

void printMap(map<int, int> m);
void printMap2(map<int, pair<int, int> > m);



