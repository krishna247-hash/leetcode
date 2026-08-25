class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n = nums.size();

        int e1 = -1;  int e2 = -1;

        int low = 0; int high = n-1;

        while(low <= high)
        {
            int mid = low + (high - low)/2;

            if(nums[mid] == target)
            {
               e1 = mid;
               high = mid - 1;
            }
            else if(nums[mid] > target){
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }



     low = 0; high = n-1;

        while(low <= high)
        {
            int mid = low + (high - low)/2;

            if(nums[mid] == target)
            {
               e2 = mid;
               low = mid + 1;
            }
            else if(nums[mid] > target){
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return {e1,e2};
    }
};