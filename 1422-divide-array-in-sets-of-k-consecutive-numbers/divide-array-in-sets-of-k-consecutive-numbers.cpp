class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(nums.size() % k != 0) return 0;
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mp;
        for(auto it: nums)
        {
            mp[it]++;
        }
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(mp[nums[i]] > 0)
            {
                int x = nums[i];
                bool flag = 0;
                for(int i = 0; i < k; i++)
                {
                    if(mp[x+i] <= 0) return false;
                }
                if(!flag)
                {
                    for(int i = 0; i < k; i++)
                {
                   mp[x+i]--;
                }
                cnt++;
                }
            }
        }

        return true;
    }
};