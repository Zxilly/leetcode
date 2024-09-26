/*
 * @lc app=leetcode.cn id=146 lang=cpp
 * @lcpr version=30204
 *
 * [146] LRU 缓存
 */


// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
#ifdef LC_LOCAL
#include "leetcode/parser.hpp"
#endif
// @lcpr-template-end
// @lc code=start
class LRUCache {
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        auto it = mp[key];
        auto [k, v] = *it;
        cache.erase(it);
        cache.push_front({k, v});
        mp[key] = cache.begin();
        return v;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            auto it = mp[key];
            cache.erase(it);
        } else if (cache.size() == capacity) {
            auto [k, v] = cache.back();
            cache.pop_back();
            mp.erase(k);
        }

        cache.push_front({key, value});
        mp[key] = cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end



