class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = 1e7;

        for(int i = 0; i < nums.size(); i++)
        {
             int x = 0;
            for(int j = i ; j < nums.size(); j++)
            {
                x += nums[j];
               if(x > 0 && j-i+1 >= l && j-i+1 <= r) ans = min(x,ans);
            }
        }

        return (ans == 1e7)? -1:ans;
    }
};