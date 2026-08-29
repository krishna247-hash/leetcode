class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n == 1) return 0;
        int maxi = 0;
        for(int i = 1; i < n; i++)
        {
            maxi = max(maxi,nums[i]-nums[i-1]);
        }
        return maxi;
    }
};