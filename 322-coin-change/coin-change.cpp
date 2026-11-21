class Solution {
public:
    long long fun(long long x,vector<int>&c,vector<long long>& dp)
    {
        if(x == 0)return 0;
        if(x < 0)return 1e9;
        if(dp[x] != -1)return dp[x];

        long long mn = 1e9;
        for(auto& it: c)
        {
            if(it > x)break;
            mn = min(mn,1LL+fun(x-it,c,dp));
        }

        return dp[x] = mn;
    }
    int coinChange(vector<int>& c, int amount) {
        sort(c.begin(),c.end());
        vector<long long> dp(amount+1,-1);
        long long x = fun(amount,c,dp);
        return (x >= 1e9)?-1 : x;
    }
};

