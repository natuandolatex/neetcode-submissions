class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0; int r = heights.size()-1; 
        int ans = (r - l)*min(heights[l], heights[r]);
        while (l < heights.size()-1){
            l++; r = heights.size()-1;
            while (r > l){
                ans = max(ans, (r - l)*min(heights[l], heights[r]));
                r--;
            }
        }
        return ans;
    }
};
