class Solution {
public:
    void subsets(int i,vector<int>& nums, vector<int>& temp,unordered_map<int,int>& mp)
    {
        if(i == nums.size())
        {
            int sum = 0;
            if(temp.size() == 0) return;
            for(auto it : temp)
            {
                sum = sum | it;
            }
            mp[sum]++;

            return;
        }
        temp.push_back(nums[i]);
        subsets(i+1,nums,temp,mp);
        temp.pop_back();
        subsets(i+1,nums,temp,mp);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        vector<int> temp;
        unordered_map<int,int> mp;
        subsets(0,nums,temp,mp);
        int ans = INT_MIN;
        for(auto it: mp)
        {
            ans = max(ans,it.second);
        }
        return ans;
    }
};