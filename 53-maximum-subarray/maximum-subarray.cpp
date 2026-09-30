class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum = max(nums[i],nums[i]+sum);
            ans = max(ans,sum);
        }
        return ans;
    }
};