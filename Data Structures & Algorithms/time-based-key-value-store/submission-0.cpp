class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> keyStore;
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        keyStore[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        auto& values = keyStore[key];
        int l = 0, r = values.size() - 1;

        string res = "";

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (values[m].first <= timestamp) {
                res = values[m].second;
                l = m + 1;
            } else r = m - 1;
        }

        return res;
    }
};
