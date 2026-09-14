class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> ans;
        for(auto it: matrix)
        {
            int cnt = 0;
            for(auto x : it)
            {
                if(x == 1) cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};