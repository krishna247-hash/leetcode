class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = 1;
        unordered_map<int,int> dp;

        for(auto x: nums)
        {
            dp[x+1] = max(dp[x+1],dp[x]+1);
            dp[x] = max(dp[x] , dp[x-1] + 1);
            ans = max({ans,dp[x],dp[x+1]});
        }

        return ans;
    }
};