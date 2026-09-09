class Solution {
public:

     void parenthesis(int i, int n, string& s, vector<string>& ans)
    {
       if(s[0] == ')') return;
        if(i >= n )
        {
            stack<char> st;

            for(auto it : s)
            {
                if(!st.empty())
                {
                    if(it == ')' && st.top() == '(')
                    st.pop();
                    else
                    st.push(it);
                }
                else st.push(it);
                
            }

            if(st.empty()) ans.push_back(s);
            return;
        }

        s[i] = ')';
        parenthesis(i+1,n,s,ans);
        s[i] = '(';
        parenthesis(i+1,n,s,ans);
    }

    vector<string> generateParenthesis(int n) {
        string s = "";
        for(int i = 0; i < 2*n; i++)
        {
            s += '(';
        }
        vector<string> ans;
        parenthesis(0,2*n,s,ans);

        return ans;
    }
};