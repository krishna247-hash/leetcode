#define ll int
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        ll sum = 0;
        ll ans = nums[0];

        for(ll i = 0; i < nums.size(); i++)
        {
            sum = max(nums[i], sum + nums[i]);
            ans = max(ans,sum);
        }

        return ans;
    }
};