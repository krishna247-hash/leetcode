class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < queries.size(); i++)
        {
            int sum = 0;
            int cnt = 0;
            while(cnt < nums.size() && sum + nums[cnt] <= queries[i])
            {
                sum += nums[cnt];
                cnt++;
            }
            ans.push_back(cnt);
        }

        return ans;
    }
};