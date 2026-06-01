class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s){
            if ((c == '(') or (c == '[') or (c == '{')){
                st.push(c);
            }
            else{
                if (st.empty()) return false;
                if (((c == ')') and (st.top() == '(')) or ((c == ']') and (st.top() == '[')) or ((c == '}') and (st.top() == '{'))){
                    st.pop();
                }
                else return false;
            }
        }
        if (st.empty()){
            return true;
        }
        else return false;
    }
};
