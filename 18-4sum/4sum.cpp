class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>> st;

        for(int low = 0; low < n - 3; low++)
        {
            for(int left = low+1; left < n - 2; left++)
            {
                int right = left+1;
                int high = n - 1;
                while(right < high)
                {
                    long long sum = (long long)nums[low] + nums[right] + nums[left] + nums[high];
                    if(sum == target)
                    {
                st.insert({nums[low] ,nums[right]  ,nums[left] , nums[high]});
                right++;
                high--;

                    }
                   
                else if(sum < target)
                 right++;
                else
                high--;
                }
            }
        }
        vector<vector<int>> temp;
        for(auto it : st)
        {
          temp.push_back(it);
        }
        return temp;
    }
};