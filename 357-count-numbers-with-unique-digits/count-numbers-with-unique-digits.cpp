class Solution {
public:
    
    int countNumbersWithUniqueDigits(int n) {
        vector<long long > dp(9);
        dp[0] = 1; dp[1] = 9; dp[2] = 9 * 9;
        for(int i = 3; i < 9; i++)
        {
            dp[i] = dp[i-1]*(11-i);
        }

        int ans = 0;
        for(int i = 0; i <= n; i++)
        {
            ans += dp[i];
        }

        return ans;
    }
};