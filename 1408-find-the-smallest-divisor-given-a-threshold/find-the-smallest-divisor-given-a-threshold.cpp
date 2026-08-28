class Solution {
public:
     int maxElement(vector<int> &nums)
     {
        int maxi = INT_MIN;
        for(auto it: nums)
        {
            maxi = max(maxi,it);
        }

        return maxi;
     }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();

        int maxi = maxElement(nums);

        int low = 1;  int high = maxi;

        int ans = maxi;

        while(low <= high){

            int mid = low + (high - low)/2;
            int sum = 0;

            for(auto x : nums){
                sum += x / mid;

                if(x % mid != 0) sum++;
               
            }

            if(sum <= threshold)
            {
                high = mid - 1;

                 ans = mid;

            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;

    
    }
};