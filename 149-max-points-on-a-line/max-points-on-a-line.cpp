class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {

        int n = points.size();

        if(n <= 2)
            return n;

        int ans = 0;

        for(int j = 0; j < n; j++)
        {
            unordered_map<double, int> mp;

            for(int i = 0; i < n; i++)
            {
                if(i == j)
                    continue;

                double slope;

                if(points[i][0] == points[j][0])
                {
                    slope = 1e9;
                }
                else
                {
                    slope = (double)(points[i][1] - points[j][1]) /
                            (points[i][0] - points[j][0]);
                }

                mp[slope]++;
            }

            for(auto it : mp)
            {
                ans = max(ans, it.second + 1);
            }
        }

        return ans;
    }
};