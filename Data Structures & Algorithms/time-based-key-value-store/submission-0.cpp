class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> hashmap;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hashmap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (hashmap.find(key) == hashmap.end()){
            return "";
        }
        auto vec = hashmap[key]; string ans = "";
        int l = 0, r = vec.size()-1;
        while (l <= r){
            int mid = l + (r-l)/2;
            if (vec[mid].first <= timestamp){
                ans = vec[mid].second;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return ans;
    }
};
