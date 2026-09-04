class Solution {
public:
    string removeOuterParentheses(string s) {
        // we can use stack too
        string ans;
        int cnt = 0;
        for(auto it: s)
        {
            if(it == ')') cnt--;
            if(cnt != 0) ans += it;
            if(it =='(') cnt++;
        }
        return ans;
    }
};