class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        sort(nums.begin(),nums.end());
        int prev = nums[0];
        int cnt = 1;
        int k = n / 3;

        for(int i = 1; i < n; i++)
        {
            if(prev != nums[i])
            {
                if(cnt > k)
                {
                    ans.push_back(prev);
                }
                prev = nums[i];
                cnt = 1;
            }
            else
            {
                cnt++;
            }
            
        }
        if(cnt > k)
        {
            ans.push_back(prev);
        }
        return ans;
    }
};