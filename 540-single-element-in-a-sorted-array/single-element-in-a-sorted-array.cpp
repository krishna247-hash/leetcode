class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

       int n = nums.size();

       int low = 0;  int high = n-1;

       int e;

       while(low <= high)
       {
        int mid = low + (high - low)/2;

        if(mid < n-1 && nums[mid+1] == nums[mid])
        {
            e = mid;
        }
        else if(mid > 0 && nums[mid] == nums[mid - 1])
        {
            e = mid - 1;
        }
        else
        {
            return nums[mid];
        }

        if(e % 2 == 0)
        {
            low = e + 2;
        }
        else
        {
            high = e - 1;
        }
       }

     
          return -1; 
    }
};