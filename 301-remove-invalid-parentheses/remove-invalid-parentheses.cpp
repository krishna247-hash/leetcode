#define ll int
#define pb push_back
class Solution {
public:
    bool isValid(string s)
    {
        int cnt = 0;
        for(char ch : s)
        {
            if(ch == '(')
                cnt++;
            else if(ch == ')')
            {
                if(cnt == 0) return false;
                cnt--;
            }
        }
        return cnt == 0;
    }
    void solve(ll x, ll start, string& s, vector<string>& ans)
    {
        if(x == 0)
        {
            if(isValid(s))
                ans.pb(s);
            return;
        }
        for(ll j = start; j < s.size(); j++)
        {
            if(j > start && s[j] == s[j-1])
                continue;
            if(s[j] != '(' && s[j] != ')')
                continue;
            char ch = s[j];
            s.erase(j, 1);
            solve(x - 1, j, s, ans);
            s.insert(j, 1, ch);
        }
    }
    vector<string> removeInvalidParentheses(string s)
    {
        vector<string> ans;
        stack<char> st;
        ll cnt = 0;
        for(char ch : s)
        {
            if(ch == '(')
                st.push('(');
            else if(ch == ')')
            {
                if(st.empty())
                    cnt++;
                else
                    st.pop();
            }
        }
        ll x = cnt + st.size();
        solve(x, 0, s, ans);
        return ans;
    }
};