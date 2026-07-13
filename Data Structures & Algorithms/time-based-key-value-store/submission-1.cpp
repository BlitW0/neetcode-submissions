class TimeMap {
    unordered_map <string, vector <pair<int, string> > > store;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        store[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        auto& values = store[key];
        int lo = 0, hi = store[key].size() - 1, mid, ans = -1;
        while (lo <= hi) {
            mid = (lo + hi) >> 1;
            // try to find larger
            if (values[mid].first <= timestamp) {
                ans = mid;
                lo = mid + 1;
            } else
                hi = mid - 1;
        }
        return ans == -1 ? "" : values[ans].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */