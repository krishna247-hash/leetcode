class Solution {
public:
    long long M = 1e9 + 7;

    int sumOfPower(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        long long ans = 0;
        long long sum = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            long long x = nums[i];

            // x is the maximum
            ans = (ans + x * x % M * (x + sum) % M) % M;

            // prepare for next maximum
            sum = (2 * sum + x) % M;
        }

        return ans;
    }
};