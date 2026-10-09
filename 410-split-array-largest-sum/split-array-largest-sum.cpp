#define pb push_back
class Solution {
public:
    
    bool check(int mid, vector<int>& nums, int k)
    {
        int cnt = 1;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(sum + nums[i] <= mid)
            {
                sum += nums[i];
            }
            else
            {
                sum = nums[i];
                cnt++;
            }
        }

        return cnt <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
       
        int low = *max_element(nums.begin(),nums.end());
       int high = 0;
        for(int i = 0; i < nums.size(); i++)
        high += nums[i];

        
        if(k == 1) return high;

        int ans = INT_MAX;
        while(low < high)
        {
            int mid = low + (high - low) / 2;
            if(check(mid,nums,k))
            {
                high = mid  ;
            }
            else low = mid + 1;
        }


        return low;
    }
};