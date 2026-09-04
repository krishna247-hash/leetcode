class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string temp ="";
        string ans ="";
        for(auto it : s)
        {
         if(it != ' ')
         {
            temp += it;
         }
         else
         {
            if(temp != ""){
                st.push(temp);
            }
            
            temp = "";
         }
        }

        if(s[s.size()-1] != ' ') st.push(temp);

        ans += st.top();
        st.pop();

        while(!st.empty())
        {
            ans += " ";
            ans += st.top();
            st.pop();
        }

        

        return ans;
    }
};