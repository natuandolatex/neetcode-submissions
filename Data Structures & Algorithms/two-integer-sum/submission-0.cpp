class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashset;
        for (int i = 0; i < nums.size(); i++){
            int diff = target - nums[i];
            if (hashset.count(diff)){
                return {hashset[diff],i};
            }
            hashset[nums[i]] = i;
        }
        return {};
    }
};
