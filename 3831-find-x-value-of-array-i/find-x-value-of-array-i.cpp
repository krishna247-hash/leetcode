class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> temp(k, 0);

        for (int i = 0; i < nums.size(); i++) {
            vector<long long> curr(k, 0);

            int x = nums[i] % k;

            // Subarray containing only nums[i]
            curr[x]++;

            // Extend previous subarrays
            for (int j = 0; j < k; j++) {
                int rem = (j * x) % k;
                curr[rem] += temp[j];
            }

            // Add all subarrays ending at i
            for (int j = 0; j < k; j++) {
                ans[j] += curr[j];
            }

            temp = curr;
        }

        return ans;
    }
};