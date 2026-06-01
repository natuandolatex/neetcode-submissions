class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string s : tokens){
            if ((s != "+") and (s != "-") and (s != "*") and (s != "/")){
                st.push(stoi(s));
            }
            else{
                if (s == "+"){
                    int a = st.top(); st.pop();
                    int b = st.top(); st.pop();
                    st.push(b + a);
                }
                if (s == "-"){
                    int a = st.top(); st.pop();
                    int b = st.top(); st.pop();
                    st.push(b - a);
                }
                if (s == "*"){
                    int a = st.top(); st.pop();
                    int b = st.top(); st.pop();
                    st.push(b * a);
                }
                if (s == "/"){
                    int a = st.top(); st.pop();
                    int b = st.top(); st.pop();
                    st.push(b / a);
                }
            }
        }
        return st.top();
    }
};
