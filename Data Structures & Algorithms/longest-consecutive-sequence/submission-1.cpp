class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> hashmap;
        for (int x : nums) hashmap[x] = 0;
        for (int x : nums){
            if (hashmap.count(x-1) == 0){
                int y = x; int count = 0;
                while (hashmap.count(y)){
                    count++;
                    y++;
                }
                hashmap[x] = count;
            }
        }
        int ans = 0;
        for (auto p : hashmap){
            ans = max(ans, p.second);
        }
        return ans;
    }
};
