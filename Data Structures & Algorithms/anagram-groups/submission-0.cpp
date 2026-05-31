class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> hashmap = {};
        for (string s : strs){
            vector<int> count(26,0);
            for (char c : s){
                count[c - 'a']++;
            }
            hashmap[count].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto p : hashmap) {
            ans.push_back(p.second);
        }
        return ans;
    }
};
