class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> hashrow(9);
        vector<unordered_set<char>> hashcol(9);
        vector<unordered_set<char>> hashsq(9);
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                char value = board[i][j];
                if (value == '.'){
                    continue;
                }
                int sqi = (i/3)*3 + j/3;
                if ((hashrow[i].count(value)) or (hashcol[j].count(value)) or (hashsq[sqi].count(value))){
                    return false;
                }
                hashrow[i].insert(value);
                hashcol[j].insert(value);
                hashsq[sqi].insert(value);
            }
        }
        return true;
    }
};
