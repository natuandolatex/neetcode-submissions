class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0; int r = height.size() - 1;
        int maxleft = 0; int maxright = 0;
        int water = 0;
        while (l < r){
            if (height[l] < height[r]){
                maxleft = max(maxleft, height[l]);
                water += maxleft - height[l];
                l++;
            }
            else {
                maxright = max(maxright, height[r]);
                water += maxright - height[r];
                r--;
            }
        }
        return water;
    }
};
