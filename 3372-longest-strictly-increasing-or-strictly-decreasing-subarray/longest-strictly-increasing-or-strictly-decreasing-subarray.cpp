class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        int cnt = 1;
        for(int i = 1; i < n; i++)
        {
            if(nums[i-1] < nums[i])
                cnt++;
            else 
                cnt = 1;

                ans = max(ans,cnt);
        }

        reverse(nums.begin(),nums.end());

        cnt = 1;
        for(int i = 1; i < n; i++)
        {
            if(nums[i-1] < nums[i])
                cnt++;
            else 
                cnt = 1;

                ans = max(ans,cnt);
        }

        return ans;
    }
};