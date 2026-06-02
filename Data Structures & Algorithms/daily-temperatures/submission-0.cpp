class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int max = temperatures[0]; int n = temperatures.size();
        stack<int> st; st.push(0);
        vector<int> ans(n, 0);
        int i = 1;
        while (i < n){
            while ((i < n) and (temperatures[i] <= temperatures[st.top()])){
                st.push(i);
                i++;
            }
            if (i == n) return ans;
            int j = st.top();
            while ((!st.empty()) and (temperatures[st.top()] < temperatures[i])){
                ans[j] = i - j;
                st.pop();
                j = st.top();
            }
            st.push(i);
            i++;
        }
        return ans;
    }
};