class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashmap = {};
        for (string s : strs){
            vector<int> count(26,0);
            for (char c : s){
                count[c - 'a']++;
            }
            string key ="";
            for (int x : count){
                key += to_string(x) + "#";
            }
            hashmap[key].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto p : hashmap) {
            ans.push_back(p.second);
        }
        return ans;
    }
};
