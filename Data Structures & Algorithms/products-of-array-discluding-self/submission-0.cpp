class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int count = 0; int pos; int prod = 1;
        vector<int> ans(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 0){
                count ++;
                pos = i;
            }
            if (count > 1) return ans;
        }
        if (count == 1){
            for (int i = 0; i < nums.size(); i++){
                if (i != pos){
                    prod *= nums[i];
                }
            }
            ans[pos] = prod;
            return ans;
        }
        for (int i = 0; i < nums.size(); i++){
            prod *= nums[i];
        }
        for (int i = 0; i < nums.size(); i++){
            ans[i] = prod / nums[i];
        }
        return ans;
    }
};
