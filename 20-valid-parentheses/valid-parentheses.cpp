class Solution {
public:
    bool isValid(string s) {
        int e1 = 0;
        int n = s.size();
        if(n % 2 != 0) return 0;
        stack<char> st;
        if(s[0] == '(') st.push(')');
        else if(s[0] == '[') st.push(']');
        else if(s[0] == '{') st.push('}');
        else return 0;

        for(int i = 1; i < n; i++)
        {
            if(!st.empty())
            {
                if(st.top() == s[i]) st.pop();
                else if(s[i] == '(') st.push(')');
                else if(s[i] == '[') st.push(']');
                else if(s[i] == '{') st.push('}');
                else return false;
            }
            else
            {
                if(s[i] == '(') st.push(')');
                else if(s[i] == '[') st.push(']');
                else if(s[i] == '{') st.push('}');
                else return false;

            }
        }
        return (st.empty());
        
    }
};