class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size() - 2; i++){
            if ((i > 0) and (nums[i] == nums[i-1])) continue;
            int j = i + 1; int k = nums.size()-1;
            while (j < k){
                if (nums[i] + nums[j] + nums[k] == 0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++; k--;
                    while ((nums[j] == nums[j-1]) and (j < k)) j++;
                    while ((nums[k] == nums[k+1]) and (k > j)) k--;
                }
                else if (nums[i] + nums[j] + nums[k] > 0){
                    k--;
                }
                else j++;
            }
        }
        return ans;
    }
};
