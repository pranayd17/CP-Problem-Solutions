#include <bits/stdc++.h>
using namespace std;

int capacity;
int currentTime;
map<int, int> cache;
map<int, int> timeToKey;
map<int, int> keyToTime;

LRUCache::LRUCache(int capacityValue)
{
capacity = capacityValue;
currentTime = 0;
cache.clear();
timeToKey.clear();
keyToTime.clear();
}

int LRUCache::get(int key)
{
if(cache.find(key) == cache.end())
return -1;
int oldTime = keyToTime[key];
keyToTime.erase(key);
timeToKey.erase(oldTime);
keyToTime[key] = currentTime;
timeToKey[currentTime] = key;
currentTime++;
return cache[key];
}

void LRUCache::set(int key, int value)
{
if(cache.find(key) != cache.end())
{
int oldTime = keyToTime[key];
keyToTime.erase(key);
timeToKey.erase(oldTime);
keyToTime[key] = currentTime;
timeToKey[currentTime] = key;
currentTime++;
cache[key] = value;
return;
}
if(cache.size() == capacity)
{
int leastRecentlyUsed = (*timeToKey.begin()).second;
timeToKey.erase(timeToKey.begin());
keyToTime.erase(leastRecentlyUsed);
cache.erase(leastRecentlyUsed);
cache[key] = value;
keyToTime[key] = currentTime;
timeToKey[currentTime] = key;
currentTime++;
return;
}
cache[key] = value;
keyToTime[key] = currentTime;
timeToKey[currentTime] = key;
currentTime++;
return;
}
