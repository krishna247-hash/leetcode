class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        for(auto& it: nums)
        sort(it.begin(),it.end());

        int                sum = 0;
        for(int i = 0; i < nums[0].size();i++)
        {
            int maxi = INT_MIN;
            for(int j = 0; j < nums.size(); j++)
            maxi = max(maxi , nums[j][i]);

            sum += maxi;
        }

        return sum;
    }
};