class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, n = nums.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        int breakPoint = l;
        if (breakPoint == 0){
            l = 0; r = n-1;
            while (l <= r){
                int mid = l + (r-l)/2;
                if (nums[mid] == target) return mid;
                if (nums[mid] > target){
                    r = mid - 1;
                }
                else l = mid + 1;
            }
            return -1;
        }
        if (target < nums[breakPoint] or target > nums[breakPoint-1]) return -1;
        if (target <= nums[n-1]){
            l = breakPoint; r = n-1;
            while (l <= r){
                int mid = l + (r-l)/2;
                if (nums[mid] == target) return mid;
                if (nums[mid] > target){
                    r = mid - 1;
                }
                else l = mid + 1;
            }
            return -1;
        }
        else {
            l = 0; r = breakPoint-1;
            while (l <= r){
                int mid = l + (r-l)/2;
                if (nums[mid] == target) return mid;
                if (nums[mid] > target){
                    r = mid - 1;
                }
                else l = mid + 1;
            }
            return -1;
        }
    }
};
