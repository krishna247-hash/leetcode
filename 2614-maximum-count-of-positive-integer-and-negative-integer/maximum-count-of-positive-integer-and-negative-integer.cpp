class Solution {
public:
    
    int totalPositive(vector<int>& nums)
    {
        int n = nums.size();
        int low = 0;  int high = nums.size() - 1;
        int ans = n;
        while(low <= high)
        {
            int mid = low + (high - low)/2;

            if(nums[mid] > 0){
                ans = mid;

                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
            
        }

        return n - ans;

    }

    int totalNegative(vector<int>& nums){
        int n = nums.size();
        int low = 0;  int high = nums.size() - 1;
        int ans = -1;

        while(low <= high)
        {
            int mid = low + (high - low)/2;

            if(nums[mid] < 0){
                ans = mid;

                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
            
        }

        return ans+1;

        
    }


    int maximumCount(vector<int>& nums) {
        int positive = totalPositive(nums);

        int negative = totalNegative(nums);

        return max(positive,negative);
    }
};