class Solution {
public:
    bool check(string& temp)
    {
        stack<char> st;
        for(auto it: temp)
        {
            if(it == '(')
            {
                st.push(')');
            }
            if(it == ')')
            {
                if(st.empty()) return false;
                if(st.top() == ')') 
                    st.pop();
            }
        }

        return st.empty();
    }
    void solve(int i,int n, string& temp, vector<string>&ans)
    {
        if(i >= n)
        {
            if (check(temp))
            {
                ans.push_back(temp);
            }
            return;
        }

        temp[i] = '(';
        solve(i+1,n,temp,ans);
        temp[i] = ')';
        solve(i+1,n,temp,ans);
        

    }
    vector<string> generateParenthesis(int n) {
        string temp = "";
        for(int i = 0; i < 2*n; i++)
            temp += '(';
        vector<string> ans;
        solve(0,2*n,temp,ans);
        return ans;
    }
};