class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> temp(n+1,0);
        for(int i = 1; i <= nums.size(); i++)
        {
            temp[i] = temp[i-1] + nums[i-1];
        }

        for(int i = 0; i < queries.size(); i++)
        {
            int q = queries[i];
            int tempAns = 0;
            int low = 0; int high = n;
            while(low <= high)
            {
                int mid = low + (high - low) / 2;

                if(temp[mid] <= q)
                {
                    tempAns = mid;
                    low = mid + 1;

                }
                else high = mid - 1;
            }
            ans.push_back(tempAns);
        }
        return ans;
    }
};