#define M 1000000007
#define ll int
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        ll n = nums.size();
        vector<int> bits(32,0);
        for(ll i = 0; i < n; i++)
        {
            for(ll j = 0; j < 32; j++)
            {
                if(nums[i] & (1 << j)) bits[j]++;
            }
        }
        ll ans = 0;

        while(k--)
        {
            ll x = 0;
            for(ll i = 0; i < 32; i++)
            {
                if(bits[i] > 0)
                {
                    x += (1 << i);
                    bits[i]--;
                }
            }
           x = (1LL * x * x) % M;
            ans = ((ans%M) + (x%M))%M;

        }

        return ans;
    }
};