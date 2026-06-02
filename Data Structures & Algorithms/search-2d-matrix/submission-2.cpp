class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); int n = matrix[0].size();
        if ((target < matrix[0][0]) or (target > matrix[m-1][n-1])) return false;
        int l = 0; int r = m - 1; int row;
        while (l <= r){
            if (l == r){
                row = l;
                break;
            }
            int mid = l + (r-l)/2;
            if (matrix[mid][0] == target) return true;
            if (matrix[mid][0] > target){
                r = mid - 1;
            }
            else l = mid + 1;
        }
        if (matrix[row][0] == target) return true;
        if (matrix[row][0] > target){
            if (matrix[row][n-1] > target) row--;
        }
        else if (matrix[row][n-1] < target) row++;
        l = 0; r = n - 1;
        while (l <= r){
            int mid = l + (r-l)/2;
            if (matrix[row][mid] == target) return true;
            if (matrix[row][mid] > target){
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return false;
    }
};