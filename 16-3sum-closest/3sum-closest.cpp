class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        int ans = nums[0] + nums[1] + nums[2];

        for(int i = 0; i < n - 2; i++)
        {
            int j = i + 1;
            int k = n - 1;

            while(j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];

                // Check whether current sum is closer
                if(abs(target - sum) < abs(target - ans))
                {
                    ans = sum;
                }

                if(sum < target)
                {
                    j++;
                }
                else if(sum > target)
                {
                    k--;
                }
                else
                {
                    // Exact answer
                    return sum;
                }
            }
        }

        return ans;
    }
};