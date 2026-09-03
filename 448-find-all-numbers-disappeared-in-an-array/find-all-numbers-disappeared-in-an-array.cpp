class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int maxi = nums.size();
        unordered_map<int,int> mp;
        for(auto it: nums)
        {
            mp[it]++;
        }
        vector<int> temp;
        for(int i = 1; i <= maxi; i++)
        {
            if(mp[i] == 0) temp.push_back(i);
        }
        return temp;

    }
};