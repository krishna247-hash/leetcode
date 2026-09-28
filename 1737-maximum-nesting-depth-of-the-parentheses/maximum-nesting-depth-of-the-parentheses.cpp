class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int cnt = 0;
        for(auto& it: s)
        {
           
            if(it == '(')
            {
                cnt++;
                ans = max(ans,cnt);
            }
            else if(it == ')') cnt--;
        }
        return ans;
    }
};