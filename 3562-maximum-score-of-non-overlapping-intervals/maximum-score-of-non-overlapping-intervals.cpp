class Solution {
public:

    vector<int> maximumWeight(vector<vector<int>>& intervals) 
    {
        int n = intervals.size();

        // {start, end, weight, original_index}
        vector<array<int,4>> a;

        for(int i = 0; i < n; i++)
        {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by starting point
        sort(a.begin(), a.end());

        // Store starting points
        vector<int> starts(n);

        for(int i = 0; i < n; i++)
        {
            starts[i] = a[i][0];
        }

        // Find next non-overlapping interval
        vector<int> next(n);

        for(int i = 0; i < n; i++)
        {
            next[i] = upper_bound(
                starts.begin(),
                starts.end(),
                a[i][1]
            ) - starts.begin();
        }

        // dp[i][k] = best answer from i using at most k intervals
        vector<vector<pair<long long, vector<int>>>> dp(
            n + 1,
            vector<pair<long long, vector<int>>>(5)
        );

        for(int i = n - 1; i >= 0; i--)
        {
            for(int k = 1; k <= 4; k++)
            {
                // Don't take
                auto notTake = dp[i + 1][k];

                // Take
                auto take = dp[next[i]][k - 1];

                take.first += a[i][2];
                take.second.push_back(a[i][3]);

                sort(take.second.begin(), take.second.end());

                if(take.first > notTake.first)
                {
                    dp[i][k] = take;
                }
                else if(take.first < notTake.first)
                {
                    dp[i][k] = notTake;
                }
                else
                {
                    dp[i][k] = min(take, notTake);
                }
            }
        }

        return dp[0][4].second;
    }
};