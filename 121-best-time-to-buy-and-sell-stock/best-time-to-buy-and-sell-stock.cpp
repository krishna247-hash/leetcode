class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int mini = 0;
        int profit = 0;
        int n = nums.size();

        for (int i = 1; i < n; i++) {

            if (nums[i] < nums[mini]) {
                mini = i;
            }
            else {
                profit = max(profit, nums[i] - nums[mini]);
            }
        }

        return profit;
    }
};