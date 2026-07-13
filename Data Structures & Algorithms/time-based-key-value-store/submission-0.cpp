class TimeMap {
    unordered_map <string, map <int, string> > store;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        store[key].insert( {timestamp, value} );
    }
    
    string get(string key, int timestamp) {
        // first val greater than x
        auto it = store[key].upper_bound(timestamp);
        return it == store[key].begin() ? "" : prev(it)->second;
    }
};
