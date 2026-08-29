class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];

        for(int i = 1; i < strs.size(); i++)
        {
            int t = min(ans.size(),strs[i].size());

            string common = "";

            for(int j = 0; j < t; j++)
            { 
                if(ans[j] != strs[i][j])
                {
                    break;
                }
                else
                {
                    common += ans[j];
                }
            }

            ans = common;

        }

        return ans;
    }
};