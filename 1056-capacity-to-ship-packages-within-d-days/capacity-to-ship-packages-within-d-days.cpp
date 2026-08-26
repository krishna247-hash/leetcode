class Solution {
public:

      int maxElement(vector<int>& nums)

    {

        int maxi = INT_MIN;

        for(auto it : nums)

        {

            maxi = max(maxi, it);

        }

        return maxi;

    }

    int totalSum(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;

        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
        }

        return sum;
    }

    int countDays(vector<int> &nums , int capacity)
    {
        int countDay = 1;  int cnt = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            cnt += nums[i];

            if(cnt > capacity)
            {
                cnt = nums[i];

                countDay++;
            }
        }

        return countDay;
    }


    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int low = maxElement(weights);  int high = totalSum(weights);

        int ans = high;

        while(low <= high)
        {
            int mid = low + (high - low)/2;

            int totalDays = countDays(weights,mid);

            if(totalDays <= days)
            {
                ans = mid;

                high = mid - 1;
            } 
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }

    
};