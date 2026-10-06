class Solution {
public:
    int minAddToMakeValid(string s) {
        int left = 0;
        stack<char>st;

        for(auto it: s)
        {
            if(it == '(')
            {
                st.push(')');
            }
            else
            {
                if(!(st.empty()))
                {
                    st.pop();
                }
                else
                {
                    left++;
                }
            }
        }

        int ans = st.size() + left;

        return ans;
    }
};