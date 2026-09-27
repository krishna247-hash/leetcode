class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st1;
        string ans;
        
        for(auto it: s)
        {

            string temp = "";
            if(it == ')')
            {
                while(st1.top() != '(')
                {
                    temp += st1.top();
                    st1.pop();
                }
                st1.pop();
                for(auto x: temp)
                st1.push(x);

            }
            else 
            st1.push(it);
        }

        while(st1.size() != 0)
        {
            ans += st1.top();
            st1.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};