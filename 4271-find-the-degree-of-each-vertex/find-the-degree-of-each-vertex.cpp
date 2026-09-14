class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> ans(matrix.size(),0);
        for(int i = 0; i < matrix.size(); i++)
        {

            for(auto x : matrix[i])
            {
                ans[i] += x;
            }

        }
        return ans;
    }
};