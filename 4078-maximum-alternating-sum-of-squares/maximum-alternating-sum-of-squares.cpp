class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(auto & it: nums)
        {
            it = abs(it);
        }
        sort(nums.begin(),nums.end());
        long long ans = 0;
        int l = 0, h = nums.size()-1;
        if(nums.size() == 1) {
            ans += nums[0]*nums[0];
            h--;
        }

        while(l <= h)
        {
            ans += nums[h]*nums[h];
            h--;
            if(l <= h)
            ans -= nums[l]*nums[l];
            
            l++;
        }

        return ans;
    }
};