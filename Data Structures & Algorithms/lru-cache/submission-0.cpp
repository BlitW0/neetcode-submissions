class LRUCache {
public:
    int capacity;
    list <int> order;
    unordered_map <int, pair <int, list<int>::iterator > > cache;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (not cache.contains(key)) return -1;
        
        // remove old entry using stored itr and push to most recen
        order.erase(cache[key].second);
        order.push_back(key);

        // store new itr and ret val
        cache[key].second = prev(order.end());
        return cache[key].first;
    }
    
    void put(int key, int value) {
        if (cache.contains(key)) // remove old entry
            order.erase(cache[key].second);
        else if (cache.size() == capacity) {
            // cache full, remove lru from order and cache
            int lru = order.front();
            order.pop_front();
            cache.erase(lru);
        }
        
        // push key to most recent in order
        order.push_back(key);
        cache[key] = {value, prev(order.end())};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */