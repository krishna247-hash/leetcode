class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 1; i < n; i++)
        {
            nums[i] = nums[i] + nums[i-1];
        }

        for(int i = 0; i < queries.size(); i++)
        {
            int q = queries[i];
            int tempAns = -1;
            int low = 0; int high = n-1;
            while(low <= high)
            {
                int mid = low + (high - low) / 2;

                if(nums[mid] <= q)
                {
                    tempAns = mid;
                    low = mid + 1;

                }
                else high = mid - 1;
            }
            ans.push_back(tempAns + 1);
        }
        return ans;
    }
};