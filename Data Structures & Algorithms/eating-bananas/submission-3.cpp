class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxRate = piles[0];
        for (int i = 1; i < n; i++) maxRate = max(maxRate, piles[i]);
        int l = 1; int r = maxRate; int ans = maxRate;
        while (l <= r){
            int mid = l + (r-l)/2;
            int hours = 0;
            for (int i = 0; i < n; i++) hours += (piles[i] + mid - 1)/mid;
            if (hours <= h){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};