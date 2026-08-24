class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {   
        int cnt = 0;

        unordered_map<int,int> mp;

        mp[0] = 1;
        int prefixSum = 0;
        for(int i = 0; i < nums.size();i++){

            prefixSum += nums[i];

            int suffixSum = prefixSum - k;

            cnt += mp[suffixSum];

            mp[prefixSum]++;
        }

        return cnt;
    }
};