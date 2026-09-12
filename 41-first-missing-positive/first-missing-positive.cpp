class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it: nums)
        {
            mp[it]++;
        }
        for(int i = 1; i <= nums.size(); i++)
        {
            if(mp[i] == 0) return i;
        }
        return nums.size()+1;
    }
};