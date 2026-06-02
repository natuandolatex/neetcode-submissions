class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_area = 0; int n = heights.size();
        vector<int> left_boundary(n, 0);
        vector<int> right_boundary(n, 0);
        stack<int> right_stack;
        int i = 1; right_stack.push(0);
        while (i < n){
            while ((i < n) and (heights[i] >= heights[right_stack.top()])){
                right_stack.push(i);
                i++;
            }
            while ((!right_stack.empty()) and (i < n) and (heights[i] < heights[right_stack.top()])){
                right_boundary[right_stack.top()] = i-1;
                right_stack.pop();
            }
            if (i < n) {
                right_stack.push(i);
                i++;
            }
        }
        if (!right_stack.empty()) {
            while (!right_stack.empty()){
                right_boundary[right_stack.top()] = n-1;
                right_stack.pop();
            }
        }
        stack<int> left_stack;
        i = n-2; left_stack.push(n-1);
        while (i >= 0){
            while ((i >= 0) and (heights[i] >= heights[left_stack.top()])){
                left_stack.push(i);
                i--;
            }
            while ((!left_stack.empty()) and (i >= 0) and (heights[i] < heights[left_stack.top()])){
                left_boundary[left_stack.top()] = i+1;
                left_stack.pop();
            }
            if (i >= 0) {
                left_stack.push(i);
                i--;
            }
        }       
        while (!left_stack.empty()){
            left_boundary[left_stack.top()] = 0;
            left_stack.pop();
        }
        for (int i = 0; i < n; i++) max_area = max(max_area, heights[i]*(right_boundary[i]-left_boundary[i]+1));
        return max_area;
    }
};