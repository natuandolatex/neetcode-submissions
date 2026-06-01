class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0; int right = s.length() - 1;
        while (left < right){
            while (!isalnum(s[left])){
                left++;
                if (left == right) return true;
            }
            while (!isalnum(s[right])){
                right--;
                if (right == left) return true;
            }
            if (tolower(s[left]) != tolower(s[right])){
                return false;
            }
            left++; right--;
        }
        return true;
    }
};
