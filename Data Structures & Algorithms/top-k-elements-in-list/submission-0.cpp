class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> freq(nums.size()+1);
        unordered_map<int, int> hashmap;
        for (int x : nums){
            hashmap[x]++;
        }
        for (auto p : hashmap){
            int key = p.first;
            int value = p.second;
            freq[value].push_back(key);
        }
        vector<int> ans = {};
        for (int i = freq.size()-1; i >= 0; i--){
            for (int x : freq[i]){
                ans.push_back(x);
                if (ans.size()==k){
                    return ans;
                }
            }
        }
        return ans;
    }
};
