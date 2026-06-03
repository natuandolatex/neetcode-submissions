class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (nums[0] < nums[n - 1]) return nums[0];
        if (nums[n-1] < nums[n-2]) return nums[n-1];
        int l = 1; int r = n-2;
        while (l <= r){
            if (nums[l] < nums[r]) return nums[l];
            int mid = l + (r-l)/2;
            if (nums[mid-1] < nums[mid] and nums[mid] < nums[mid + 1]){
                if (nums[mid] > nums[l]){
                    l = mid + 1;
                }
                else r = mid - 1;
            }
            else return min(nums[mid], nums[mid+1]);
        }
    }
};