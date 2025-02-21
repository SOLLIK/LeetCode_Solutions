class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back(make_pair(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        const vector<pair<int, string>>& values = mp[key];
        auto it = lower_bound(values.begin(), values.end(), timestamp, [](const pair<int, string>& a, int t) {
            return a.first < t;
        });
        if(it != values.end() && it->first == timestamp) {
            return it->second;
        }
        if(it == values.begin()) {
            return "";
        }
        return (it - 1)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */