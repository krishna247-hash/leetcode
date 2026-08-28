class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int low = 0 , high = n-1;
        int mini = INT_MAX;

        while(low <= high)
        {
            int mid = low + (high - low)/2;

            if(nums[low] == nums[mid] && nums[high] == nums[mid])
            {

                high--;
                low++;
                mini = min(nums[mid],mini);
            }
            else if(nums[mid] >= nums[low]){
                mini = min(nums[low],mini);

                low = mid + 1;
            }
            else
            {
                mini = min(nums[mid],mini);
                high = mid - 1;
            }
        }

        return mini;

    }
};