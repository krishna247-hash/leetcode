class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        vector<int> mini(n, INT_MAX);

        int low = 0;
        int sum = 0;
        int ans = INT_MAX;
        int best = INT_MAX;

        for(int high = 0; high < n; high++)
        {
            sum += arr[high];

            while(sum > target)
            {
                sum -= arr[low];
                low++;
            }

            if(high > 0)
                mini[high] = mini[high - 1];

            if(sum == target)
            {
                int len = high - low + 1;

                // Previous subarray must end before low
                if(low > 0 && mini[low - 1] != INT_MAX)
                {
                    ans = min(ans, len + mini[low - 1]);
                }

                best = min(best, len);
                mini[high] = min(mini[high], best);
            }
        }

        if(ans == INT_MAX)
            return -1;

        return ans;
    }
};