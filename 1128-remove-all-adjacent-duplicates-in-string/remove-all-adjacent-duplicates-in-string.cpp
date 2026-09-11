class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(auto it: s)
        {
            if(!st.empty() && st.top() == it)
            {
                st.pop();
            }
            else
            {
                st.push(it);
            }
        }

         string t ="";

        while(!st.empty())
        {
            t += st.top();
            st.pop();
        }
        reverse(t.begin(),t.end());
        return t;
    }
};