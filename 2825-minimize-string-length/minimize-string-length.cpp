class Solution {
public:
    int minimizedStringLength(string s) {
        if(s.size() == 1 || s.size() == 0) return s.size();
        int cnt = 0;
        int ans[26] = {0};
        for(auto it: s)
        {
            if(ans[it - 'a'] == 0)
            {
                ans[it - 'a'] = 1;
                cnt++;
            }
        }        
        return cnt;

    }

};