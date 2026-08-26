class Solution {
public:

     int maxElement(vector<int>&nums){
        int maxi = INT_MIN;

        for(auto it : nums){
            maxi = max(maxi,it);
        }

        return maxi;

    }

    long long totalHours(vector<int>& piles,int speed){
        long long totalH = 0;

        for(auto bananas : piles){
            totalH += ceil((double)bananas/speed);
        }

        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int n = piles.size();

        int low = 1;  int high = maxElement(piles);

        int ans = high;

        while(low <= high)
        {
            int mid = low + (high - low)/2;

           long long totalH = totalHours(piles,mid);

            if(totalH <= h)
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