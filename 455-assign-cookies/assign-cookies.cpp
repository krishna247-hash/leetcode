class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int cnt = 0;
       
       int g1 = 0; int s1 = 0;
       while(s1 < s.size() && g1 < g.size())
       {
        if(g[g1] <= s[s1])
        {
            cnt++;
            g1++;
            s1++;
        }
        else s1++;
       }
        return cnt;
    }
};