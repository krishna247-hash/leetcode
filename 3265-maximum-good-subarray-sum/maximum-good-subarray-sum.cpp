class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = -(1LL << 50);
        bool flag = 1;
        vector<long long> preSum(nums.size()+1,0);
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            preSum[i+1] = preSum[i] + nums[i];
            
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(mp.find(nums[i] - k) != mp.end())
            {
                flag = 0;
                int j = mp[nums[i]-k];
                if(ans < (preSum[i+1] - preSum[j]))
                {
                    ans = preSum[i+1] - preSum[j];
                }
            }
            if(mp.find(nums[i] + k) != mp.end())
            {
                flag = 0;
                int j = mp[nums[i]+k];
                if(ans < (preSum[i+1] - preSum[j]))
                {
                    ans = preSum[i+1] - preSum[j];
                }
            }

            if(mp.find(nums[i]) == mp.end() ||

               preSum[i] < preSum[mp[nums[i]]])

            {

                mp[nums[i]] = i;

            }
        }
        if(flag) ans = 0;

        return ans;

    }
};